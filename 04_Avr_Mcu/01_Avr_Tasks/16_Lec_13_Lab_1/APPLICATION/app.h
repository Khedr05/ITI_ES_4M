/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 18_Lec_13_Lab_1                                    	 
// File          : app.h                                  	     
// Date          : 2 Sept 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include "../COMMON/std_types.h"
#include "../HAL/led/led_interface.h"
#include "../MCAL/uart/uart_interface.h"

void initMain(void);
void appMain(void);

#endif /* APPLICATION_APP_H_ */
