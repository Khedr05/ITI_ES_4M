/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 08_Lec_1_Assignment_2                                    	 
// File          : app.c                                  	     
// Date          : 11 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/


#include "app.h"


extern ST_LED_cfg_t ledOne;
extern ST_LED_cfg_t ledTwo;
extern ST_LED_cfg_t ledThree;
extern ST_LED_cfg_t ledFour;
extern ST_LED_cfg_t ledFive;
extern ST_LED_cfg_t ledSix;
extern ST_LED_cfg_t ledSeven;
extern ST_LED_cfg_t ledEight;
extern ST_EDIP_cfg_t dipSwitchOne;
extern ST_EDIP_cfg_t dipSwitchTwo;
extern ST_EDIP_cfg_t dipSwitchThree;
extern ST_EDIP_cfg_t dipSwitchFour;
extern ST_EDIP_cfg_t dipSwitchFive;
extern ST_EDIP_cfg_t dipSwitchSix;
extern ST_EDIP_cfg_t dipSwitchSeven;
extern ST_EDIP_cfg_t dipSwitchEight;


void appInit(void)
{
	LED_init(&ledOne);
	LED_init(&ledTwo);
	LED_init(&ledThree);
	LED_init(&ledFour);
	LED_init(&ledFive);
	LED_init(&ledSix);
	LED_init(&ledSeven);
	LED_init(&ledEight);
	EDIP_init(&dipSwitchOne);
	EDIP_init(&dipSwitchTwo);
	EDIP_init(&dipSwitchThree);
	EDIP_init(&dipSwitchFour);
	EDIP_init(&dipSwitchFive);
	EDIP_init(&dipSwitchSix);
	EDIP_init(&dipSwitchSeven);
	EDIP_init(&dipSwitchEight);
}

void appMain(void)
{
	EN_EDIP_logicStatus_t  dipSwitchState;
	EDIP_readStates(&dipSwitchOne,&dipSwitchState);

	if(dipSwitchState == EDIP_IS_ON)
	{
		flashingMode();
	}
	else
	{
		/*Do Nothing */
	}

	EDIP_readStates(&dipSwitchTwo,&dipSwitchState);

	if(dipSwitchState == EDIP_IS_ON)
	{
		shiftingLeftMode();
	}
	else
	{
		/*Do Nothing */
	}

	EDIP_readStates(&dipSwitchThree,&dipSwitchState);

	if(dipSwitchState == EDIP_IS_ON)
	{
		shiftingRightMode();
	}
	else
	{
		/*Do Nothing */
	}

	EDIP_readStates(&dipSwitchFour,&dipSwitchState);

	if(dipSwitchState == EDIP_IS_ON)
	{
		convergingMode();
	}
	else
	{
		/*Do Nothing */
	}

	EDIP_readStates(&dipSwitchFive,&dipSwitchState);

	if(dipSwitchState == EDIP_IS_ON)
	{
		divergingMode();
	}
	else
	{
		/*Do Nothing */
	}

	EDIP_readStates(&dipSwitchSix,&dipSwitchState);

	if(dipSwitchState == EDIP_IS_ON)
	{
		pingPongMode();
	}
	else
	{
		/*Do Nothing */
	}

	EDIP_readStates(&dipSwitchSeven,&dipSwitchState);

	if(dipSwitchState == EDIP_IS_ON)
	{
		incrementingMode();
	}
	else
	{
		/*Do Nothing */
	}

	EDIP_readStates(&dipSwitchEight,&dipSwitchState);

	if(dipSwitchState == EDIP_IS_ON)
	{
		convergingDivergingMode();
	}
	else
	{
		/*Do Nothing */
	}
}



void flashingMode(void)
{
	LED_turnOn(&ledOne);
	LED_turnOn(&ledTwo);
	LED_turnOn(&ledThree);
	LED_turnOn(&ledFour);
	LED_turnOn(&ledFive);
	LED_turnOn(&ledSix);
	LED_turnOn(&ledSeven);
	LED_turnOn(&ledEight);
	_delay_ms(500);
	LED_turnOff(&ledOne);
	LED_turnOff(&ledTwo);
	LED_turnOff(&ledThree);
	LED_turnOff(&ledFour);
	LED_turnOff(&ledFive);
	LED_turnOff(&ledSix);
	LED_turnOff(&ledSeven);
	LED_turnOff(&ledEight);
	_delay_ms(500);

}

void shiftingLeftMode(void)
{
	LED_turnOn(&ledOne);
	_delay_ms(250);
	LED_turnOff(&ledOne);
	LED_turnOn(&ledTwo);
	_delay_ms(250);
	LED_turnOff(&ledTwo);
	LED_turnOn(&ledThree);
	_delay_ms(250);
	LED_turnOff(&ledThree);
	LED_turnOn(&ledFour);
	_delay_ms(250);
	LED_turnOff(&ledFour);
	LED_turnOn(&ledFive);
	_delay_ms(250);
	LED_turnOff(&ledFive);
	LED_turnOn(&ledSix);
	_delay_ms(250);
	LED_turnOff(&ledSix);
	LED_turnOn(&ledSeven);
	_delay_ms(250);
	LED_turnOff(&ledSeven);
	LED_turnOn(&ledEight);
	_delay_ms(250);
	LED_turnOff(&ledEight);
}

void shiftingRightMode(void)
{
	LED_turnOn(&ledEight);
	_delay_ms(250);
	LED_turnOff(&ledEight);
	LED_turnOn(&ledSeven);
	_delay_ms(250);
	LED_turnOff(&ledSeven);
	LED_turnOn(&ledSix);
	_delay_ms(250);
	LED_turnOff(&ledSix);
	LED_turnOn(&ledFive);
	_delay_ms(250);
	LED_turnOff(&ledFive);
	LED_turnOn(&ledFour);
	_delay_ms(250);
	LED_turnOff(&ledFour);
	LED_turnOn(&ledThree);
	_delay_ms(250);
	LED_turnOff(&ledThree);
	LED_turnOn(&ledTwo);
	_delay_ms(250);
	LED_turnOff(&ledTwo);
	LED_turnOn(&ledOne);
	_delay_ms(250);
	LED_turnOff(&ledOne);
}

void convergingMode(void)
{
	LED_turnOn(&ledOne);
	LED_turnOn(&ledEight);
	_delay_ms(300);
	LED_turnOff(&ledOne);
	LED_turnOff(&ledEight);
	LED_turnOn(&ledTwo);
	LED_turnOn(&ledSeven);
	_delay_ms(300);
	LED_turnOff(&ledTwo);
	LED_turnOff(&ledSeven);
	LED_turnOn(&ledThree);
	LED_turnOn(&ledSix);
	_delay_ms(300);
	LED_turnOff(&ledThree);
	LED_turnOff(&ledSix);
	LED_turnOn(&ledFour);
	LED_turnOn(&ledFive);
	_delay_ms(300);
	LED_turnOff(&ledFour);
	LED_turnOff(&ledFive);
}

void divergingMode(void)
{
	LED_turnOn(&ledFour);
	LED_turnOn(&ledFive);
	_delay_ms(300);
	LED_turnOff(&ledFour);
	LED_turnOff(&ledFive);
	LED_turnOn(&ledThree);
	LED_turnOn(&ledSix);
	_delay_ms(300);
	LED_turnOff(&ledThree);
	LED_turnOff(&ledSix);
	LED_turnOn(&ledTwo);
	LED_turnOn(&ledSeven);
	_delay_ms(300);
	LED_turnOff(&ledTwo);
	LED_turnOff(&ledSeven);
	LED_turnOn(&ledOne);
	LED_turnOn(&ledEight);
	_delay_ms(300);
	LED_turnOff(&ledOne);
	LED_turnOff(&ledEight);
}

void pingPongMode(void)
{
	shiftingLeftMode();
	_delay_ms(250);
	shiftingRightMode();
}

void incrementingMode(void)
{
	LED_turnOn(&ledOne);
	_delay_ms(300);
	LED_turnOn(&ledTwo);
	_delay_ms(300);
	LED_turnOn(&ledThree);
	_delay_ms(300);
	LED_turnOn(&ledFour);
	_delay_ms(300);
	LED_turnOn(&ledFive);
	_delay_ms(300);
	LED_turnOn(&ledSix);
	_delay_ms(300);
	LED_turnOn(&ledSeven);
	_delay_ms(300);
	LED_turnOn(&ledEight);
	_delay_ms(300);
	LED_turnOff(&ledOne);
	LED_turnOff(&ledTwo);
	LED_turnOff(&ledThree);
	LED_turnOff(&ledFour);
	LED_turnOff(&ledFive);
	LED_turnOff(&ledSix);
	LED_turnOff(&ledSeven);
	LED_turnOff(&ledEight);
}

void convergingDivergingMode(void)
{
	convergingMode();
	_delay_ms(300);
	divergingMode();
}







