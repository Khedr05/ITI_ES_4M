/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 10_Lec_3_Assignment_2                                    	 
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

uint8_t customChar0[8] = {
  0x00,
  0x04,
  0x0A,
  0x15,
  0x1F,
  0x00,
  0x00,
  0x00
};

uint8_t customChar1[8] = {
 0x00,
 0x00,
 0x00,
 0x00,
 0x03,
 0x04,
 0x18,
 0x00
};

uint8_t customChar2[8] = {
 0x00,
 0x00,
 0x00,
 0x01,
 0x1F,
 0x00,
 0x06,
 0x00
};

uint8_t customChar3[8] = {
 0x02,
 0x00,
 0x17,
 0x15,
 0x1F,
 0x00,
 0x00,
 0x00
};



void appInit(void)
{
	HLCD_init(&lcd0);
	HLCD_createNewCustomChar(&lcd0,customChar0,0);
	HLCD_createNewCustomChar(&lcd0,customChar1,1);
	HLCD_createNewCustomChar(&lcd0,customChar2,2);
	HLCD_createNewCustomChar(&lcd0,customChar3,3);
}

void appMain(void)
{
	while(1)
	{
		HLCD_changeCursorPosation(&lcd0,0,12);
		HLCD_displayChar(&lcd0,3);
		HLCD_displayChar(&lcd0,2);
		HLCD_displayChar(&lcd0,1);
		HLCD_displayChar(&lcd0,0);
		_delay_ms(500);
		HLCD_Clr(&lcd0);
		HLCD_changeCursorPosation(&lcd0,1,6);
		HLCD_displayChar(&lcd0,3);
		HLCD_displayChar(&lcd0,2);
		HLCD_displayChar(&lcd0,1);
		HLCD_displayChar(&lcd0,0);
		_delay_ms(500);
		HLCD_Clr(&lcd0);
		HLCD_changeCursorPosation(&lcd0,0,0);
		HLCD_displayChar(&lcd0,3);
		HLCD_displayChar(&lcd0,2);
		HLCD_displayChar(&lcd0,1);
		HLCD_displayChar(&lcd0,0);
		_delay_ms(500);
		HLCD_Clr(&lcd0);

	}
}
