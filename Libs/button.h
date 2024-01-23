/*
 * button.h
 *
 *  Created on: Jan 12, 2024
 *      Author: Admin
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "main.h"


typedef enum {

	NPress = 0,
	SPress = 1,
	DPress = 2,

}bstatus;

extern uint8_t button_pressed;

extern void button_interrupt();
extern void button_query();

#endif /* BUTTON_H_ */
