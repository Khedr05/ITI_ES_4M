/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 11_Lec_4_Assignment_1                                    	 
// File          : devices_cfg.c                                  	     
// Date          : 23 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "devices_cfg.h"

ST_HLCD_cfg_t myLcd =
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

ST_HKP_cfg_t myKeypad =
{
		.arrOfRowPins =
		{
				{GPIO_PIN0},{GPIO_PIN1},{GPIO_PIN2},{GPIO_PIN3}
		},
		.arrOfRowPorts =
		{
				{GPIO_PORTD},{GPIO_PORTD},{GPIO_PORTD},{GPIO_PORTD}
		},
		.arrOfColumnPorts =
		{
				{GPIO_PORTD},{GPIO_PORTD},{GPIO_PORTD},{GPIO_PORTD}
		},
		.arrOfColumnPins =
		{
				{GPIO_PIN4},{GPIO_PIN5},{GPIO_PIN6},{GPIO_PIN7}
		}
};


