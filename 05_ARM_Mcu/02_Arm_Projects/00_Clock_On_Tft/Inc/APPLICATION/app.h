/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC_Drivers                                    	 
// File          : app.h                                  	     
// Date          : Sep 8, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include "../Inc/MCAL/rcc/rcc_interface.h"
#include "../Inc/HAL/tft/tft_interface.h"
#include "../Inc/MCAL/systick/systick_interface.h"


void appInit(void);
void appMain(void);
void clockLogic(void);
void clockDisplayTime(void);
void clockDisplayDay(void);

#endif /* APPLICATION_APP_H_ */
