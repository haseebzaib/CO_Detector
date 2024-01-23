/*
 * USB_driver.c
 *
 *  Created on: Jan 18, 2024
 *      Author: Admin
 */

/**
 * The downstream-facing port (DFP) sends data
downstream; it is typically the port on a host or a
hub to which devices connect. A DFP will source
VBUS power (the power path between host and
device) and can also source VCONN power (to
power electronically marked cables). An example of
an application that may include a DFP is a docking
station.

in our case if in DFP we will give the power. DFP is sourcing mode



• The upstream-facing port (UFP), which connects to
a host or DFP of a hub, receives the data on a device
or hub. These ports usually sink VBUS. An example
of an application that may include a UFP is a display
monitor

in UFP we will take power from connected device. UFP is sinking mode


 */


#include "USB_driver.h"
#include "main.h"

#define i2c_addr (0x60 << 1)



uint8_t usb_cabledetect_statedetect()
{
	uint8_t wr_addr[3] = {0x08,0x09,0x0A};
	  uint8_t cable_nd_state_detection[3];
	  uint8_t flag =2;

	 for(int i=0;i<3;i++)
		 {
			 HAL_I2C_Mem_Read(&hi2c2, 0x60<<1, wr_addr[i], 1, &cable_nd_state_detection[i], 1, 1000);
		 }


		if(cable_nd_state_detection[1] & 0x40)
		{
			  HAL_GPIO_WritePin(VBUS_OUT_EN_GPIO_Port, VBUS_OUT_EN_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(CHG_EN_GPIO_Port, CHG_EN_Pin, GPIO_PIN_SET);
			  flag =1;
		}
		else if(cable_nd_state_detection[1] & 0x80)
		{
			  HAL_GPIO_WritePin(VBUS_OUT_EN_GPIO_Port, VBUS_OUT_EN_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(CHG_EN_GPIO_Port, CHG_EN_Pin, GPIO_PIN_RESET);
			  flag = 0;
		}


return flag;

}

void usb_currentselector()
{

	uint8_t data = 0x40;
	 HAL_I2C_Mem_Write(&hi2c2, (0x60<<1), 0x08, 1, &data, 1, 1000);
}


/**
 * id
 * [0] : 0x30
 * [1] : 0x32
 * [2] : 0x33
 * [3] : 0x42
 * [4] : 0x53
 * [5] : 0x55
 * [6] : 0x54
 * [7] : 0x00
 */
void usb_deviceID(uint8_t *id)
{

uint8_t wr_addr[8] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07};

for(int i=0;i<8;i++)
{
	HAL_I2C_Mem_Read(&hi2c2, i2c_addr, wr_addr[i], 1, &id[i], 1, 1000);
}


}
