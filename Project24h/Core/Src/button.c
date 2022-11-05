/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */


#include "button.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int KeyReg4 = NORMAL_STATE;
int KeyReg5 = NORMAL_STATE;
int KeyReg6 = NORMAL_STATE;
int KeyReg7 = NORMAL_STATE;

int KeyReg8 = NORMAL_STATE;
int KeyReg9 = NORMAL_STATE;
int KeyReg10 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;

int TimeOutForKeyPress =  300;
int check_press_button2 = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed_3s(){
	return check_press_button2;
}
int isButton3Pressed_3s();
// action to be done after button press
void subKeyProcess_button1(){
	//TODO
	//HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	button1_flag = 1;
}
void subKeyProcess_button2(){
	button2_flag = 1;
}
void subKeyProcess_button3(){
	button3_flag = 1;
}
// getKetInput: detect button pressed and execute subkeyprocess

void getKeyInput_button1(){
	  KeyReg0 = KeyReg1;
	  KeyReg1 = KeyReg2;
	  KeyReg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	  if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
	    if (KeyReg3 != KeyReg2){
	      KeyReg3 = KeyReg2;

	    if (KeyReg2 == PRESSED_STATE){
		    subKeyProcess_button1();
	        TimeOutForKeyPress = 300;
	      }
	    }else{
	       TimeOutForKeyPress --;
	        if (TimeOutForKeyPress == 0){
//	        	KeyReg3 = NORMAL_STATE;

	        	if(KeyReg2 == PRESSED_STATE){
			        subKeyProcess_button1();


	        	}

	        	TimeOutForKeyPress = 300;

	        }

	    }
	  }

}

void getKeyInput_button2(){
	  KeyReg4 = KeyReg5;
	  KeyReg5 = KeyReg6;
	  KeyReg6 = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
	  if ((KeyReg4 == KeyReg5) && (KeyReg5 == KeyReg6)){
	    if (KeyReg7 != KeyReg6){
	      KeyReg7 = KeyReg6;

	      if (KeyReg6 == PRESSED_STATE){
		    subKeyProcess_button2();
	        TimeOutForKeyPress = 300;
	      }
//	      else{
//	    	  button2_flag = 0;
//	    	  press3s_button2 = 0;
//	    	  check_press_button2 = 1;
//	      }
	    }

	    else{

	    		TimeOutForKeyPress --;

				if (TimeOutForKeyPress == 0){
					// TO DO

		        	if(KeyReg6 == PRESSED_STATE){
				        subKeyProcess_button2();


		        	}
					TimeOutForKeyPress = 300;

				}


	    }
	  }
}

void getKeyInput_button3(){
	  KeyReg8 = KeyReg9;
	  KeyReg9 = KeyReg10;
	  KeyReg10 = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
	  if ((KeyReg8 == KeyReg9) && (KeyReg9 == KeyReg10)){
	    if (KeyReg11 != KeyReg10){
	      KeyReg11 = KeyReg10;

	      if (KeyReg10 == PRESSED_STATE){
		    subKeyProcess_button3();
	        TimeOutForKeyPress = 300;

	      }
	    }else{
	       TimeOutForKeyPress --;
	        if (TimeOutForKeyPress == 0){
	        	//TO DO

	        	if(KeyReg10 == PRESSED_STATE){
			        subKeyProcess_button3();

	        	}

	        	TimeOutForKeyPress = 300;

	        }

	    }
	  }
}
