/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 16_Lec_8_Lab_3
// File          : app.h                                  	     
// Date          : 24 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include "../HAL/lcd/lcd_interface.h"
#include "../HAL/led/led_interface.h"
#include "../MCAL/adc/adc_interface.h"


void appInit(void);
void appMain(void);

#endif /* APPLICATION_APP_H_ */
