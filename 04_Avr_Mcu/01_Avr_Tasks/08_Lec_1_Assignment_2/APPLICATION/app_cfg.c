/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 08_Lec_1_Assignment_2                                    	 
// File          : app_cfg.c                                  	     
// Date          : 11 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "app.h"

ST_LED_cfg_t ledOne =
{
		.ledDefaultState = LED_STATUES_OFF,
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN0
};

ST_LED_cfg_t ledTwo =
{
		.ledDefaultState = LED_STATUES_OFF,
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN1
};

ST_LED_cfg_t ledThree =
{
		.ledDefaultState = LED_STATUES_OFF,
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN2
};

ST_LED_cfg_t ledFour =
{
		.ledDefaultState = LED_STATUES_OFF,
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN3
};

ST_LED_cfg_t ledFive =
{
		.ledDefaultState = LED_STATUES_OFF,
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN4
};

ST_LED_cfg_t ledSix =
{
		.ledDefaultState = LED_STATUES_OFF,
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN5
};

ST_LED_cfg_t ledSeven =
{
		.ledDefaultState = LED_STATUES_OFF,
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN6
};

ST_LED_cfg_t ledEight =
{
		.ledDefaultState = LED_STATUES_OFF,
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN7
};

ST_EDIP_cfg_t dipSwitchOne =
{
		.dipPin = GPIO_PIN0,
		.dipPort = GPIO_PORTC
};

ST_EDIP_cfg_t dipSwitchTwo =
{
		.dipPin = GPIO_PIN1,
		.dipPort = GPIO_PORTC
};

ST_EDIP_cfg_t dipSwitchThree =
{
		.dipPin = GPIO_PIN2,
		.dipPort = GPIO_PORTC
};

ST_EDIP_cfg_t dipSwitchFour =
{
		.dipPin = GPIO_PIN3,
		.dipPort = GPIO_PORTC
};

ST_EDIP_cfg_t dipSwitchFive =
{
		.dipPin = GPIO_PIN4,
		.dipPort = GPIO_PORTC
};

ST_EDIP_cfg_t dipSwitchSix =
{
		.dipPin = GPIO_PIN5,
		.dipPort = GPIO_PORTC
};

ST_EDIP_cfg_t dipSwitchSeven =
{
		.dipPin = GPIO_PIN6,
		.dipPort = GPIO_PORTC
};

ST_EDIP_cfg_t dipSwitchEight =
{
		.dipPin = GPIO_PIN7,
		.dipPort = GPIO_PORTC
};
