/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : adc_prog.c                                  	     
// Date          : 15 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "adc_interface.h"

#define MADC_enable()			SET_BIT(ADCSRA_REG,ADEN_BIT)

#define MADC_disable()			CLR_BIT(ADCSRA_REG,ADEN_BIT)

#define MADC_interruptDisable() CLR_BIT(ADCSRA_REG , ADIE_BIT);


static void(*ptrCallbackHandler)(void) = PTR_NULL;

EN_MADC_systeamState_t MADC_init(ST_MADC_CFG_t const * ST_ptrAdcCfgInstance_t)
{
	EN_MADC_systeamState_t adcRet = MADC_NOK;

	if(PTR_NULL != ST_ptrAdcCfgInstance_t)
	{
		uint8_t ADMUX_REG_TEMP = 0;
		uint8_t ADCSRA_REG_TEMP = 0;

		// disable adc
		MADC_disable();

		// select vref
		ADMUX_REG_TEMP = ((ADMUX_REG_TEMP & 0x3F)   | (ST_ptrAdcCfgInstance_t->referenceSource << REFS0_BIT ));
		// select adjust result
		ADMUX_REG_TEMP = ((ADMUX_REG_TEMP & 0xDF)   | (ST_ptrAdcCfgInstance_t->resultAdjust << ADLAR_BIT));
		// select adc channel
		ADMUX_REG_TEMP = ((ADMUX_REG_TEMP & 0xE0)   | (ST_ptrAdcCfgInstance_t->channelSelection));
		// select prescaler
		ADCSRA_REG_TEMP = ((ADCSRA_REG_TEMP & 0xF8) | (ST_ptrAdcCfgInstance_t->prescalerDivision));
		// enable or disable interrupt
		ADCSRA_REG_TEMP = ((ADCSRA_REG_TEMP & 0xF7) | (ST_ptrAdcCfgInstance_t->triggerSource << ADIE_BIT));

		// assign the values in registers
		ADMUX_REG	 = ADMUX_REG_TEMP;
		ADCSRA_REG 	 = ADCSRA_REG_TEMP;

		// set pointer of isr callback

		ptrCallbackHandler = ST_ptrAdcCfgInstance_t->MADC_setCallback;

		// enable adc
		MADC_enable();
		adcRet = MADC_OK;

	}
	else
	{
		adcRet = MADC_PTR_NULL;
	}
	return adcRet;
}
EN_MADC_systeamState_t MADC_deinit(ST_MADC_CFG_t const * ST_ptrAdcCfgInstance_t)
{
	EN_MADC_systeamState_t adcRet = MADC_NOK;

	if(PTR_NULL != ST_ptrAdcCfgInstance_t)
	{
		// disable adc interrupt
		MADC_interruptDisable();
		// disable adc
		MADC_disable();
		adcRet = MADC_OK;
	}
	else
	{
		adcRet = MADC_PTR_NULL;
	}
	return adcRet;
}

EN_MADC_systeamState_t MADC_startConversion(ST_MADC_CFG_t const * ST_ptrAdcCfgInstance_t)
{
	EN_MADC_systeamState_t adcRet = MADC_NOK;

	if(PTR_NULL != ST_ptrAdcCfgInstance_t)
	{
		// start conversion
		SET_BIT(ADCSRA_REG,ADSC_BIT);
		adcRet = MADC_OK;
	}
	else
	{
		adcRet = MADC_PTR_NULL;
	}
	return adcRet;
}

EN_MADC_systeamState_t MADC_getConversionResult(ST_MADC_CFG_t const * ST_ptrAdcCfgInstance_t, Uint16_t *_ConversionResult)
{
	EN_MADC_systeamState_t adcRet = MADC_NOK;

	if( (PTR_NULL != ST_ptrAdcCfgInstance_t) && (PTR_NULL != _ConversionResult) )
	{
		// polling on adc flag
		while(GET_BIT(ADCSRA_REG,ADIF_BIT) != 1);
		// clear adc flag
		SET_BIT(ADCSRA_REG,ADIF_BIT);

		switch(ST_ptrAdcCfgInstance_t->resultAdjust)
		{
		case MADC_RIGHT_ADJUST  : *_ConversionResult = (Uint16_t)(ADCL_REG + (ADCH_REG << 8)); adcRet = MADC_OK;  break;
		case MADC_LEFT_ADJUST	:  *_ConversionResult = (Uint16_t)((ADCL_REG + (ADCH_REG << 8))>>6); adcRet = MADC_OK; break;
		default 				: adcRet = MADC_NOK; break;
		}
	}
	else
	{
		adcRet = MADC_PTR_NULL;
	}
	return adcRet;
}


ISR(ADC_INT)
{
	if(PTR_NULL != ptrCallbackHandler)
	{
		ptrCallbackHandler();
	}
	else /*Do Nothing */;
}

