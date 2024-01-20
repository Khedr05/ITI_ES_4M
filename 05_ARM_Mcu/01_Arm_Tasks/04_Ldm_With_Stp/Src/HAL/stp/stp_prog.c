/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : stp_prog.c                                  	     
// Date          : Sep 26, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/HAL/stp/stp_interface.h"

EN_HSTP_systeamState_t HSTP_uddtInit(ST_HSTP_cfg_t const *PS_stpCfg)
{
	EN_HSTP_systeamState_t ret = HSTP_NOK;
	if(PTR_NULL != PS_stpCfg)
	{
		MGPIO_setPinMode(PS_stpCfg->dataPortName, PS_stpCfg->dataPinNumber, MGPIO_MODE_OUTPUT);
		MGPIO_setOutputMode(PS_stpCfg->dataPortName,PS_stpCfg->dataPinNumber, MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
		MGPIO_setOutputSpeed(PS_stpCfg->dataPortName, PS_stpCfg->dataPinNumber, MGPIO_OUTPUT_SPEED_HIGH);

		MGPIO_setPinMode(PS_stpCfg->latchBitPortName, PS_stpCfg->latchBitPinNumber, MGPIO_MODE_OUTPUT);
		MGPIO_setOutputMode(PS_stpCfg->latchBitPortName,PS_stpCfg->latchBitPinNumber, MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
		MGPIO_setOutputSpeed(PS_stpCfg->latchBitPortName, PS_stpCfg->latchBitPinNumber, MGPIO_OUTPUT_SPEED_HIGH);

		MGPIO_setPinMode(PS_stpCfg->latchBytePortName, PS_stpCfg->latchBytePinNumber, MGPIO_MODE_OUTPUT);
		MGPIO_setOutputMode(PS_stpCfg->latchBytePortName,PS_stpCfg->latchBytePinNumber, MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
		MGPIO_setOutputSpeed(PS_stpCfg->latchBytePortName, PS_stpCfg->latchBytePinNumber, MGPIO_OUTPUT_SPEED_HIGH);


		ret = HSTP_OK;
	}
	else
	{

		ret = HSTP_PTR_NULL;
	}

	return ret;
}
EN_HSTP_systeamState_t HSTP_uddtByteOutput(ST_HSTP_cfg_t const *PS_stpCfg , uint8_t  copy_u8DataToOutput)
{
	EN_HSTP_systeamState_t ret = HSTP_NOK;
	if(PTR_NULL != PS_stpCfg)
	{
		uint8_t loc_u8Counter = 0;
		MGPIO_setPinVal(PS_stpCfg->latchBytePortName, PS_stpCfg->latchBytePinNumber, MGPIO_LOGIC_LOW);

		for(loc_u8Counter= 8; loc_u8Counter > 0 ;loc_u8Counter--)
		{
			MGPIO_setPinVal( PS_stpCfg->dataPortName , PS_stpCfg->dataPinNumber , ( GET_BIT( copy_u8DataToOutput , ( loc_u8Counter - 1))));

			MGPIO_setPinVal( PS_stpCfg->latchBitPortName , PS_stpCfg->latchBitPinNumber , MGPIO_LOGIC_HIGH);
			MSTK_setBusyWait(10);
			MGPIO_setPinVal( PS_stpCfg->latchBitPortName , PS_stpCfg->latchBitPinNumber , MGPIO_LOGIC_LOW);
		}

		MGPIO_setPinVal( PS_stpCfg->latchBytePortName , PS_stpCfg->latchBytePinNumber , MGPIO_LOGIC_HIGH);
		MSTK_setBusyWait(10);
		MGPIO_setPinVal( PS_stpCfg->latchBytePortName , PS_stpCfg->latchBytePinNumber , MGPIO_LOGIC_LOW);
		ret = HSTP_OK;
	}
	else
	{

		ret = HSTP_PTR_NULL;
	}

	return ret;
}
EN_HSTP_systeamState_t HSTP_uddtHalfWordOutput(ST_HSTP_cfg_t const *PS_stpCfg ,uint16_t copy_u16DataToOutput)
{
	EN_HSTP_systeamState_t ret = HSTP_NOK;
	if(PTR_NULL != PS_stpCfg)
	{
		uint16_t loc_u8Counter = 0;
		MGPIO_setPinVal(PS_stpCfg->latchBytePortName, PS_stpCfg->latchBytePinNumber, MGPIO_LOGIC_LOW);

		for(loc_u8Counter= 16; loc_u8Counter > 0 ;loc_u8Counter--)
		{
			MGPIO_setPinVal( PS_stpCfg->dataPortName , PS_stpCfg->dataPinNumber , ( GET_BIT( copy_u16DataToOutput , ( loc_u8Counter - 1))));

			MGPIO_setPinVal( PS_stpCfg->latchBitPortName , PS_stpCfg->latchBitPinNumber , MGPIO_LOGIC_HIGH);
			MSTK_setBusyWait(10);
			MGPIO_setPinVal( PS_stpCfg->latchBitPortName , PS_stpCfg->latchBitPinNumber , MGPIO_LOGIC_LOW);
		}

		MGPIO_setPinVal( PS_stpCfg->latchBytePortName , PS_stpCfg->latchBytePinNumber , MGPIO_LOGIC_HIGH);
		MSTK_setBusyWait(10);
		MGPIO_setPinVal( PS_stpCfg->latchBytePortName , PS_stpCfg->latchBytePinNumber , MGPIO_LOGIC_LOW);
		ret = HSTP_OK;
	}
	else
	{

		ret = HSTP_PTR_NULL;
	}

	return ret;
}

