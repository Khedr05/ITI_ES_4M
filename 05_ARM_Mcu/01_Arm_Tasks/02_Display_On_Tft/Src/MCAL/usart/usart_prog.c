/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : usart_prog.c                                  	     
// Date          : Sep 19, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/MCAL/usart/usart_interface.h"


EN_MUSART_systeamState_t MUSART_uddtInit(ST_MUSART_cfg_t const *PS_uddtUartCfg)
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;
	MGPIO_setPinMode(MGPIO_PORTB,MGPIO_PIN6, MGPIO_MODE_ALTF);
	MGPIO_setPinMode(MGPIO_PORTB,MGPIO_PIN7, MGPIO_MODE_ALTF);
	MGPIO_SetAltFun(MGPIO_PORTB,MGPIO_PIN6,MGPIO_ALTFN_7);
	MGPIO_SetAltFun(MGPIO_PORTB,MGPIO_PIN7,MGPIO_ALTFN_7);
	if(PTR_NULL != PS_uddtUartCfg)
	{
		//float64_t loc_f64UsartDiv = 0;
		//float32_t loc_f32UsartFrac = 0;
		float64_t loc_f64UsartDiv = (float64_t)MUSART_PERIPHERAL_CLK / (8*(2-PS_uddtUartCfg->copy_uddtSamplingModeOption) * PS_uddtUartCfg->copy_uddtBuadRateOption);
		float64_t loc_f32UsartFrac = loc_f64UsartDiv - (int)loc_f64UsartDiv;

		if(loc_f32UsartFrac > 0)
		{
			loc_f32UsartFrac *=16;
			loc_f32UsartFrac = (loc_f32UsartFrac - (int)loc_f32UsartFrac)>=0.5 ? (int)loc_f32UsartFrac+1 : (int)loc_f32UsartFrac;
		}

		switch(PS_uddtUartCfg->copy_uddtUartNumber)
		{
			case MUSART_NUMBER_ONE:
			{

				MUART1_PERIPHERAL->MUSART_BRR = loc_f32UsartFrac;
				MUART1_PERIPHERAL->MUSART_BRR |= ((int)loc_f64UsartDiv << MUSART_DIV_MANTISSA0_BIT);


				MUART1_PERIPHERAL->MUSART_CR2 = ((MUART1_PERIPHERAL->MUSART_CR2 & 0b0000000000000000)
												|(PS_uddtUartCfg->copy_uddtStopBitSelection  << MUSART_STOP0_BIT));

				MUART1_PERIPHERAL->MUSART_CR3 = 0b0000000000000000;

				MUART1_PERIPHERAL->MUSART_CR1 = ((MUART1_PERIPHERAL->MUSART_CR1 & 0b0000000000000000)
						| (PS_uddtUartCfg->copy_uddtSamplingModeOption << MUSART_OVER8_BIT)
						| (PS_uddtUartCfg->copy_uddtDataSizeOption  << MUSART_M_BIT)
						| (PS_uddtUartCfg->copy_uddtParityControl   << MUSART_PCE_BIT)
						| (PS_uddtUartCfg->copy_uddtParitySelection << MUSART_PS_BIT)
						| (MUASRT_ENABLE << MUSART_UE_BIT));



				break;
			}
		}
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}

	return ret;
}

EN_MUSART_systeamState_t MUSART_uddtEnable(EN_MUSART_uartNumber_t copy_uddtUartNumber , EN_MUSART_uartEnableOption_t copy_uddtUartEnableOption)
{

	switch(copy_uddtUartNumber)
	{
		case MUSART_NUMBER_ONE :
		{

			MUART1_PERIPHERAL->MUSART_CR1 = ((MUART1_PERIPHERAL->MUSART_CR1 & 0xFF3) | (copy_uddtUartEnableOption << MUSART_RE_BIT));
			break;
		}
	}

}

EN_MUSART_systeamState_t MUSART_uddtDisable(EN_MUSART_uartNumber_t copy_uddtUartNumber , EN_MUSART_uartDisableOption_t copy_uddtUartDisableOption)
{
	switch(copy_uddtUartNumber)
	{
		case MUSART_NUMBER_ONE :
		{

			MUART1_PERIPHERAL->MUSART_CR1 = ((MUART1_PERIPHERAL->MUSART_CR1 & 0xFF3) | (copy_uddtUartDisableOption << MUSART_RE_BIT));
			break;
		}
	}
}

EN_MUSART_systeamState_t MUSART_uddtSend(uint8_t *copy_u32DataToSend)
{

}

EN_MUSART_systeamState_t MUSART_uddtReceive(uint8_t *copy_u32DataToReceive)
{

}

EN_MUSART_systeamState_t MUSART_uddtSendBlocking(uint8_t *copy_u8DataToSend)
{
	while(GET_BIT(MUART1_PERIPHERAL->MUSART_SR , MUSART_TXE_BIT) == 0);
	CLR_BIT(MUART1_PERIPHERAL->MUSART_SR , MUSART_TXE_BIT);
	MUART1_PERIPHERAL->MUSART_DR = (vuint32_t)copy_u8DataToSend;
	while(GET_BIT(MUART1_PERIPHERAL->MUSART_SR , MUSART_TC_BIT) == 0);
	CLR_BIT(MUART1_PERIPHERAL->MUSART_SR , MUSART_TC_BIT);

}

EN_MUSART_systeamState_t MUSART_uddtReceiveBlocking(uint8_t *copy_u8DataToReceive)
{
	while(GET_BIT(MUART1_PERIPHERAL->MUSART_SR , MUSART_RXNE_BIT) == 0);

	*copy_u8DataToReceive = MUART1_PERIPHERAL->MUSART_DR;
}
