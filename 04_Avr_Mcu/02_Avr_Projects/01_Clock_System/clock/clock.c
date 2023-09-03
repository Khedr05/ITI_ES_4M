/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 17_Clock_System                                    	 
// File          : clock.c                                  	     
// Date          : 29 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/


#include "clock.h"

EN_CLOCK_systeamStates_t clockState = CLOCK_Entry_MODE;
uint8_t pressedKeyVal = '#';
vuint16_t tmrCounter = 0;

uint32_t hr = 0;
uint32_t min = 0;
uint32_t sec = 0;



void CLOCK_timerIsr(void)
{

	if(tmrCounter == 3906)
	{
		MTMR_writeTcntPreload(&myTmr,192);
		tmrCounter = 0;
		clockState = CLOCK_UPDATE_TIME_MODE;
	}
	else
	{
		tmrCounter++;
	}
}

void CLOCK_init(void)
{
	HLCD_init(&myLcd);
	HKP_init(&myKeypad);
	myTmr.MTMR_setCallbackForOvf = CLOCK_timerIsr;
	MTMR_init(&myTmr);
	MGI_vGIE();
}

void CLOCK_interface(void)
{

	while(1)
	{
		switch(clockState)
		{
			case CLOCK_SLEEP_MODE:
			{
				CLOCK_CheckForPause();
				break;
			}
			case CLOCK_Entry_MODE :
			{
				CLOCK_entryMode();
				break;
			}
			case CLOCK_SCANNING :
			{
				CLOCK_Scanning();
				break;
			}
			case CLOCK_ADJUST_MODE :
			{
				CLOCK_adjust();
				break;
			}
			case CLOCK_RUNNING_MODE :
			{
				CLOCK_running();
				break;
			}
			case CLOCK_UPDATE_TIME_MODE :
			{
				CLOCK_updateTime();
				break;
			}
			default :
			{
				break;
			}
		}
	}
}


void CLOCK_entryMode(void)
{
	HLCD_changeCursorPosation(&myLcd,0,0);
	HLCD_displayString(&myLcd,(uint8_t *)"A : Adjust Clock");
	HLCD_changeCursorPosation(&myLcd,1,0);
	HLCD_displayString(&myLcd,(uint8_t *)"R : Reset Clock");
	HLCD_Clr(&myLcd);
	HLCD_changeCursorPosation(&myLcd,0,0);
	HLCD_displayString(&myLcd,(uint8_t *)"G : Start Clock");
	HLCD_changeCursorPosation(&myLcd,1,0);
	HLCD_displayString(&myLcd,(uint8_t *)"P : Stop Clock");
	HLCD_Clr(&myLcd);
	CLOCK_UpdateLcd();
	clockState = CLOCK_SCANNING;
}


void CLOCK_Scanning(void)
{
	HKP_scanningForPressedBtn(&pressedKeyVal);
	if(pressedKeyVal == 'A')
	{
		pressedKeyVal = '#';
		MTMR_stop(&myTmr);
		HLCD_Clr(&myLcd);
		HLCD_changeCursorPosation(&myLcd,0,0);
		HLCD_displayString(&myLcd,(uint8_t *)"H : Edit Hours");
		HLCD_changeCursorPosation(&myLcd,1,0);
		HLCD_displayString(&myLcd,(uint8_t *)"M : Edit Minutes");
		HLCD_Clr(&myLcd);
		HLCD_changeCursorPosation(&myLcd,0,0);
		HLCD_displayString(&myLcd,(uint8_t *)"S : Edit Seconds");
		HLCD_changeCursorPosation(&myLcd,1,0);
		HLCD_displayString(&myLcd,(uint8_t *)"D : Done");
		HLCD_Clr(&myLcd);
		CLOCK_UpdateLcd();
		HLCD_changeCursorPosation(&myLcd,0,4);

		clockState = CLOCK_ADJUST_MODE;
	}
	else if(pressedKeyVal == 'R')
	{
		CLOCK_resetClock();
		pressedKeyVal = '#';
	}
	else if(pressedKeyVal == 'G')
	{
		CLOCK_startClock();
		pressedKeyVal = '#';
	}
	else if(pressedKeyVal == 'P')
	{
		pressedKeyVal = '#';
		HLCD_Clr(&myLcd);
		HLCD_changeCursorPosation(&myLcd,0,0);
		HLCD_displayString(&myLcd,(uint8_t *)"Clock Already");
		HLCD_changeCursorPosation(&myLcd,1,0);
		HLCD_displayString(&myLcd,(uint8_t *)"Stopped");
		clockState = CLOCK_Entry_MODE;
	}
	else if(pressedKeyVal != '#')
	{
		pressedKeyVal = '#';
		HLCD_Clr(&myLcd);
		HLCD_changeCursorPosation(&myLcd,0,0);
		HLCD_displayString(&myLcd,(uint8_t *)"Invalid Parameter");
		clockState = CLOCK_Entry_MODE;
	}
}


void CLOCK_adjust(void)
{
	HKP_scanningForPressedBtn(&pressedKeyVal);
	if(pressedKeyVal == 'H')
	{
		CLOCK_updateHr();
		pressedKeyVal = '#';
	}
	else if(pressedKeyVal == 'M')
	{
		CLOCK_updateMin();
		pressedKeyVal = '#';
	}
	else if(pressedKeyVal == 'S')
	{
		CLOCK_updateSec();
		pressedKeyVal = '#';
	}
	else if(pressedKeyVal == 'D')
	{
		HLCD_Clr(&myLcd);
		HLCD_changeCursorPosation(&myLcd,0,0);
		HLCD_displayString(&myLcd,(uint8_t *)"Adjusted Success");
		pressedKeyVal = '#';
		HLCD_Clr(&myLcd);
		CLOCK_startClock();
	}
	else
	{
		/* Do Nothing */
	}
}

void CLOCK_startClock(void)
{
	MTMR_start(&myTmr);
	MTMR_writeTcntPreload(&myTmr,192);
	clockState = CLOCK_RUNNING_MODE;
}

void CLOCK_running(void)
{
	CLOCK_UpdateLcd();
	clockState = CLOCK_SLEEP_MODE;
}

void CLOCK_updateTime(void)
{
	if(sec <= 59)
	{
		sec++;
	}
	else if(sec == 60)
	{
		sec = 0;
		if(min <= 59)
		{
			min++;
		}
		else if(min == 60)
		{
			min = 0;
			if(hr <= 23)
			{
				hr++;
			}
			else if(hr == 24)
			{
				hr = 0;
			}
			else
			{
				/* Do Nothing */
			}
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		/* Do Nothing */
	}

	clockState = CLOCK_RUNNING_MODE;
}

void CLOCK_updateHr(void)
{
	if( (hr >= 0) && (hr <= 8))
	{
		hr++;
		HLCD_changeCursorPosation(&myLcd,0,4);
		HLCD_displayNumber(&myLcd,0);
		HLCD_displayNumber(&myLcd,hr);
	}
	else if((hr >= 9) && (hr <= 23))
	{
		hr++;
		HLCD_changeCursorPosation(&myLcd,0,4);
		HLCD_displayNumber(&myLcd,hr);
	}
	else if(hr == 24)
	{
		hr = 0;
		HLCD_changeCursorPosation(&myLcd,0,4);
		HLCD_displayNumber(&myLcd,hr);
		HLCD_displayNumber(&myLcd,0);
	}
	else
	{
		/* Do Nothing */
	}
	clockState = CLOCK_ADJUST_MODE;
}

void CLOCK_updateMin(void)
{
	if( (min >= 0) && (min <= 8))
	{
		min++;
		HLCD_changeCursorPosation(&myLcd,0,7);
		HLCD_displayNumber(&myLcd,0);
		HLCD_displayNumber(&myLcd,min);
	}
	else if((min >= 9) && (min <= 59))
	{
		min++;
		HLCD_changeCursorPosation(&myLcd,0,7);
		HLCD_displayNumber(&myLcd,min);
	}
	else if(min == 60)
	{
		min = 0;
		HLCD_changeCursorPosation(&myLcd,0,7);
		HLCD_displayNumber(&myLcd,min);
		HLCD_displayNumber(&myLcd,0);
	}
	else
	{
		/* Do Nothing */
	}
	clockState = CLOCK_ADJUST_MODE;
}

void CLOCK_updateSec(void)
{
	if( (sec >= 0) && (sec <= 8))
	{
		sec++;
		HLCD_changeCursorPosation(&myLcd,0,10);
		HLCD_displayNumber(&myLcd,0);
		HLCD_displayNumber(&myLcd,sec);
	}
	else if((sec >= 9) && (sec <= 59))
	{
		sec++;
		HLCD_changeCursorPosation(&myLcd,0,10);
		HLCD_displayNumber(&myLcd,sec);
	}
	else if(sec == 60)
	{
		sec = 0;
		HLCD_changeCursorPosation(&myLcd,0,10);
		HLCD_displayNumber(&myLcd,sec);
		HLCD_displayNumber(&myLcd,0);
	}
	else
	{
		/* Do Nothing */
	}
	clockState = CLOCK_ADJUST_MODE;
}


void CLOCK_CheckForPause(void)
{
	HKP_scanningForPressedBtn(&pressedKeyVal);
	if(pressedKeyVal == 'P')
	{
		pressedKeyVal = '#';
		MTMR_stop(&myTmr);
		clockState = CLOCK_Entry_MODE;
	}
}

void CLOCK_UpdateLcd(void)
{
	if( (hr >= 0) && (hr <= 9))
	{
		HLCD_changeCursorPosation(&myLcd,0,4);
		HLCD_displayNumber(&myLcd,0);
		HLCD_displayNumber(&myLcd,hr);
	}
	else if((hr >= 10) && (hr <= 24))
	{
		HLCD_changeCursorPosation(&myLcd,0,4);
		HLCD_displayNumber(&myLcd,hr);
	}
	else if(hr > 24)
	{
		HLCD_changeCursorPosation(&myLcd,0,4);
		HLCD_displayNumber(&myLcd,hr);
		HLCD_displayNumber(&myLcd,0);
	}
	else
	{
		/* Do Nothing */
	}

	HLCD_displayChar(&myLcd,':');

	if( (min >= 0) && (min <= 9))
	{
		HLCD_changeCursorPosation(&myLcd,0,7);
		HLCD_displayNumber(&myLcd,0);
		HLCD_displayNumber(&myLcd,min);
	}
	else if((min >= 10) && (min <= 60))
	{
		HLCD_changeCursorPosation(&myLcd,0,7);
		HLCD_displayNumber(&myLcd,min);
	}
	else if(min > 60)
	{
		HLCD_changeCursorPosation(&myLcd,0,7);
		HLCD_displayNumber(&myLcd,min);
		HLCD_displayNumber(&myLcd,0);
	}
	else
	{
		/* Do Nothing */
	}

	HLCD_displayChar(&myLcd,':');

	if( (sec >= 0) && (sec <= 9))
	{
		HLCD_changeCursorPosation(&myLcd,0,10);
		HLCD_displayNumber(&myLcd,0);
		HLCD_displayNumber(&myLcd,sec);
	}
	else if((sec >= 10) && (sec <= 60))
	{
		HLCD_changeCursorPosation(&myLcd,0,10);
		HLCD_displayNumber(&myLcd,sec);
	}
	else if(sec > 60)
	{
		HLCD_changeCursorPosation(&myLcd,0,10);
		HLCD_displayNumber(&myLcd,sec);
		HLCD_displayNumber(&myLcd,0);
	}
	else
	{
		/* Do Nothing */
	}
}

void CLOCK_resetClock(void)
{
	hr = 0;
	min = 0;
	sec = 0;
	MTMR_stop(&myTmr);
	MTMR_writeTcntPreload(&myTmr,0);
	HLCD_Clr(&myLcd);
	HLCD_changeCursorPosation(&myLcd,0,0);
	HLCD_displayString(&myLcd, "Clock Reset");
	HLCD_changeCursorPosation(&myLcd,1,0);
	HLCD_displayString(&myLcd, "Success");
	clockState = CLOCK_Entry_MODE;
}
