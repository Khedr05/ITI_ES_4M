/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : exti_prog.c                                  	     
// Date          : 14 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "exti_interface.h"

static void(*ptr_exti0IsrAction)(void) = PTR_NULL;
static void(*ptr_exti1IsrAction)(void) = PTR_NULL;
static void(*ptr_exti2IsrAction)(void) = PTR_NULL;

static EN_MEXTI_systemState_t exti0SetHandlerToAction(void(*ptr_Handler)(void))
{
	EN_MEXTI_systemState_t extiRet = MEXTI_NOK;

	if(PTR_NULL != ptr_Handler)
	{
		ptr_exti0IsrAction = ptr_Handler;
		extiRet = MEXTI_OK;
	}
	else
	{
		extiRet = MEXTI_PTR_NULL;
	}

	return extiRet;
}

static EN_MEXTI_systemState_t exti1SetHandlerToAction(void(*ptr_Handler)(void))
{
	EN_MEXTI_systemState_t extiRet = MEXTI_NOK;

	if(PTR_NULL != ptr_Handler)
	{
		ptr_exti1IsrAction = ptr_Handler;
		extiRet = MEXTI_OK;
	}
	else
	{
		extiRet = MEXTI_PTR_NULL;
	}

	return extiRet;
}

static EN_MEXTI_systemState_t exti2SetHandlerToAction(void(*ptr_Handler)(void))
{
	EN_MEXTI_systemState_t extiRet = MEXTI_NOK;

	if(PTR_NULL != ptr_Handler)
	{
		ptr_exti2IsrAction = ptr_Handler;
		extiRet = MEXTI_OK;
	}
	else
	{
		extiRet = MEXTI_PTR_NULL;
	}

	return extiRet;
}



EN_MEXTI_systemState_t MEXTI_initExti(ST_MEXTI_cfg_t const *ST_ptrExtiCfgInstance)
{
	EN_MEXTI_systemState_t extiRet = MEXTI_NOK;

	if(PTR_NULL != ST_ptrExtiCfgInstance)
	{
		switch(ST_ptrExtiCfgInstance->numberOfExti)
		{
		case MEXTI_EXTI0_INTERRUPT:
		{

			if(ST_ptrExtiCfgInstance->extiTriggerSence == MEXTI_LOW_LEVEL_SENSE_CONTROL)
			{
				CLR_BIT(GICR_REG,INT0_BIT);
				CLR_BIT(MCUCR_REG,ISC01_BIT);
				CLR_BIT(MCUCR_REG,ISC00_BIT);
				extiRet = MEXTI_OK;
			}
			else if(ST_ptrExtiCfgInstance->extiTriggerSence == MEXTI_ANY_LOGICAL_SENSE_CONTROL)
			{
				CLR_BIT(GICR_REG,INT0_BIT);
				CLR_BIT(MCUCR_REG,ISC01_BIT);
				SET_BIT(MCUCR_REG,ISC00_BIT);
				extiRet = MEXTI_OK;
			}
			else if(ST_ptrExtiCfgInstance->extiTriggerSence == MEXTI_FALLING_EDGE_SENSE_CONTROL)
			{
				CLR_BIT(GICR_REG,INT0_BIT);
				SET_BIT(MCUCR_REG,ISC01_BIT);
				CLR_BIT(MCUCR_REG,ISC00_BIT);
				extiRet = MEXTI_OK;
			}
			else if(ST_ptrExtiCfgInstance->extiTriggerSence == MEXTI_RISING_EDGE_SENSE_CONTROL)
			{
				CLR_BIT(GICR_REG,INT0_BIT);
				SET_BIT(MCUCR_REG,ISC01_BIT);
				SET_BIT(MCUCR_REG,ISC00_BIT);
				extiRet = MEXTI_OK;
			}
			else
			{
				extiRet = MEXTI_INVALID_PARAMTER;
			}
			break;
		}
		case MEXTI_EXTI1_INTERRUPT:
		{

			if(ST_ptrExtiCfgInstance->extiTriggerSence == MEXTI_LOW_LEVEL_SENSE_CONTROL)
			{
				CLR_BIT(GICR_REG,INT1_BIT);
				CLR_BIT(MCUCR_REG,ISC11_BIT);
				CLR_BIT(MCUCR_REG,ISC10_BIT);
				extiRet = MEXTI_OK;
			}
			else if(ST_ptrExtiCfgInstance->extiTriggerSence == MEXTI_ANY_LOGICAL_SENSE_CONTROL)
			{
				CLR_BIT(GICR_REG,INT1_BIT);
				CLR_BIT(MCUCR_REG,ISC11_BIT);
				SET_BIT(MCUCR_REG,ISC10_BIT);
				extiRet = MEXTI_OK;
			}
			else if(ST_ptrExtiCfgInstance->extiTriggerSence == MEXTI_FALLING_EDGE_SENSE_CONTROL)
			{
				CLR_BIT(GICR_REG,INT1_BIT);
				SET_BIT(MCUCR_REG,ISC11_BIT);
				CLR_BIT(MCUCR_REG,ISC10_BIT);
				extiRet = MEXTI_OK;
			}
			else if(ST_ptrExtiCfgInstance->extiTriggerSence == MEXTI_RISING_EDGE_SENSE_CONTROL)
			{
				CLR_BIT(GICR_REG,INT1_BIT);
				SET_BIT(MCUCR_REG,ISC11_BIT);
				SET_BIT(MCUCR_REG,ISC10_BIT);
				extiRet = MEXTI_OK;
			}
			else
			{
				extiRet = MEXTI_INVALID_PARAMTER;
			}
			break;
		}

		case MEXTI_EXTI2_INTERRUPT:
		{

			if(ST_ptrExtiCfgInstance->extiTriggerSence == MEXTI_FALLING_EDGE_SENSE_CONTROL)
			{
				CLR_BIT(GICR_REG,INT2_BIT);
				CLR_BIT(MCUCSR_REG,ISC2_BIT);
				extiRet = MEXTI_OK;
			}
			else if(ST_ptrExtiCfgInstance->extiTriggerSence == MEXTI_RISING_EDGE_SENSE_CONTROL)
			{
				SET_BIT(GICR_REG,INT2_BIT);
				SET_BIT(MCUCSR_REG,ISC2_BIT);
				extiRet = MEXTI_OK;
			}
			else
			{
				extiRet = MEXTI_INVALID_PARAMTER;
			}
			break;
		}
		}
	}
	else
	{
		extiRet = MEXTI_PTR_NULL;
	}

	return extiRet;
}

EN_MEXTI_systemState_t MEXTI_enableExti(ST_MEXTI_cfg_t const *ST_ptrExtiCfgInstance)
{
	EN_MEXTI_systemState_t extiRet = MEXTI_NOK;

	if(PTR_NULL != ST_ptrExtiCfgInstance)
	{
		switch(ST_ptrExtiCfgInstance->numberOfExti)
		{
		case MEXTI_EXTI0_INTERRUPT:
		{
			SET_BIT(GICR_REG,INT0_BIT);
			extiRet = exti0SetHandlerToAction(ST_ptrExtiCfgInstance->MEXTI_ptrCallbackHandler);
			break;
		}
		case MEXTI_EXTI1_INTERRUPT:
		{
			SET_BIT(GICR_REG,INT1_BIT);
			extiRet = exti1SetHandlerToAction(ST_ptrExtiCfgInstance->MEXTI_ptrCallbackHandler);
			break;
		}
		case MEXTI_EXTI2_INTERRUPT:
		{
			SET_BIT(GICR_REG,INT2_BIT);
			extiRet = exti2SetHandlerToAction(ST_ptrExtiCfgInstance->MEXTI_ptrCallbackHandler);
			break;
		}
		}
	}
	else
	{
		extiRet = MEXTI_PTR_NULL;
	}
	return extiRet;
}

EN_MEXTI_systemState_t MEXTI_disableExti(ST_MEXTI_cfg_t const *ST_ptrExtiCfgInstance)
{
	EN_MEXTI_systemState_t extiRet = MEXTI_NOK;

	if(PTR_NULL != ST_ptrExtiCfgInstance)
	{
		switch(ST_ptrExtiCfgInstance->numberOfExti)
		{
		case MEXTI_EXTI0_INTERRUPT:
		{
			CLR_BIT(GICR_REG,INT0_BIT);
			extiRet = MEXTI_OK;
			break;
		}
		case MEXTI_EXTI1_INTERRUPT:
		{
			CLR_BIT(GICR_REG,INT1_BIT);
			extiRet = MEXTI_OK;
			break;
		}
		case MEXTI_EXTI2_INTERRUPT:
		{
			CLR_BIT(GICR_REG,INT2_BIT);
			extiRet = MEXTI_OK;
			break;
		}
		}
	}
	else
	{
		extiRet = MEXTI_PTR_NULL;
	}

	return extiRet;
}


ISR(EXT_INT_0)
{
	ptr_exti0IsrAction();
}

ISR(EXT_INT_1)
{
	ptr_exti1IsrAction();
}

ISR(EXT_INT_2)
{
	ptr_exti2IsrAction();
}






