/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : spi_prog.c                                  	     
// Date          : Sep 20, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/MCAL/spi/spi_interface.h"


EN_MSPI_systeamState_t MSPI_uddtInit(ST_MSPI_cfg_t const *PS_uddtSpiCfg)
{
	EN_MSPI_systeamState_t ret = MSPI_NOK;
	if(PTR_NULL != PS_uddtSpiCfg)
	{
		MSPI1_PERIPHERAL->MSPI_CR1 = ((MSPI1_PERIPHERAL->MSPI_CR1 & 0x0000)
				|(PS_uddtSpiCfg->cpolSelect << CPOL_BIT)
				|(PS_uddtSpiCfg->cphaSelect << CPHA_BIT)
				|(PS_uddtSpiCfg->deviceRole << MSTR_BIT)
				//|(PS_uddtSpiCfg->buadRate << BR0_BIT)
				|(PS_uddtSpiCfg->frameFormatSelection << LSBFIRST_BIT)
				|(PS_uddtSpiCfg->ssiSelect << SSI_BIT)
				|(PS_uddtSpiCfg->ssmSelect << SSM_BIT)
				|(PS_uddtSpiCfg->dataFrameFormatSelection << DFF_BIT)
				|(PS_uddtSpiCfg->statusOfSpi << SPE_BIT));
	}
	else
	{
		ret = MSPI_PTR_NULL;
	}

	return ret;
}

EN_MSPI_systeamState_t MSPI_uddtSendBlocking(uint8_t copy_u8DataToSend)
{
	EN_MSPI_systeamState_t ret = MSPI_NOK;

	MSPI1_PERIPHERAL->MSPI_DR = (vuint32_t )copy_u8DataToSend;
	while(GET_BIT(MSPI1_PERIPHERAL->MSPI_SR ,BSY_BIT) == 1);

	ret = MSPI_OK;

	return ret;
}


EN_MSPI_systeamState_t MSPI_uddtReceiveBlocking(uint8_t *copy_u8DataToReceive)
{
	EN_MSPI_systeamState_t ret = MSPI_NOK;
	if(PTR_NULL != copy_u8DataToReceive)
	{
		while(GET_BIT(MSPI1_PERIPHERAL->MSPI_SR ,BSY_BIT) == 1);
		*copy_u8DataToReceive = MSPI1_PERIPHERAL->MSPI_DR;
	}
	else
	{
		ret = MSPI_PTR_NULL;
	}
	return ret;
}
