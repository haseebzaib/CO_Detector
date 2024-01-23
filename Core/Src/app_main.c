/*
 * app_main.c
 *
 *  Created on: Jan 11, 2024
 *      Author: Admin
 */


#include "buzzer.h"
#include "internal_adc.h"
#include "stdio.h"
#include "string.h"
#include "AHT20.h"
#include "stdlib.h"
#include "lcd.h"
#include "button.h"
#include "USB_driver.h"

/*Function Prototypes*/
static void display_routine(char *buffer,uint32_t temp,uint32_t humid,uint16_t ppm,uint16_t percentage);
static void button_press_routine();
static void rtc_set_alarm();
static void prev_ppm_(uint16_t lower_limit,uint16_t upper_limit );
static void ppm_level_routine();


/*Defines*/
#define Brightness_100	65535
#define Brightness_75	49151
#define Brightness_50	32767
#define Brightness_25	16383
#define RTC_Handle &hrtc

/*Variables*/
__IO uint8_t CO_buf[10];
__IO uint16_t ppm;
uint16_t prev_ppm =0;
__IO uint8_t set_alarmA_Time;
uint16_t time_interval =10;
uint8_t rtcA_off =0;
uint8_t switch_alarmA_hour_min =1; //1=hour , 2=min
uint8_t set_alarm =1;
uint8_t usb_dt;
uint8_t detection;


/**
 * main application
 */
void app_main()
{
	set_alarmA_Time = 0;
	uint32_t Temperature, Humidity;
	float battery_voltage;
	 uint16_t percentage;
	char buffer[100];
	 BUZZER_Init();
	 AHT20_Init(&hi2c2);
	 HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	  TIM3->CCR3 = Brightness_100;
	 HAL_UART_Receive_DMA(&huart1, (uint8_t *)CO_buf, 9);

	  LCD_init();

	  uint8_t val[8] ={0};
       usb_deviceID(val);
       usb_currentselector();

	  while(1)
	  {



		  detection = usb_cabledetect_statedetect();



//		   HAL_IWDG_Refresh(&hiwdg);
			IWDG->KR = 0x0000AAAA;
			RTC_TimeTypeDef gTime;
			HAL_RTC_GetTime(RTC_Handle, &gTime, RTC_FORMAT_BIN);
			RTC_DateTypeDef sDate;
		    HAL_RTC_GetDate(RTC_Handle, &sDate, RTC_FORMAT_BIN);
	//	  AHT20_Measure();
		  Temperature = AHT20_Temp();
		  Humidity = AHT20_Humid();
		  adc_Measure(&battery_voltage);
		  percentage= (battery_voltage/3.9)*100;
		  if(percentage>=100) percentage = 100;


		 display_routine(buffer,Temperature,Humidity,ppm,percentage);
	//	  button_press_routine();
		//  rtc_set_alarm();
	//      ppm_level_routine();
	  }

}


/*Static functions*/
static void display_routine(char *buffer,uint32_t temp,uint32_t humid,uint16_t ppm,uint16_t percentage)
{

char bufppm[20];

	UG_SetBackcolor(C_BLACK);
			UG_SetForecolor(C_WHITE);
			UG_FontSelect(FONT_12X20);

			sprintf(buffer,"Temp: %ldC   ",temp );
			UG_PutString(20, 20, buffer);

			sprintf(buffer,"Humid: %ld%%    ",humid );
					UG_PutString(20, 60, buffer);

					sprintf(buffer,"PPM: %d   ",ppm );
									UG_PutString(20, 100, buffer);


									sprintf(buffer,"Battery: %d%%   ",percentage );
																UG_PutString(20, 140, buffer);





			if(detection == 1)
			{
				sprintf(buffer,"%s",  "Charging ext-dev      " );
			}
			else if(detection == 2)
			{
				sprintf(buffer,"%s",  "NONE                  " );
			}
			else
			{
				sprintf(buffer,"%s", "Charging Battery         " );
			}


			UG_PutString(20, 200, buffer);



//	if(button_pressed == 1)
//	{
//		//button_pressed =0;
//		UG_PutString(20, 50, "single press");
//
//	}
//	if(button_pressed == 2)
//	{
//		//button_pressed =0;
//		UG_PutString(20, 50, "long press   ");
//
//
//
//	}
//
//	if(set_alarmA_Time)
//	{
//		UG_PutString(20, 100, "RTC interrupt detected");
//
//		HAL_Delay(2000);
//	}
//	else
//	{
//		UG_PutString(20, 100, "                               ");
//	}


	  UG_Update();

}

static void button_press_routine()
{
	if(button_pressed == SPress)
	{
		button_pressed =NPress;
		 TIM3->CCR3 = Brightness_100;
	}
	if(button_pressed == DPress)
	{
		 TIM3->CCR3 = 0;
		button_pressed =NPress;
		  BUZZER_Go(TBUZ_100, TICK_2);
		  HAL_Delay(120);
		  BUZZER_Off();

	}
}

static void rtc_set_alarm()
{

if(switch_alarmA_hour_min == 2) //if it is on min
{
	uint16_t minuteA;

	if(set_alarmA_Time)
	{
		RTC_TimeTypeDef gTime;
		HAL_RTC_GetTime(RTC_Handle, &gTime, RTC_FORMAT_BIN);
		RTC_DateTypeDef sDate;
	    HAL_RTC_GetDate(RTC_Handle, &sDate, RTC_FORMAT_BIN);


	    minuteA = gTime.Minutes + time_interval;

	    if(minuteA > 59)
	    {
	    	minuteA = minuteA%time_interval;
	    	if(minuteA == 0)
	    	{
	    		minuteA = time_interval;
	    	}
	    }
	      RTC_AlarmTypeDef sAlarm = {0};
		  sAlarm.AlarmTime.Hours = 0;
		  sAlarm.AlarmTime.Minutes = minuteA;
		  sAlarm.AlarmTime.Seconds = 0;
		  sAlarm.AlarmTime.SubSeconds = 0;
		  sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
		  sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
		  sAlarm.AlarmMask = RTC_ALARMMASK_SECONDS| RTC_ALARMMASK_HOURS | RTC_ALARMMASK_DATEWEEKDAY;
		  sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
		  sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
		  sAlarm.AlarmDateWeekDay = 1;
		  sAlarm.Alarm = RTC_ALARM_A;
		  if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK)
		  {
		    Error_Handler();
		  }

		  __HAL_RTC_ALARM_ENABLE_IT (&hrtc, RTC_IT_ALRA);
		  __HAL_RTC_ALARM_CLEAR_FLAG (&hrtc, RTC_IT_ALRA);


		  set_alarmA_Time = 0;
	}
}
else if(switch_alarmA_hour_min == 1)
{
	uint16_t hourA;

	if(set_alarmA_Time)
	{
		RTC_TimeTypeDef gTime;
		HAL_RTC_GetTime(RTC_Handle, &gTime, RTC_FORMAT_BIN);
		RTC_DateTypeDef sDate;
	    HAL_RTC_GetDate(RTC_Handle, &sDate, RTC_FORMAT_BIN);


	    hourA = gTime.Hours + time_interval;

	    if(hourA > 12)
	    {
	    	hourA = hourA%time_interval;
	    	if(hourA == 0)
	    	{
	    		hourA = time_interval;
	    	}
	    }
	      RTC_AlarmTypeDef sAlarm = {0};
		  sAlarm.AlarmTime.Hours = hourA;
		  sAlarm.AlarmTime.Minutes = 0;
		  sAlarm.AlarmTime.Seconds = 0;
		  sAlarm.AlarmTime.SubSeconds = 0;
		  sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
		  sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
		  sAlarm.AlarmMask = RTC_ALARMMASK_SECONDS| RTC_ALARMMASK_MINUTES | RTC_ALARMMASK_DATEWEEKDAY;
		  sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
		  sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
		  sAlarm.AlarmDateWeekDay = 1;
		  sAlarm.Alarm = RTC_ALARM_A;
		  if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK)
		  {
		    Error_Handler();
		  }

		  __HAL_RTC_ALARM_ENABLE_IT (&hrtc, RTC_IT_ALRA);
		  __HAL_RTC_ALARM_CLEAR_FLAG (&hrtc, RTC_IT_ALRA);


		  set_alarmA_Time = 0;
	}
}

}

static void prev_ppm_(uint16_t lower_limit,uint16_t upper_limit )
{

	if(prev_ppm < lower_limit || prev_ppm >=upper_limit)
	{
		set_alarm =0;
		  BUZZER_Off();
	}

}

static void ppm_level_routine()
{
//use 12hour format for use of ease
	if(ppm >= 30 && ppm < 70)
	{

		switch_alarmA_hour_min = 1;
		time_interval = 8; //8hours

		//when it goes inside this routine it also sets time interval here as well for rtc but make a condition such tht it does not keep setting it

		if(!set_alarm)
		{
			set_alarmA_Time = 1;
			rtc_set_alarm();
			set_alarm = 1;
		}

		prev_ppm_(30,70);
		prev_ppm = ppm;
	}
	else if(ppm >= 70 && ppm < 150)
	{
		switch_alarmA_hour_min = 1;
      time_interval = 1; //1hour
		if(!set_alarm)
		{
			set_alarmA_Time = 1;
			rtc_set_alarm();
			set_alarm = 1;
		}

		prev_ppm_(70,150);
		prev_ppm = ppm;
	}
	else if(ppm >= 150 && ppm < 400)
	{
		switch_alarmA_hour_min = 2;
		time_interval = 11; //11 minutes
		if(!set_alarm)
		{
			set_alarmA_Time = 1;
			rtc_set_alarm();
			set_alarm = 1;
		}

		prev_ppm_(150,400);
		prev_ppm = ppm;
	}
	else if(ppm>= 400)
	{
		switch_alarmA_hour_min = 2;
		time_interval = 5; //5 minutes
		if(!set_alarm)
		{
			set_alarmA_Time = 1;
			rtc_set_alarm();
			set_alarm = 1;
		}

		if(prev_ppm < 400 )
		{
			set_alarm =0;
			  BUZZER_Off();
		}

		prev_ppm = ppm;
	}
	else
	{

		//if(!set_alarm)
		//{

		set_alarmA_Time = 0;
		 __HAL_RTC_ALARM_DISABLE_IT(&hrtc,RTC_IT_ALRA);
		 __HAL_RTC_ALARMA_DISABLE(&hrtc);
		//}

		  BUZZER_Off();
	    prev_ppm = ppm;

	}


}

/*Interrupts*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	ppm = CO_buf[4]<<8 | CO_buf[5];
	 HAL_UART_Receive_DMA(&huart1, (uint8_t *)CO_buf, 9);
}

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
{
	set_alarmA_Time = 1;
	set_alarm = 0;
	  BUZZER_Go(TBUZ_100, TICK_2);
}

void HAL_RTC_AlarmBEventCallback(RTC_HandleTypeDef *hrtc)
{

}

