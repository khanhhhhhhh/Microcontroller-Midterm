/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"


#define RESTART			11
#define INC				12
#define DEC				13
#define INIT 			14

#define INC_LONG		15
#define DEC_LONG		16
#define NO_PRESSED		17

extern int status;
extern int status_1;
extern int status_2;
extern int counter_7led;

extern int press3s_button1;
extern int press3s_button2;
extern int press3s_button3;


#endif /* INC_GLOBAL_H_ */
