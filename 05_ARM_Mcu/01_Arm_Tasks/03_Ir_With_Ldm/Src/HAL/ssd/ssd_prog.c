/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : ssd_prog.c                                  	     
// Date          : Sep 15, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/HAL/ssd/ssd_interface.h"

static uint8_t arrOfNum[10] = {0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F};


EN_HSSD_systemState_t HSSD_init(ST_HSSD_cfg_t const *copy_uddtPsOfSsd)
{
	EN_HSSD_systemState_t ret = HSSD_NOK;

	if(PTR_NULL != copy_uddtPsOfSsd)
	{
		for(uint8_t i=0 ; i<=8 ; i++)
		{
		   MGPIO_setPinMode(copy_uddtPsOfSsd->uddtSsdPortsName[i],copy_uddtPsOfSsd->uddtSsdPinsNumber[i], MGPIO_MODE_OUTPUT);
		   MGPIO_setOutputMode(copy_uddtPsOfSsd->uddtSsdPortsName[i],copy_uddtPsOfSsd->uddtSsdPinsNumber[i],MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
		   MGPIO_setOutputSpeed(copy_uddtPsOfSsd->uddtSsdPortsName[i],copy_uddtPsOfSsd->uddtSsdPinsNumber[i],MGPIO_OUTPUT_SPEED_HIGH);
		}
		ret = HSSD_OK;
	}
	else
	{
		ret = HSSD_PTR_NULL;
	}

	return ret;
}

EN_HSSD_systemState_t HSSD_displayNumber(ST_HSSD_cfg_t const *copy_uddtPsOfSsd , EN_HSSD_numberOptions_t copy_uddtNumber)
{
	EN_HSSD_systemState_t ret = HSSD_NOK;

	if(PTR_NULL != copy_uddtPsOfSsd)
	{
		if(copy_uddtNumber >=HSSD_ZERO && copy_uddtNumber <=HSSD_NINE)
		{
			if(copy_uddtPsOfSsd->uddtCommanPinMode == HSSD_COMMAN_CATHODE)
			{
				for(uint8_t i=0 ; i<= 6; i++)
				{
					MGPIO_setPinVal(copy_uddtPsOfSsd->uddtSsdPortsName[i],copy_uddtPsOfSsd->uddtSsdPinsNumber[i],GET_BIT(arrOfNum[copy_uddtNumber],i));
				}
				MGPIO_setPinVal(copy_uddtPsOfSsd->uddtSsdPortsName[COM_PIN],copy_uddtPsOfSsd->uddtSsdPinsNumber[COM_PIN],MGPIO_LOGIC_LOW);

				ret = HSSD_OK;
			}
			else if(copy_uddtPsOfSsd->uddtCommanPinMode == HSSD_COMMAN_ANODE)
			{
				for(uint8_t i=0 ; i<= 6; i++)
				{
					MGPIO_setPinVal(copy_uddtPsOfSsd->uddtSsdPortsName[i],copy_uddtPsOfSsd->uddtSsdPinsNumber[i],!GET_BIT(arrOfNum[copy_uddtNumber],i));
				}
				MGPIO_setPinVal(copy_uddtPsOfSsd->uddtSsdPortsName[COM_PIN],copy_uddtPsOfSsd->uddtSsdPinsNumber[COM_PIN],MGPIO_LOGIC_HIGH);
				ret = HSSD_OK;
			}
			else
			{
				ret = HSSD_INVALID_PARAMTERS;
			}
		}
		else
		{
			ret = HSSD_INVALID_PARAMTERS;
		}
	}
	else
	{
		ret = HSSD_PTR_NULL;
	}

	return ret;
}

EN_HSSD_systemState_t HSSD_enableDot(ST_HSSD_cfg_t const *copy_uddtPsOfSsd)
{
	EN_HSSD_systemState_t ret = HSSD_NOK;

	if(PTR_NULL  != copy_uddtPsOfSsd)
	{
		if(copy_uddtPsOfSsd->uddtCommanPinMode == HSSD_COMMAN_CATHODE)
		{
			MGPIO_setPinVal(copy_uddtPsOfSsd->uddtSsdPortsName[DOT_PIN],copy_uddtPsOfSsd->uddtSsdPinsNumber[DOT_PIN],MGPIO_LOGIC_HIGH);
			MGPIO_setPinVal(copy_uddtPsOfSsd->uddtSsdPortsName[COM_PIN],copy_uddtPsOfSsd->uddtSsdPinsNumber[COM_PIN],MGPIO_LOGIC_LOW);
			ret = HSSD_OK;
		}
		else if(copy_uddtPsOfSsd->uddtCommanPinMode == HSSD_COMMAN_ANODE)
		{
			MGPIO_setPinVal(copy_uddtPsOfSsd->uddtSsdPortsName[DOT_PIN],copy_uddtPsOfSsd->uddtSsdPinsNumber[DOT_PIN],MGPIO_LOGIC_LOW);
			MGPIO_setPinVal(copy_uddtPsOfSsd->uddtSsdPortsName[COM_PIN],copy_uddtPsOfSsd->uddtSsdPinsNumber[COM_PIN],MGPIO_LOGIC_HIGH);
			ret = HSSD_OK;
		}
		else
		{
			ret = HSSD_INVALID_PARAMTERS;
		}
		ret = HSSD_OK;
	}
	else
	{
		ret = HSSD_PTR_NULL;
	}

	return ret;
}

EN_HSSD_systemState_t HSSD_disableDot(ST_HSSD_cfg_t const *copy_uddtPsOfSsd)
{
	EN_HSSD_systemState_t ret = HSSD_NOK;

	if(PTR_NULL  != copy_uddtPsOfSsd)
	{
		if(copy_uddtPsOfSsd->uddtCommanPinMode == HSSD_COMMAN_CATHODE)
		{
			MGPIO_setPinVal(copy_uddtPsOfSsd->uddtSsdPortsName[DOT_PIN],copy_uddtPsOfSsd->uddtSsdPinsNumber[DOT_PIN],MGPIO_LOGIC_LOW);
			ret = HSSD_OK;
		}
		else if(copy_uddtPsOfSsd->uddtCommanPinMode == HSSD_COMMAN_ANODE)
		{
			MGPIO_setPinVal(copy_uddtPsOfSsd->uddtSsdPortsName[DOT_PIN],copy_uddtPsOfSsd->uddtSsdPinsNumber[DOT_PIN],MGPIO_LOGIC_HIGH);
			ret = HSSD_OK;
		}
		else
		{
			ret = HSSD_INVALID_PARAMTERS;
		}
		ret = HSSD_OK;
	}
	else
	{
		ret = HSSD_PTR_NULL;
	}

	return ret;
}
