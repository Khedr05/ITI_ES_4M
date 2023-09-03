/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : spi_config.h                                  	     
// Date          : 21 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_


typedef enum
{
	MSPI_OK = 0,
	MSPI_NOK,
	MSPI_PTR_NULL
}EN_MSPI_systemState_t;


typedef enum
{
	MSPI_INTERRUPT_DISABLE = 0,
	MSPI_INTERRUPT_ENABLE
}EN_MSPI_interruptStates_t;

typedef enum
{
	MSPI_MSB_DATA_ORDER = 0,
	MSPI_LSB_DATA_ORDER
}EN_MSPI_dataOrder_t;

typedef enum
{
	MSPI_SLAVE = 0,
	MSPI_MASTER
}EN_MSPI_typeSelect_t;

typedef enum
{
	MSPI_CLK_POLARITY_RISING_LEADING_FALLING_TRAILING = 0,
	MSPI_CLK_POLARITY_FALLING_LEADING_RISING_TRAILING
}EN_MSPI_clockPolarity_t;

typedef enum
{
	MSPI_CPHA_FUNCTIONALITY_SAMPLE_LEADING_SETUP_TRAILING = 0,
	MSPI_CPHA_FUNCTIONALITY_SETUP_LEADING_SAMPLE_TRAILING
}EN_MSPI_Cphafunctionality_t;


typedef enum
{
	MSPI_CLK_RATE_4 = 0,
	MSPI_CLK_RATE_16,
	MSPI_RESERVED,
	MSPI_CLK_RATE_128,
	MSPI_CLK_RATE_2,
	MSPI_CLK_RATE_8,
	MSPI_CLK_RATE_32,
	MSPI_CLK_RATE_64

}EN_MSPI_clockRateSelect_t;


typedef enum
{
	MSPI_DISABLE = 0,
	MSPI_ENABLE
}EN_MSPI_states_t;

typedef struct
{
	EN_MSPI_typeSelect_t 		spiDeviceType;
	EN_MSPI_interruptStates_t   spiInterruptStates;
	EN_MSPI_dataOrder_t			spiDataOrder;
	EN_MSPI_clockPolarity_t     spiClkPolarity;
	EN_MSPI_Cphafunctionality_t spiCphaFunctionality;
	EN_MSPI_clockRateSelect_t	spiClkRate;


}ST_MSPI_cfg_t;

#endif /* MCAL_SPI_SPI_CONFIG_H_ */
