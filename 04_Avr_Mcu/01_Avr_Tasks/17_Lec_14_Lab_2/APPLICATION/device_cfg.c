/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 19_Lec_14_Lab_2                                    	 
// File          : device_cfg.c                                  	     
// Date          : 2 Sept 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "device_cfg.h"

ST_HLCD_cfg_t myLcd =
{
		.dataPinsMode = HLCD_8_BIT_MODE,
		.dataPort = GPIO_PORTA,
		.controlPort = GPIO_PORTC,
		.rsPin = GPIO_PIN0,
		.rwPin = GPIO_PIN1,
		.enPin = GPIO_PIN2,
		.d0Pin = GPIO_PIN0,
		.d1Pin = GPIO_PIN1,
		.d2Pin = GPIO_PIN2,
		.d3Pin = GPIO_PIN3,
		.d4Pin = GPIO_PIN4,
		.d5Pin = GPIO_PIN5,
		.d6Pin = GPIO_PIN6,
		.d7Pin = GPIO_PIN7
};

ST_MSPI_cfg_t MASTER_spi =
{
		.spiDeviceType = MSPI_MASTER,
		.spiInterruptStates = MSPI_INTERRUPT_DISABLE,
		.spiDataOrder = MSPI_MSB_DATA_ORDER,
		.spiCphaFunctionality = MSPI_CPHA_FUNCTIONALITY_SAMPLE_LEADING_SETUP_TRAILING,
		.spiClkRate = MSPI_CLK_RATE_64,
		.spiClkPolarity = MSPI_CLK_POLARITY_RISING_LEADING_FALLING_TRAILING
};

ST_MSPI_cfg_t SLAVE_spi =
{
		.spiDeviceType = MSPI_SLAVE,
		.spiInterruptStates = MSPI_INTERRUPT_DISABLE,
		.spiDataOrder = MSPI_MSB_DATA_ORDER,
		.spiCphaFunctionality = MSPI_CPHA_FUNCTIONALITY_SAMPLE_LEADING_SETUP_TRAILING,
		.spiClkRate = MSPI_CLK_RATE_64,
		.spiClkPolarity = MSPI_CLK_POLARITY_RISING_LEADING_FALLING_TRAILING
};
