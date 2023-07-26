/*
 * irSensor_prog.c
 *
 * Created: 14/07/2023 22:43:51
 *  Author: 20101
 */ 


#include "irSensor_Interface.h"

ENU_IR_SENSOR_systemState_t    IR_SENSOR_init(ST_IR_SENSOR_cfg_t *ptr_irCfg)
{
	ENU_IR_SENSOR_systemState_t ret = IR_SENSOR_NOK;
	if(ptr_irCfg == PTR_NULL)
	{
		ret = IR_SENSOR_NOK;
	}
	else
	{
		ST_pin_config_t irPin =
		{
			.direction = GPIO_DIRECTION_INPUT,
			.pin = ptr_irCfg->IR_pin,
			.port = ptr_irCfg->IR_port
		}; 
		GPIO_pin_intialize(&irPin);
		ret = IR_SENSOR_OK;
	}
	return ret;
}
ENU_IR_SENSOR_systemState_t    IR_SENSOR_readData(ST_IR_SENSOR_cfg_t *ptr_irCfg , ENU_IR_SENSOR_surfaceState_t *irState)
{
	ENU_IR_SENSOR_systemState_t ret = IR_SENSOR_NOK;
	if(ptr_irCfg == PTR_NULL)
	{
		ret = IR_SENSOR_NOK;
	}
	else
	{
		EN_logic_t irPinState;
		ST_pin_config_t irPin =
		{
			.direction = GPIO_DIRECTION_INPUT,
			.pin = ptr_irCfg->IR_pin,
			.port = ptr_irCfg->IR_port
		};
		GPIO_pin_read_logic(&irPin , &irPinState);
		
		if(irPinState == GPIO_LOGIC_HIGH)
		{
			*irState = IR_SENSOR_ON_WHITE;
		}
		else if(irPinState == GPIO_LOGIC_LOW)
		{
			*irState = IR_SENSOR_ON_BLACK;
		}
		else
		{
			/*do nothing */
		}
		ret = IR_SENSOR_OK;
	}
	return ret;	
}