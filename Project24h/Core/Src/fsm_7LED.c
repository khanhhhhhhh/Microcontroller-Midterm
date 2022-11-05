/*
 * fsm_7LED.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#include "fsm_7LED.h"

void fsm_simple_buttons_run (){
	switch(status){
	case INIT:

		LED_7SEG(0);
		counter_7led = 0;
		status = RESTART;
		setTimer2(1000);
		break;

	case RESTART:
		LED_7SEG(counter_7led);

		if(isButton1Pressed() == 1){
			counter_7led = 0;
			setTimer2(1000);
			status = RESTART;
		}
		if(isButton2Pressed() == 1){
			counter_7led = counter_7led + 1;
			if(counter_7led > 9){
				counter_7led = 0;
			}
			setTimer2(1000);
			status = INC;
		}
		if(isButton3Pressed() == 1){
			counter_7led = counter_7led - 1;
			if(counter_7led < 0){
				counter_7led = 9;
			}
			setTimer2(1000);
			status = DEC;
		}



		break;

	case INC:
		LED_7SEG(counter_7led);

		if(isButton1Pressed() == 1){
			counter_7led = 0;
			setTimer2(1000);
			status = RESTART;
		}
		else if(isButton2Pressed() == 1){

				counter_7led = counter_7led + 1;
				if(counter_7led > 9){
					counter_7led = 0;
				}
				setTimer2(1000);
				status = INC;

		}


		else if(isButton3Pressed() == 1){
			counter_7led = counter_7led - 1;
			if(counter_7led < 0){
				counter_7led = 9;
			}
			setTimer2(1000);
			status = DEC;
		}
		else{

			if(timer2_flag==1){
				setTimer3(100);
			status = NO_PRESSED;
			}
		}

		break;

	case DEC:
		LED_7SEG(counter_7led);

		if(isButton1Pressed() == 1){
			counter_7led = 0;
			setTimer2(1000);
			status = RESTART;
		}
		else if(isButton2Pressed() == 1){
			counter_7led = counter_7led + 1;
			if(counter_7led > 9){
				counter_7led = 0;
			}
			setTimer2(1000);
			status = INC;
		}
		else if(isButton3Pressed() == 1){
			counter_7led = counter_7led - 1;
			if(counter_7led < 0){
				counter_7led = 9;
			}
			setTimer2(1000);
			status = DEC;
		}
		else{

			if(timer2_flag==1){
				setTimer3(100);
				status = NO_PRESSED;
			}
		}
		break;
	case NO_PRESSED:
		if(timer3_flag==1){
			if(counter_7led >= 0){
				counter_7led--;

					LED_7SEG(counter_7led);
					setTimer3(100);

			}

		}
		if(isButton2Pressed()==1){
			setTimer2(1000);
			status = INC;
		}
		if(isButton3Pressed()==1){
			setTimer2(1000);
			status = DEC;
		}



		break;

	default:
		break;


	}
}
