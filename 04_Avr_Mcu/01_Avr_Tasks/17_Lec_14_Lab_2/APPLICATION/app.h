/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 19_Lec_14_Lab_2                                    	 
// File          : app.h                                  	     
// Date          : 2 Sept 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include <util/delay.h>
#include "../COMMON/std_types.h"
#include "device_cfg.h"


void MASTER_appInit(void);
void MASTER_appMain(void);

void SLAVE_appInit(void);
void SLAVE_appMain(void);

#endif /* APPLICATION_APP_H_ */
