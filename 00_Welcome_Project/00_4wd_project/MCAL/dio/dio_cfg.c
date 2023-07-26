/*
 * dio_cfg.c
 *
 * Created: 07/07/2023 23:57:34
 *  Author: 20101
 */ 

#include "DIO_config.h"

const ST_pin_config_t dioCfgArr[5] =
{
	{
		GPIO_PORTA_INDEX,
		GPIO_PIN0,
		GPIO_DIRECTION_OUTPUT,
		GPIO_LOGIC_LOW
	},
	{
		GPIO_PORTA_INDEX,
		GPIO_PIN1,
		GPIO_DIRECTION_OUTPUT,
		GPIO_LOGIC_LOW
	},
	{
		GPIO_PORTA_INDEX,
		GPIO_PIN2,
		GPIO_DIRECTION_OUTPUT,
		GPIO_LOGIC_LOW		
	}		
};