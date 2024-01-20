/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 01_String_On_LedMatrix                                    	 
// File          : app.h                                  	     
// Date          : Sep 16, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include "../MCAL/rcc/rcc_interface.h"
#include "../MCAL/systick/systick_interface.h"
#include "../HAL/ledMatrix/ledMatrix_interface.h"

void appInit(void);
void appMain(void);

#endif /* APPLICATION_APP_H_ */
