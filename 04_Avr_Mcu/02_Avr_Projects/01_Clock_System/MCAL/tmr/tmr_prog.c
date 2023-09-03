/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : tmr_prog.c                                  	     
// Date          : 17 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "tmr_interface.h"


static void(*ptr_IsrCallingForOvfTmr0)(void) = PTR_NULL;
static void(*ptr_IsrCallingForOcTmr0) (void) = PTR_NULL;

static void(*ptr_IsrCallingForOvfTmr1)(void) = PTR_NULL;
static void(*ptr_IsrCallingForOcBTmr1)(void) = PTR_NULL;
static void(*ptr_IsrCallingForOcATmr1)(void) = PTR_NULL;
static void(*ptr_IsrCallingForIcuTmr1)(void) = PTR_NULL;

static void(*ptr_IsrCallingForOvfTmr2)(void) = PTR_NULL;
static void(*ptr_IsrCallingForOcTmr2) (void) = PTR_NULL;



static EN_MTMR_systemState_t MTMR_setAddressOfCallback(ST_MTMR_cfg_t const *ST_ptrCfgInstance_t)
{
	EN_MTMR_systemState_t tmrRet = MTMR_NOK;

	if(PTR_NULL != ST_ptrCfgInstance_t)
	{
		switch(ST_ptrCfgInstance_t->timerChannel)
		{
		case MTMR_TIMER_0_Channel:
		{

			if(PTR_NULL != ST_ptrCfgInstance_t->MTMR_setCallbackForOvf)
			{ ptr_IsrCallingForOvfTmr0 = ST_ptrCfgInstance_t->MTMR_setCallbackForOvf; tmrRet = MTMR_OK;}
			else tmrRet = MTMR_PTR_NULL;

			if((tmrRet = MTMR_OK) && (PTR_NULL != ST_ptrCfgInstance_t->MTMR_setCallbackForOcChannelA))
			{ ptr_IsrCallingForOcTmr0 = ST_ptrCfgInstance_t->MTMR_setCallbackForOcChannelA; tmrRet = MTMR_OK; }
			else tmrRet = MTMR_PTR_NULL;

			break;
		}
		case MTMR_TIMER_1_Channel:
		{

			if(PTR_NULL != ST_ptrCfgInstance_t->MTMR_setCallbackForOvf)
			{ ptr_IsrCallingForOvfTmr1 = ST_ptrCfgInstance_t->MTMR_setCallbackForOvf; tmrRet = MTMR_OK;}
			else tmrRet = MTMR_PTR_NULL;

			if((tmrRet = MTMR_OK) && (PTR_NULL != ST_ptrCfgInstance_t->MTMR_setCallbackForOcChannelA))
			{ ptr_IsrCallingForOcATmr1 = ST_ptrCfgInstance_t->MTMR_setCallbackForOcChannelA; tmrRet = MTMR_OK; }
			else tmrRet = MTMR_PTR_NULL;

			if((tmrRet = MTMR_OK) && (PTR_NULL != ST_ptrCfgInstance_t->MTMR_setCallbackForOcChannelB))
			{ ptr_IsrCallingForOcBTmr1 = ST_ptrCfgInstance_t->MTMR_setCallbackForOcChannelB; tmrRet = MTMR_OK; }
			else tmrRet = MTMR_PTR_NULL;

			if((tmrRet = MTMR_OK) && (PTR_NULL != ST_ptrCfgInstance_t->MTMR_setCallbackForIcu))
			{ ptr_IsrCallingForIcuTmr1 = ST_ptrCfgInstance_t->MTMR_setCallbackForIcu; tmrRet = MTMR_OK; }
			else tmrRet = MTMR_PTR_NULL;

			break;
		}
		case MTMR_TIMER_2_Channel:
		{

			if(PTR_NULL != ST_ptrCfgInstance_t->MTMR_setCallbackForOvf)
			{ ptr_IsrCallingForOvfTmr2 = ST_ptrCfgInstance_t->MTMR_setCallbackForOvf; tmrRet = MTMR_OK;}
			else tmrRet = MTMR_PTR_NULL;

			if((tmrRet = MTMR_OK) && (PTR_NULL != ST_ptrCfgInstance_t->MTMR_setCallbackForOcChannelA))
			{ ptr_IsrCallingForOcTmr2 = ST_ptrCfgInstance_t->MTMR_setCallbackForOcChannelA; tmrRet = MTMR_OK; }
			else tmrRet = MTMR_PTR_NULL;

			break;
		}
		default :
		{

			tmrRet = MTMR_INVALID_PARAMTER;
			break;
		}
		}
	}
	else
	{
		tmrRet = MTMR_PTR_NULL;
	}

	return tmrRet;
}



EN_MTMR_systemState_t   MTMR_init(ST_MTMR_cfg_t const *ST_ptrCfgInstance_t)
{
	EN_MTMR_systemState_t tmrRet = MTMR_NOK;

	if(PTR_NULL != ST_ptrCfgInstance_t)
	{
		switch(ST_ptrCfgInstance_t->timerChannel)
		{
		case MTMR_TIMER_0_Channel:
		{

			TCCR0_REG = ((TCCR0_REG & 0xBF)   | (ST_ptrCfgInstance_t->timerMode << WGM00_BIT ));
			TCCR0_REG = ((TCCR0_REG & 0xF7)   | ((ST_ptrCfgInstance_t->timerMode >> 1) << WGM01_BIT ));
			TCCR0_REG = ((TCCR0_REG & 0xCF)   | (ST_ptrCfgInstance_t->timerOcAAction << COM00_BIT ));
			TIMSK_REG = ((TIMSK_REG & 0xFC)   | (ST_ptrCfgInstance_t->timerInterruptStates << TOIE0_BIT ));

			tmrRet = MTMR_setAddressOfCallback(ST_ptrCfgInstance_t);
			break;
		}
		case MTMR_TIMER_1_Channel:
		{

			TCCR1A_REG = ((TCCR1A_REG & 0xFC)   | (ST_ptrCfgInstance_t->timerMode << WGM10_BIT ));
			TCCR1B_REG = ((TCCR1B_REG & 0xE7)   | ((ST_ptrCfgInstance_t->timerMode >> 2) << WGM12_BIT ));

			TCCR1A_REG = ((TCCR1A_REG & 0x3F)   | (ST_ptrCfgInstance_t->timerOcAAction << COM1A0_BIT ));
			TCCR1A_REG = ((TCCR1A_REG & 0xCF)   | (ST_ptrCfgInstance_t->timerOcBAction << COM1B0_BIT ));

			TIMSK_REG  = ((TIMSK_REG & 0xC3)   	| (ST_ptrCfgInstance_t->timerInterruptStates << TOIE1_BIT ));


			tmrRet = MTMR_setAddressOfCallback(ST_ptrCfgInstance_t);
			break;
		}
		case MTMR_TIMER_2_Channel:
		{

			TCCR2_REG = ((TCCR2_REG & 0xBF)   | (ST_ptrCfgInstance_t->timerMode << WGM20_BIT ));
			TCCR2_REG = ((TCCR2_REG & 0xF7)   | ((ST_ptrCfgInstance_t->timerMode >> 1) << WGM21_BIT ));
			TCCR2_REG = ((TCCR2_REG & 0xCF)   | (ST_ptrCfgInstance_t->timerOcAAction << COM20_BIT ));
			TIMSK_REG = ((TIMSK_REG & 0xFC)   | (ST_ptrCfgInstance_t->timerInterruptStates << TOIE2_BIT ));

			tmrRet = MTMR_setAddressOfCallback(ST_ptrCfgInstance_t);

			break;
		}
		default :
		{

			tmrRet = MTMR_INVALID_PARAMTER;
			break;
		}
		}
	}
	else
	{
		tmrRet = MTMR_PTR_NULL;
	}
	return tmrRet;
}


EN_MTMR_systemState_t   MTMR_start(ST_MTMR_cfg_t const *ST_ptrCfgInstance_t)
{
	EN_MTMR_systemState_t tmrRet = MTMR_NOK;

	if(PTR_NULL != ST_ptrCfgInstance_t)
	{

		switch(ST_ptrCfgInstance_t->timerChannel)
		{
		case MTMR_TIMER_0_Channel:
		{
			TCCR0_REG = ((TCCR0_REG & 0xF8)   | (ST_ptrCfgInstance_t->timerClk  << CS00_BIT ));
			tmrRet = MTMR_OK;

			break;
		}
		case MTMR_TIMER_1_Channel:
		{

			TCCR1B_REG = ((TCCR1B_REG & 0xF8)   | (ST_ptrCfgInstance_t->timerClk << CS10_BIT ));
			tmrRet = MTMR_OK;
			break;
		}
		case MTMR_TIMER_2_Channel:
		{
			TCCR2_REG = ((TCCR2_REG & 0xF8)   | (ST_ptrCfgInstance_t->timerClk  << CS20_BIT ));
			tmrRet = MTMR_OK;
			break;
		}
		default :
		{

			tmrRet = MTMR_INVALID_PARAMTER;
			break;
		}
		}


	}
	else
	{
		tmrRet = MTMR_PTR_NULL;
	}

	return tmrRet;
}


EN_MTMR_systemState_t   MTMR_stop(ST_MTMR_cfg_t const *ST_ptrCfgInstance_t)
{
	EN_MTMR_systemState_t tmrRet = MTMR_NOK;

	if(PTR_NULL != ST_ptrCfgInstance_t)
	{

		switch(ST_ptrCfgInstance_t->timerChannel)
		{
		case MTMR_TIMER_0_Channel:
		{

			TCCR0_REG = ((TCCR0_REG & 0xF8)   | (MTMR_NO_CLK_PRESCALER  << CS00_BIT ));
			tmrRet = MTMR_OK;
			break;
		}
		case MTMR_TIMER_1_Channel:
		{
			TCCR1B_REG = ((TCCR1B_REG & 0xF8)   | (MTMR_NO_CLK_PRESCALER << CS10_BIT ));
			tmrRet = MTMR_OK;
			break;
		}
		case MTMR_TIMER_2_Channel:
		{
			TCCR2_REG = ((TCCR2_REG & 0xF8)   | (MTMR_NO_CLK_PRESCALER  << CS20_BIT ));
			tmrRet = MTMR_OK;
			break;
		}
		default :
		{
			tmrRet = MTMR_INVALID_PARAMTER;
			break;
		}
		}
	}
	else
	{
		tmrRet = MTMR_PTR_NULL;
	}

	return tmrRet;
}

EN_MTMR_systemState_t   MTMR_readTcnt(ST_MTMR_cfg_t const *ST_ptrCfgInstance_t , Uint16_t *retOfTcntValue)
{
	EN_MTMR_systemState_t tmrRet = MTMR_NOK;

	if(PTR_NULL != ST_ptrCfgInstance_t)
	{

		switch(ST_ptrCfgInstance_t->timerChannel)
		{
		case MTMR_TIMER_0_Channel:
		{

			*retOfTcntValue = TCNT0_REG;
			tmrRet = MTMR_OK;
			break;
		}
		case MTMR_TIMER_1_Channel:
		{
			*retOfTcntValue = TCNT1_REG;
			tmrRet = MTMR_OK;
			break;
		}
		case MTMR_TIMER_2_Channel:
		{
			*retOfTcntValue = TCNT2_REG;
			tmrRet = MTMR_OK;
			break;
		}
		default :
		{
			tmrRet = MTMR_INVALID_PARAMTER;
			break;
		}
		}
	}
	else
	{
		tmrRet = MTMR_PTR_NULL;
	}

	return tmrRet;
}

EN_MTMR_systemState_t   MTMR_writeTcntPreload(ST_MTMR_cfg_t const *ST_ptrCfgInstance_t , Uint16_t tcntPreloadValue)
{
	EN_MTMR_systemState_t tmrRet = MTMR_NOK;

	if(PTR_NULL != ST_ptrCfgInstance_t)
	{
		switch(ST_ptrCfgInstance_t->timerChannel)
		{
		case MTMR_TIMER_0_Channel:
		{

			TCNT0_REG = (uint8_t)tcntPreloadValue;
			tmrRet = MTMR_OK;
			break;
		}
		case MTMR_TIMER_1_Channel:
		{
			TCNT1_REG = tcntPreloadValue;
			tmrRet = MTMR_OK;
			break;
		}
		case MTMR_TIMER_2_Channel:
		{
			TCNT2_REG = (uint8_t)tcntPreloadValue;
			tmrRet = MTMR_OK;
			break;
		}
		default :
		{
			tmrRet = MTMR_INVALID_PARAMTER;
			break;
		}
		}
	}
	else
	{
		tmrRet = MTMR_PTR_NULL;
	}

	return tmrRet;
}


EN_MTMR_systemState_t   MTMR_readOcr(ST_MTMR_cfg_t const *ST_ptrCfgInstance_t , Uint16_t *retOfOcrAValue , Uint16_t *retOfOcrBValue)
{
	EN_MTMR_systemState_t tmrRet = MTMR_NOK;

	if(PTR_NULL != ST_ptrCfgInstance_t)
	{

		switch(ST_ptrCfgInstance_t->timerChannel)
		{
		case MTMR_TIMER_0_Channel:
		{

			*retOfOcrAValue = OCR0_REG;
			*retOfOcrBValue = PTR_NULL;
			tmrRet = MTMR_OK;
			break;
		}
		case MTMR_TIMER_1_Channel:
		{
			*retOfOcrAValue = OCR1A_REG;
			*retOfOcrBValue = OCR1B_REG;
			tmrRet = MTMR_OK;
			break;
		}
		case MTMR_TIMER_2_Channel:
		{
			*retOfOcrAValue = OCR2_REG;
			*retOfOcrBValue = PTR_NULL;
			tmrRet = MTMR_OK;
			break;
		}
		default :
		{

			tmrRet = MTMR_INVALID_PARAMTER;
			break;
		}
		}
	}
	else
	{
		tmrRet = MTMR_PTR_NULL;
	}

	return tmrRet;
}


ISR(TIM0_OVF_INT)
{
	if(PTR_NULL != ptr_IsrCallingForOvfTmr0)
		ptr_IsrCallingForOvfTmr0();
	else
		/* Do Nothing */;
}

ISR(TIM0_COMP_INT)
{
	if(PTR_NULL != ptr_IsrCallingForOcTmr0)
		ptr_IsrCallingForOcTmr0();
	else
		/* Do Nothing */;
}

ISR(TIM1_OVF_INT)
{
	if(PTR_NULL != ptr_IsrCallingForOvfTmr1)
		ptr_IsrCallingForOvfTmr1();
	else
		/* Do Nothing */;
}

ISR(TIM1_COMPA_INT)
{
	if(PTR_NULL != ptr_IsrCallingForOcATmr1)
		ptr_IsrCallingForOcATmr1();
	else
		/* Do Nothing */;
}

ISR(TIM1_COMPB_INT)
{
	if(PTR_NULL != ptr_IsrCallingForOcBTmr1)
		ptr_IsrCallingForOcBTmr1();
	else
		/* Do Nothing */;
}

ISR(TIM1_CAPT_INT)
{
	if(PTR_NULL != ptr_IsrCallingForIcuTmr1)
		ptr_IsrCallingForIcuTmr1();
	else
		/* Do Nothing */;
}

ISR(TIM2_OVF_INT)
{
	if(PTR_NULL != ptr_IsrCallingForOvfTmr2)
		ptr_IsrCallingForOvfTmr2();
	else
		/* Do Nothing */;
}

ISR(TIM2_COMP_INT)
{
	if(PTR_NULL != ptr_IsrCallingForOcTmr2)
		ptr_IsrCallingForOcTmr2();
	else
		/* Do Nothing */;
}



