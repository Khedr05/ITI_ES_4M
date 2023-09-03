/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : pb_prog.c                                  	     
// Date          : 14 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "pb_interface.h"


EN_HPB_systeamState_t HPB_init(ST_HPB_cfg_t const *ST_ptrPbCfgInstance)
{
	EN_HPB_systeamState_t pbRet = HPB_OK;
	EN_GPIO_systemState_t gpioRet = GPIO_NOK;

	if(PTR_NULL != ST_ptrPbCfgInstance)
	{
		//EN_GPIO_pinLogic_t pbPinLogic;

		/*if(ST_ptrPbCfgInstance->PbInternalResistor == HPB_PULL_UP)
			pbPinLogic = GPIO_HIGH;
		else if(ST_ptrPbCfgInstance->PbInternalResistor == HPB_PULL_DOWN)
			pbPinLogic = GPIO_LOW;
		else  Do Nothing */

		ST_GPIO_cfg_t pbPinCfg =
		{
				.portName = ST_ptrPbCfgInstance->pbPort,
				.pinNumber = ST_ptrPbCfgInstance->PbPin,
				.pinDirection = GPIO_INPUT,
				.logicOnPin = (EN_GPIO_pinLogic_t)ST_ptrPbCfgInstance->PbInternalResistor
		};

		gpioRet = GPIO_initPin(&pbPinCfg);

		if(gpioRet == GPIO_OK) pbRet = HPB_OK; else pbRet = HPB_NOK;
	}
	else
	{
		pbRet = HPB_PTR_NULL;
	}

	return pbRet;
}

EN_HPB_systeamState_t HPB_getBtnStates(ST_HPB_cfg_t const *ST_ptrPbCfgInstance , EN_HPB_state_t *ptrOfStatesRet)
{
	EN_HPB_systeamState_t pbRet = HPB_OK;
	EN_GPIO_systemState_t gpioRet = GPIO_NOK;

	if( (PTR_NULL != ST_ptrPbCfgInstance) && (PTR_NULL != ptrOfStatesRet))
	{
		ST_GPIO_cfg_t pbPinCfg =
		{
				.portName = ST_ptrPbCfgInstance->pbPort,
				.pinNumber = ST_ptrPbCfgInstance->PbPin,
		};

		EN_GPIO_pinLogic_t pbPinLogic;
		EN_GPIO_pinLogic_t tempForDebouncing;
		gpioRet = GPIO_readPinLogic(&pbPinCfg,&pbPinLogic);
		tempForDebouncing = pbPinLogic;
		while(tempForDebouncing == pbPinLogic)
		{
			gpioRet = GPIO_readPinLogic(&pbPinCfg,&pbPinLogic);
		}
		if(gpioRet == GPIO_OK)
		{
			if(ST_ptrPbCfgInstance->PbInternalResistor == HPB_PULL_UP)
			{
				if(pbPinLogic == GPIO_LOW)
				{
					*ptrOfStatesRet = HPB_STATE_PRESSED;
					pbRet = HPB_OK;
				}
				else if(pbPinLogic == GPIO_HIGH)
				{
					*ptrOfStatesRet = HPB_STATE_RELEASED;
					pbRet = HPB_OK;
				}
				else /* Do Nothing */;

			}
			else if(ST_ptrPbCfgInstance->PbInternalResistor == HPB_PULL_DOWN)
			{
				if(pbPinLogic == GPIO_HIGH)
				{
					*ptrOfStatesRet = HPB_STATE_PRESSED;
					pbRet = HPB_OK;
				}
				else if(pbPinLogic == GPIO_LOW)
				{
					*ptrOfStatesRet = HPB_STATE_RELEASED;
					pbRet = HPB_OK;
				}
				else /* Do Nothing */;
			}else /* Do Nothing */;
		}
		else
		{
			pbRet = HPB_NOK;
		}

	}
	else
	{
		pbRet = HPB_PTR_NULL;
	}

	return pbRet;
}
