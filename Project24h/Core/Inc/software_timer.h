/*
 * software_timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;


void setTimer1(int duration);
void timerRun1();

void setTimer2(int duration);
void timerRun2();

void setTimer3(int duration);
void timerRun3();

#endif /* INC_SOFTWARE_TIMER_H_ */
