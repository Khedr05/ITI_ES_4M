/*
 * dc_motor_cfg.c
 *
 * Created: 08/07/2023 21:05:29
 *  Author: 20101
 */ 

#include "dc_motor_cfg.h"

ST_DCM_cfg_t dcmCfgArr[4] = 
{
	{
		.DCM_5vPin = GPIO_PIN0,
		.DCM_5vPort = GPIO_PORTA_INDEX,
		.DCM_gndPin = GPIO_PIN1,
		.DCM_gndPort = GPIO_PORTA_INDEX,
		.DCM_intialState = DCM_TURN_OFF,
		.DCM_defaultDirection = DCM_DIR_FORWARD
	},
	{
		.DCM_5vPin = GPIO_PIN2,
		.DCM_5vPort = GPIO_PORTA_INDEX,
		.DCM_gndPin = GPIO_PIN3,
		.DCM_gndPort = GPIO_PORTA_INDEX,
		.DCM_intialState = DCM_TURN_OFF,
		.DCM_defaultDirection = DCM_DIR_FORWARD
	},
	{
		.DCM_5vPin = GPIO_PIN4,
		.DCM_5vPort = GPIO_PORTA_INDEX,
		.DCM_gndPin = GPIO_PIN5,
		.DCM_gndPort = GPIO_PORTA_INDEX,
		.DCM_intialState = DCM_TURN_OFF,
		.DCM_defaultDirection = DCM_DIR_FORWARD
	},
	{
		.DCM_5vPin = GPIO_PIN6,
		.DCM_5vPort = GPIO_PORTA_INDEX,
		.DCM_gndPin = GPIO_PIN7,
		.DCM_gndPort = GPIO_PORTA_INDEX,
		.DCM_intialState = DCM_TURN_OFF,
		.DCM_defaultDirection = DCM_DIR_FORWARD
	}		
		
};