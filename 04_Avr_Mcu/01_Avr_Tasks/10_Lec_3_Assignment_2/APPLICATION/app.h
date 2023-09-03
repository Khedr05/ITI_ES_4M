/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 10_Lec_3_Assignment_2                                    	 
// File          : app.h                                  	     
// Date          : 23 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include "../HAL/lcd/lcd_interface.h"
#include <util/delay.h>

#define F_CPU	8000000UL

void appInit(void);

void appMain(void);

#endif /* APPLICATION_APP_H_ */
