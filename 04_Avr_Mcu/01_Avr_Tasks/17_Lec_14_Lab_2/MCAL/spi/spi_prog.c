/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : spi_prog.c                                  	     
// Date          : 21 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/


#include "spi_interface.h"


EN_MSPI_systemState_t MSPI_init(ST_MSPI_cfg_t const *ST_ptrSpiCfgInstance)
{
	EN_MSPI_systemState_t spiRet = MSPI_NOK;
	EN_GPIO_systemState_t gpioRet = GPIO_NOK;

	if(PTR_NULL != ST_ptrSpiCfgInstance)
	{

		if(ST_ptrSpiCfgInstance->spiDeviceType == MSPI_MASTER)
		{
			ST_GPIO_cfg_t pinCfg =
			{
					.portName = GPIO_PORTB,
					.pinNumber = GPIO_PIN4,
					.pinDirection = GPIO_OUTPUT,
					.logicOnPin = GPIO_LOW
			};

			gpioRet = GPIO_initPin(&pinCfg);

			if(gpioRet == GPIO_OK)
			{
				pinCfg.pinNumber = GPIO_PIN5;
				gpioRet = GPIO_initPin(&pinCfg);
			}
			else spiRet = MSPI_NOK;

			if(gpioRet == GPIO_OK)
			{
				pinCfg.pinNumber = GPIO_PIN7;
				gpioRet = GPIO_initPin(&pinCfg);
			}
			else spiRet = MSPI_NOK;

			if(gpioRet == GPIO_OK)
			{
				pinCfg.pinNumber = GPIO_PIN6;
				pinCfg.pinDirection = GPIO_INPUT;
				gpioRet = GPIO_initPin(&pinCfg);
			}
			else spiRet = MSPI_NOK;
		}
		else if(ST_ptrSpiCfgInstance->spiDeviceType == MSPI_SLAVE)
		{
			ST_GPIO_cfg_t pinCfg =
			{
					.portName = GPIO_PORTB,
					.pinNumber = GPIO_PIN4,
					.pinDirection = GPIO_INPUT,
					.logicOnPin = GPIO_LOW
			};

			gpioRet = GPIO_initPin(&pinCfg);

			if(gpioRet == GPIO_OK)
			{
				pinCfg.pinNumber = GPIO_PIN5;
				gpioRet = GPIO_initPin(&pinCfg);
			}
			else spiRet = MSPI_NOK;

			if(gpioRet == GPIO_OK)
			{
				pinCfg.pinNumber = GPIO_PIN7;
				gpioRet = GPIO_initPin(&pinCfg);
			}
			else spiRet = MSPI_NOK;

			if(gpioRet == GPIO_OK)
			{
				pinCfg.pinNumber = GPIO_PIN6;
				pinCfg.pinDirection = GPIO_OUTPUT;
				gpioRet = GPIO_initPin(&pinCfg);
			}
			else spiRet = MSPI_NOK;
		}
		else
		{
			/* Do Nothing */
		}

		  SPCR_REG = ((SPCR_REG & 0x7F) | (ST_ptrSpiCfgInstance->spiInterruptStates << SPIE_BIT));
		  SPCR_REG = ((SPCR_REG & 0xDF) | (ST_ptrSpiCfgInstance->spiDataOrder << DORD_BIT));
		  SPCR_REG = ((SPCR_REG & 0xEF) | (ST_ptrSpiCfgInstance->spiDeviceType << MSTR_BIT));
		  SPCR_REG = ((SPCR_REG & 0xF7) | (ST_ptrSpiCfgInstance->spiClkPolarity << CPOL_BIT));
		  SPCR_REG = ((SPCR_REG & 0xFC) | (ST_ptrSpiCfgInstance->spiClkRate << SPR0_BIT));
		  SPCR_REG = ((SPCR_REG & 0xFB) | (ST_ptrSpiCfgInstance->spiCphaFunctionality << CPHA_BIT));

		  SPSR_REG = ((SPSR_REG & 0xFE) | ((ST_ptrSpiCfgInstance->spiClkRate >> 2) << SPI2X_BIT));

		spiRet = MSPI_OK;
	}
	else
	{
		spiRet = MSPI_PTR_NULL;
	}

	return spiRet;
}

EN_MSPI_systemState_t MSPI_enable(void)
{
	EN_MSPI_systemState_t spiRet = MSPI_NOK;

	SPCR_REG = ((SPCR_REG & 0xBF) | (MSPI_ENABLE  << SPE_BIT));
	spiRet = MSPI_OK;
	return spiRet;
}
EN_MSPI_systemState_t MSPI_disable(void)
{
	EN_MSPI_systemState_t spiRet = MSPI_NOK;

	SPCR_REG = ((SPCR_REG & 0xBF) | (MSPI_DISABLE  << SPE_BIT));
	spiRet = MSPI_OK;
	return spiRet;
}


EN_MSPI_systemState_t MSPI_recive(uint8_t *retOfData)
{
	  EN_MSPI_systemState_t spiRet = MSPI_NOK;

	  while(GET_BIT(SPSR_REG,SPIF_BIT) != 1);
	  *retOfData = SPDR_REG;
	  spiRet = MSPI_OK;
	  return spiRet;
}


EN_MSPI_systemState_t MSPI_send(uint8_t DataToSend)
{
  EN_MSPI_systemState_t spiRet = MSPI_NOK;
  SPDR_REG = DataToSend;
  while(GET_BIT(SPSR_REG,SPIF_BIT) != 1);
  spiRet = MSPI_OK;
  return spiRet;
}
