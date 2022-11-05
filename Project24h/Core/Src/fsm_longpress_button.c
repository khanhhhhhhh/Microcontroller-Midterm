/*
 * fsm_longpress_button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#include "fsm_longpress_button.h"

void fsm_longpress_button_run(){
	switch(status){

	case INC_LONG:

		LED_7SEG(counter_7led);
		if(isButton2Pressed()==1){
			if(timer2_flag == 1){
				counter_7led++;
				if(counter_7led > 9){
					counter_7led = 0;
				}

				status = INC_LONG;
				setTimer2(100);
			}
		}
		if(isButton2Pressed()==0){
			status = INC;
		}

		break;

	case DEC_LONG:

		break;

	default:
		break;

	}
}
