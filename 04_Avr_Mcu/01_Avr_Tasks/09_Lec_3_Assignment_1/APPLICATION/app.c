/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 09_Lec_3_Assignment_1                                    	 
// File          : app.c                                  	     
// Date          : 23 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/


#include "app.h"


ST_HLCD_cfg_t  lcd0 =
{
		.dataPinsMode = HLCD_8_BIT_MODE,
		.dataPort = GPIO_PORTA,
		.controlPort = GPIO_PORTC,
		.rsPin = GPIO_PIN0,
		.rwPin = GPIO_PIN1,
		.enPin = GPIO_PIN2,
		.d0Pin = GPIO_PIN0,
		.d1Pin = GPIO_PIN1,
		.d2Pin = GPIO_PIN2,
		.d3Pin = GPIO_PIN3,
		.d4Pin = GPIO_PIN4,
		.d5Pin = GPIO_PIN5,
		.d6Pin = GPIO_PIN6,
		.d7Pin = GPIO_PIN7
};



void appInit(void)
{
	HLCD_init(&lcd0);
}

void appMain(void)
{
	while(1)
	{
		HLCD_changeCursorPosation(&lcd0,0,0);
		HLCD_displayString(&lcd0,(uint8_t *)"sherif");
		_delay_ms(500);
		HLCD_Clr(&lcd0);
		HLCD_changeCursorPosation(&lcd0,1,6);
		HLCD_displayString(&lcd0,(uint8_t *)"sherif");
		_delay_ms(500);
		HLCD_Clr(&lcd0);
		HLCD_changeCursorPosation(&lcd0,0,10);
		HLCD_displayString(&lcd0,(uint8_t *)"sherif");
		_delay_ms(500);
		HLCD_Clr(&lcd0);

	}
}
