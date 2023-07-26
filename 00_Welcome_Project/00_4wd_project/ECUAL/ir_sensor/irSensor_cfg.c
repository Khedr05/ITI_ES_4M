/*
 * irSensor_cfg.c
 *
 * Created: 14/07/2023 22:55:31
 *  Author: 20101
 */ 

#include "irSensor_Interface.h"

ST_IR_SENSOR_cfg_t arr_irCfg[IR_ARR_MAX_SIZE] =
{
	{
		.IR_pin = GPIO_PIN0,
		.IR_port = GPIO_PORTC_INDEX
	},
	{
		.IR_pin = GPIO_PIN1,
		.IR_port = GPIO_PORTC_INDEX
	}
};