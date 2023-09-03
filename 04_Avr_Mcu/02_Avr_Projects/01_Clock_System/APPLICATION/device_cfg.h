/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 17_Clock_System                                    	 
// File          : device_cfg.h                                  	     
// Date          : 29 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef APPLICATION_DEVICE_CFG_H_
#define APPLICATION_DEVICE_CFG_H_

#include "../HAL/keypad/kp_interface.h"
#include "../HAL/lcd/lcd_interface.h"
#include "../MCAL/gi/gi_interface.h"
#include "../MCAL/tmr/tmr_interface.h"

extern ST_HLCD_cfg_t myLcd;
extern ST_HKP_cfg_t myKeypad;
extern ST_MTMR_cfg_t myTmr;

#endif /* APPLICATION_DEVICE_CFG_H_ */
