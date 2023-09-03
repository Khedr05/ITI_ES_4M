/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 08_Lec_1_Assignment_2                                    	 
// File          : app.h                                  	     
// Date          : 11 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include <util/delay.h>
#include "../COMMON/std_types.h"
#include "../ECUAL/led/led_interface.h"
#include "../ECUAL/dip/dip_interface.h"


void appInit(void);
void appMain(void);


void flashingMode(void);
void shiftingLeftMode(void);
void shiftingRightMode(void);
void convergingMode(void);
void divergingMode(void);
void pingPongMode(void);
void incrementingMode(void);
void convergingDivergingMode(void);

#endif /* APPLICATION_APP_H_ */
