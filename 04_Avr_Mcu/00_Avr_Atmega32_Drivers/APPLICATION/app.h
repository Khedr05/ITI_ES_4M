/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 00_Gpio_Driver                                    	 
// File          : app.h                                  	     
// Date          : 31 Jul 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include "../HAL/lcd/lcd_interface.h"

#include "../HAL/pb/pb_interface.h"
#include "../HAL/led/led_interface.h"
#include "../MCAL/gi/gi_interface.h"
#include "../MCAL/exti/exti_interface.h"
#include "../MCAL/tmr/tmr_interface.h"
#include "../MCAL/uart/uart_interface.h"
#include "../MCAL/spi/spi_interface.h"
#include "../MCAL/twi/twi_interface.h"

void appInit(void);
void appMain(void);

#endif /* APPLICATION_APP_H_ */
