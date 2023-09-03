/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 07_Lec_1_Assignment_1                                    	 
// File          : app.c                                  	     
// Date          : 11 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "app.h"

extern ST_LED_cfg_t greenLed;
extern ST_LED_cfg_t yellowLed;
extern ST_LED_cfg_t redLed;
extern ST_SSD_cfg_t ssdOne;
extern ST_SSD_cfg_t ssdTwo;


void appInit(void)
{
	LED_init(&greenLed);
	LED_init(&yellowLed);
	LED_init(&redLed);
	SSD_int(&ssdOne);
	SSD_int(&ssdTwo);
}

void appMain(void)
{
	uint8_t i;

	for(i=1 ; i<=10 ; i++)
	{
		LED_turnOn(&greenLed);
		LED_turnOff(&yellowLed);
		LED_turnOff(&redLed);

		if(i == 10)
		{
			SSD_setNumberOnSsd(&ssdOne,SSD_ONE);
			SSD_setNumberOnSsd(&ssdTwo,SSD_ZERO);
		}
		else
		{
			SSD_setNumberOnSsd(&ssdOne,SSD_ZERO);
			SSD_setNumberOnSsd(&ssdTwo,i);
		}
		_delay_ms(1000);
	}

	for(i=1 ; i<=3 ; i++)
	{
		LED_turnOn(&yellowLed);
		LED_turnOff(&greenLed);
		LED_turnOff(&redLed);

		if(i == 10)
		{
			SSD_setNumberOnSsd(&ssdOne,SSD_ONE);
			SSD_setNumberOnSsd(&ssdTwo,SSD_ZERO);
		}
		else
		{
			SSD_setNumberOnSsd(&ssdOne,SSD_ZERO);
			SSD_setNumberOnSsd(&ssdTwo,i);
		}
		_delay_ms(1000);
	}

	for(i=1 ; i<=10 ; i++)
	{
		LED_turnOn(&redLed);
		LED_turnOff(&greenLed);
		LED_turnOff(&yellowLed);

		if(i == 10)
		{
			SSD_setNumberOnSsd(&ssdOne,SSD_ONE);
			SSD_setNumberOnSsd(&ssdTwo,SSD_ZERO);
		}
		else
		{
			SSD_setNumberOnSsd(&ssdOne,SSD_ZERO);
			SSD_setNumberOnSsd(&ssdTwo,i);
		}
		_delay_ms(1000);
	}
}
