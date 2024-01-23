/*
 * button.c
 *
 *  Created on: Jan 12, 2024
 *      Author: Admin
 */


#include "main.h"
#include "button.h"

uint8_t button_pressed = 0;
typedef enum
{
	MenuButtonStatus_oneClick = 0,
	MenuButtonStatus_doubleClick,
	MenuButtonStatus_heldPressed,
	MenuButtonStatus_notPressed
}MenuButtonStatus_e;


typedef struct
{
	 uint32_t 			buttonTimer;
     uint8_t 		    buttonTimerEnable;
	MenuButtonStatus_e	buttonStatus;
	__IO uint8_t 			buttonFlag;
	uint8_t 			buttonHeldPressedCounter;
}MenuButton_t;

MenuButton_t hMenuButton;


__IO uint8_t ticks = 0;


/*Local functions*/


static void setTimer(uint32_t* timer)
{
	*timer = HAL_GetTick();
}
static uint8_t checkTimer(uint32_t* timer, uint32_t msTime)
{
	uint8_t ret = RESET;
	ret = ((HAL_GetTick() - *timer) > msTime)  ? ENABLE : DISABLE;
	return ret;
}


/*GLOBAL functions*/

/**
 * this routine is kept in systick handler interupt
 * this will employ button query to check buttons
 * systick occurs every 1ms but we check button every 50ms which makes auto debouncing routine
 */
void button_interrupt()
{
	ticks++;
	if(ticks>50)
	{
		ticks =0; //reset the ticks
		button_query();
	}
}

/**
 * Checks for button press and long press
 * also debounces the button
 */
 void button_query()
 {
		if(hMenuButton.buttonFlag)
				     {
					         if(HAL_GPIO_ReadPin(PWN_BTN_MCU_GPIO_Port, PWN_BTN_MCU_Pin))											//for applying debounce
							  {
								  hMenuButton.buttonFlag = RESET;						//Reset interrupt flag

								  if(hMenuButton.buttonTimerEnable != SET)						//Start timer when the menu button gets pressed for the first time
								  {
									  hMenuButton.buttonTimerEnable = SET;						//Enable software timer
									  hMenuButton.buttonStatus = MenuButtonStatus_oneClick;		//The menu button has been pressed for one time
									  setTimer(&hMenuButton.buttonTimer);						//Start software timer
								  }
								  else
								  {
									// hMenuButton.buttonStatus = MenuButtonStatus_doubleClick;	//If the timer is already started this means that the button is pressed for the second time
								  }
							  }
						  }


					  if((hMenuButton.buttonStatus == MenuButtonStatus_oneClick) || hMenuButton.buttonStatus == MenuButtonStatus_heldPressed )//(checkTimer(&hMenuButton.buttonTimer, 5 * hMenuButton.buttonHeldPressedCounter)) &&
						  {
							  if(HAL_GPIO_ReadPin(PWN_BTN_MCU_GPIO_Port, PWN_BTN_MCU_Pin))		//To check if the button is still pressed
							  {
								  ++hMenuButton.buttonHeldPressedCounter;						//Increment samples number
							  }


							 if(hMenuButton.buttonHeldPressedCounter >= 60)
							 {
								  hMenuButton.buttonStatus = MenuButtonStatus_heldPressed;
							 }

						  }																		//If the button is held pressed change button status


					  //this if statement can be removed if double press feature is not being used.
					  if( (checkTimer(&hMenuButton.buttonTimer, 200)) && hMenuButton.buttonTimerEnable)//(checkTimer(&hMenuButton.buttonTimer, 40)) &&
						  {
			              if((HAL_GPIO_ReadPin(PWN_BTN_MCU_GPIO_Port, PWN_BTN_MCU_Pin)) && (hMenuButton.buttonHeldPressedCounter >= 60) )
						     {
							  switch(hMenuButton.buttonStatus)
							 	{
							 		case MenuButtonStatus_heldPressed:
							 		{
							 			button_pressed = DPress;
							 			 hMenuButton.buttonHeldPressedCounter 	= RESET;					//Reset counter
							 			 break;
							 		}
							 		default:
							 			break;
							 	 }


						     }


						  if(!HAL_GPIO_ReadPin(PWN_BTN_MCU_GPIO_Port, PWN_BTN_MCU_Pin))
						  {
							  switch(hMenuButton.buttonStatus)
							 	 {
							 			  	  case	MenuButtonStatus_oneClick:
							 			  	  {
							 			  		button_pressed = SPress;
							 			  		 break;
							 			  	  }

							 			  	  case 	MenuButtonStatus_doubleClick:
							 			  	  {
							 			  		 break;
							 			  	  }
							 			  	  default:
							 			  		  break;

							 		}
							              hMenuButton.buttonFlag = SET;
							 			  hMenuButton.buttonTimerEnable 		= RESET;					//Disable software timer
							 			  hMenuButton.buttonHeldPressedCounter 	= RESET;					//Reset counter
							 			  hMenuButton.buttonStatus 				= MenuButtonStatus_notPressed;

						  }



						  }





					  if(!HAL_GPIO_ReadPin(PWN_BTN_MCU_GPIO_Port, PWN_BTN_MCU_Pin) && !hMenuButton.buttonTimerEnable )//resets everything when button is unpressed
					  {

						  hMenuButton.buttonFlag = SET;
						  hMenuButton.buttonTimerEnable 		= RESET;					//Disable software timer
							hMenuButton.buttonHeldPressedCounter 	= RESET;					//Reset counter
							 hMenuButton.buttonStatus 				= MenuButtonStatus_notPressed;
					  }
 }
