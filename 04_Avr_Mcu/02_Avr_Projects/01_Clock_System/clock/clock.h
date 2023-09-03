/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 17_Clock_System                                    	 
// File          : clock..h                                  	     
// Date          : 29 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef CLOCK_CLOCK_H_
#define CLOCK_CLOCK_H_

#include <string.h>
#include <stdlib.h>
#include "../APPLICATION/device_cfg.h"


typedef enum
{
	CLOCK_Entry_MODE = 0,
	CLOCK_SCANNING,
	CLOCK_ADJUST_MODE,
	CLOCK_RUNNING_MODE,
	CLOCK_UPDATE_TIME_MODE,
	CLOCK_SLEEP_MODE

}EN_CLOCK_systeamStates_t;


void CLOCK_init(void);
void CLOCK_interface(void);

void CLOCK_entryMode(void);
void CLOCK_Scanning(void);
void CLOCK_adjust(void);
void CLOCK_running(void);


void CLOCK_updateHr(void);
void CLOCK_updateMin(void);
void CLOCK_updateSec(void);

void CLOCK_updateTime(void);
void CLOCK_UpdateLcd(void);

void CLOCK_timerIsr(void);

void CLOCK_CheckForPause(void);
void CLOCK_resetClock(void);
void CLOCK_startClock(void);


#endif /* CLOCK_CLOCK_H_ */
