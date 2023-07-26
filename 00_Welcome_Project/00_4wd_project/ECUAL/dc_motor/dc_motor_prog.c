/*
 * dc_motor_prog.c
 *
 * Created: 07/07/2023 18:50:34
 *  Author: 20101
 */ 

#include "dc_motor_interface.h"

ENU_DCM_systemState_t DCM_init(ST_DCM_cfg_t *dcmCfg)
{
	ENU_DCM_systemState_t ret;
	if(dcmCfg == PTR_NULL)
	{
		ret = DCM_NOK;
	}
	else
	{
		if(dcmCfg->DCM_defaultDirection == DCM_DIR_FORWARD)
		{
			ST_pin_config_t dcm5vPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = dcmCfg->DCM_intialState,
				.pin = dcmCfg->DCM_5vPin,
				.port = dcmCfg->DCM_5vPort
			};
			ST_pin_config_t dcmGndPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = GPIO_LOGIC_LOW,
				.pin = dcmCfg->DCM_gndPin,
				.port = dcmCfg->DCM_gndPort
			};
			GPIO_pin_intialize(&dcm5vPinCfg);
			GPIO_pin_intialize(&dcmGndPinCfg);
			ret = DCM_OK;			
		}
		else if(dcmCfg->DCM_defaultDirection == DCM_DIR_BACKWORD)
		{
			ST_pin_config_t dcm5vPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = GPIO_LOGIC_LOW,
				.pin = dcmCfg->DCM_5vPin,
				.port = dcmCfg->DCM_5vPort
			};
			ST_pin_config_t dcmGndPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = dcmCfg->DCM_intialState,
				.pin = dcmCfg->DCM_gndPin,
				.port = dcmCfg->DCM_gndPort
			};
			GPIO_pin_intialize(&dcm5vPinCfg);
			GPIO_pin_intialize(&dcmGndPinCfg);
			ret = DCM_OK;			
		}
		else
		{
			ret = DCM_NOK;
		}

	}
	return ret;
}
ENU_DCM_systemState_t DCM_turnOff(ST_DCM_cfg_t *dcmCfg)
{
	ENU_DCM_systemState_t ret;
	if(dcmCfg == PTR_NULL)
	{
		ret = DCM_NOK;
	}
	else
	{
		if(dcmCfg->DCM_defaultDirection == DCM_DIR_FORWARD)
		{
			ST_pin_config_t dcm5vPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = dcmCfg->DCM_intialState,
				.pin = dcmCfg->DCM_5vPin,
				.port = dcmCfg->DCM_5vPort
			};
			ST_pin_config_t dcmGndPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = GPIO_LOGIC_LOW,
				.pin = dcmCfg->DCM_gndPin,
				.port = dcmCfg->DCM_gndPort
			};
			GPIO_pin_write_logic(&dcm5vPinCfg , GPIO_LOGIC_LOW);
			GPIO_pin_write_logic(&dcmGndPinCfg , GPIO_LOGIC_LOW);
			ret = DCM_OK;
		}
		else if(dcmCfg->DCM_defaultDirection == DCM_DIR_BACKWORD)
		{
			ST_pin_config_t dcm5vPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = GPIO_LOGIC_LOW,
				.pin = dcmCfg->DCM_5vPin,
				.port = dcmCfg->DCM_5vPort
			};
			ST_pin_config_t dcmGndPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = dcmCfg->DCM_intialState,
				.pin = dcmCfg->DCM_gndPin,
				.port = dcmCfg->DCM_gndPort
			};
			GPIO_pin_write_logic(&dcm5vPinCfg , GPIO_LOGIC_LOW);
			GPIO_pin_write_logic(&dcmGndPinCfg , GPIO_LOGIC_LOW);
			ret = DCM_OK;
		}
		else
		{
			ret = DCM_NOK;
		}

	}
	return ret;
}
ENU_DCM_systemState_t DCM_turnOn(ST_DCM_cfg_t *dcmCfg)
{
	ENU_DCM_systemState_t ret;
	if(dcmCfg == PTR_NULL)
	{
		ret = DCM_NOK;
	}
	else
	{
		if(dcmCfg->DCM_defaultDirection == DCM_DIR_FORWARD)
		{
			ST_pin_config_t dcm5vPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = dcmCfg->DCM_intialState,
				.pin = dcmCfg->DCM_5vPin,
				.port = dcmCfg->DCM_5vPort
			};
			ST_pin_config_t dcmGndPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = GPIO_LOGIC_LOW,
				.pin = dcmCfg->DCM_gndPin,
				.port = dcmCfg->DCM_gndPort
			};
			GPIO_pin_write_logic(&dcm5vPinCfg , GPIO_LOGIC_HIGH);
			GPIO_pin_write_logic(&dcmGndPinCfg , GPIO_LOGIC_LOW);
			ret = DCM_OK;
		}
		else if(dcmCfg->DCM_defaultDirection == DCM_DIR_BACKWORD)
		{
			ST_pin_config_t dcm5vPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = GPIO_LOGIC_LOW,
				.pin = dcmCfg->DCM_5vPin,
				.port = dcmCfg->DCM_5vPort
			};
			ST_pin_config_t dcmGndPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = dcmCfg->DCM_intialState,
				.pin = dcmCfg->DCM_gndPin,
				.port = dcmCfg->DCM_gndPort
			};
			GPIO_pin_write_logic(&dcm5vPinCfg , GPIO_LOGIC_LOW);
			GPIO_pin_write_logic(&dcmGndPinCfg , GPIO_LOGIC_HIGH);
			ret = DCM_OK;
		}
		else
		{
			ret = DCM_NOK;
		}

	}
	return ret;
}

ENU_DCM_systemState_t DCM_changeDirection(ST_DCM_cfg_t *dcmCfg , ENU_DCM_direction_t dcmDirction)
{
	ENU_DCM_systemState_t ret;
	if(dcmCfg == PTR_NULL)
	{
		ret = DCM_NOK;
	}
	else
	{
		if(dcmDirction == DCM_DIR_FORWARD)
		{
			ST_pin_config_t dcm5vPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = dcmCfg->DCM_intialState,
				.pin = dcmCfg->DCM_5vPin,
				.port = dcmCfg->DCM_5vPort
			};
			ST_pin_config_t dcmGndPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = GPIO_LOGIC_LOW,
				.pin = dcmCfg->DCM_gndPin,
				.port = dcmCfg->DCM_gndPort
			};
			dcmCfg->DCM_defaultDirection = dcmDirction;
			ret = DCM_OK;
		}
		else if(dcmDirction == DCM_DIR_BACKWORD)
		{
			ST_pin_config_t dcm5vPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = GPIO_LOGIC_LOW,
				.pin = dcmCfg->DCM_5vPin,
				.port = dcmCfg->DCM_5vPort
			};
			ST_pin_config_t dcmGndPinCfg =
			{
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = dcmCfg->DCM_intialState,
				.pin = dcmCfg->DCM_gndPin,
				.port = dcmCfg->DCM_gndPort
			};
			dcmCfg->DCM_defaultDirection = dcmDirction;
			ret = DCM_OK;
		}
		else
		{
			ret = DCM_NOK;
		}

	}
	return ret;	
}

