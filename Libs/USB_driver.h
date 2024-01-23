/*
 * USB_driver.h
 *
 *  Created on: Jan 18, 2024
 *      Author: Admin
 */




#ifndef USB_DRIVER_H_
#define USB_DRIVER_H_


#include "main.h"



extern uint8_t usb_cabledetect_statedetect();
extern void usb_currentselector();
extern void usb_deviceID(uint8_t *id);


#endif /* USB_DRIVER_H_ */
