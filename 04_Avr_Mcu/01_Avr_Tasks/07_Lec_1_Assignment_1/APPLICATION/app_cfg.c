/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 07_Lec_1_Assignment_1                                    	 
// File          : app_cfg.c                                  	     
// Date          : 11 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "app.h"

ST_LED_cfg_t greenLed =
{
		.ledDefaultState = LED_STATUES_OFF,
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN0
};

ST_LED_cfg_t yellowLed =
{
		.ledDefaultState = LED_STATUES_OFF,
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN1
};

ST_LED_cfg_t redLed =
{
		.ledDefaultState = LED_STATUES_OFF,
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN2
};

ST_SSD_cfg_t ssdOne =
{
		.ssdCommonType = SSD_ANODE_COMMON,
		.ssdPinAPinNumber = GPIO_PIN0,
		.ssdPinBPinNumber = GPIO_PIN1,
		.ssdPinCPinNumber = GPIO_PIN2,
		.ssdPinDPinNumber = GPIO_PIN3,
		.ssdPinEPinNumber = GPIO_PIN4,
		.ssdPinFPinNumber = GPIO_PIN5,
		.ssdPinGPinNumber = GPIO_PIN6,
		.ssdPinComPinNumber = GPIO_PIN7,
		.ssdPinAPortName = GPIO_PORTC,
		.ssdPinBPortName = GPIO_PORTC,
		.ssdPinCPortName = GPIO_PORTC,
		.ssdPinDPortName = GPIO_PORTC,
		.ssdPinEPortName = GPIO_PORTC,
		.ssdPinFPortName = GPIO_PORTC,
		.ssdPinGPortName = GPIO_PORTC,
		.ssdPinComPortName = GPIO_PORTC

};

ST_SSD_cfg_t ssdTwo =
{
		.ssdCommonType = SSD_ANODE_COMMON,
		.ssdPinAPinNumber = GPIO_PIN0,
		.ssdPinBPinNumber = GPIO_PIN1,
		.ssdPinCPinNumber = GPIO_PIN2,
		.ssdPinDPinNumber = GPIO_PIN3,
		.ssdPinEPinNumber = GPIO_PIN4,
		.ssdPinFPinNumber = GPIO_PIN5,
		.ssdPinGPinNumber = GPIO_PIN6,
		.ssdPinComPinNumber = GPIO_PIN7,
		.ssdPinAPortName = GPIO_PORTD,
		.ssdPinBPortName = GPIO_PORTD,
		.ssdPinCPortName = GPIO_PORTD,
		.ssdPinDPortName = GPIO_PORTD,
		.ssdPinEPortName = GPIO_PORTD,
		.ssdPinFPortName = GPIO_PORTD,
		.ssdPinGPortName = GPIO_PORTD,
		.ssdPinComPortName = GPIO_PORTD

};

