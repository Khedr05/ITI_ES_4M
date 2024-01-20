/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 04_Ldm_With_Stp                                    	 
// File          : app.h                                  	     
// Date          : Sep 28, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include "../MCAL/rcc/rcc_interface.h"
#include "../HAL/ledMatrix/ledMatrix_interface.h"
#include "../HAL/ir/ir_interface.h"


void appInit(void);
void appMain(void);


#endif /* APPLICATION_APP_H_ */
