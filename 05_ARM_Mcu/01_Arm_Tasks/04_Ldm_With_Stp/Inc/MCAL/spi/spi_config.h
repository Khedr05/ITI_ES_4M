/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : spi_config.h                                  	     
// Date          : Sep 20, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

typedef enum
{
	MSPI_OK = 0,
	MSPI_NOK,
	MSPI_PTR_NULL
}EN_MSPI_systeamState_t;


typedef enum
{
	MSPI_DFF_8_BIT = 0,
	MSPI_DFF_16_BIT
}EN_MSPI_dataFrame_t;

typedef enum
{
	MSPI_SSM_DISABLED = 0,
	MSPI_SSM_ENABLED
}EN_MSPI_ssmSelect_t;


typedef enum
{
	MSPI_SSI_IS_CLEAR = 0,
	MSPI_SSI_IS_SET
}EN_MSPI_ssiSelect_t;


typedef enum
{
	MSPI_FRAME_MSB = 0,
	MSPI_FRAME_LSB
}EN_MSPI_frameFormat;

typedef enum
{
	MSPI_DISABLE = 0,
	MSPI_ENABLE
}EN_MSPI_statusOfSpi_t;

typedef enum
{
	MSPI_CLK_DIVSION_2 = 0,
	MSPI_CLK_DIVSION_4,
	MSPI_CLK_DIVSION_8,
	MSPI_CLK_DIVSION_16,
	MSPI_CLK_DIVSION_32,
	MSPI_CLK_DIVSION_64,
	MSPI_CLK_DIVSION_128,
	MSPI_CLK_DIVSION_256
}EN_MSPI_buadRateSelect_t;

typedef enum
{
	MSPI_DEVICE_ROLE_SLAVE = 0,
	MSPI_DEVICE_ROLE_MASTER
}EN_MSPI_deviceRole_t;

typedef enum
{
	MSPI_FIRST_CLK_FIRST_DATA_EDGE = 0,
	MSPI_SECOND_CLK_FIRST_DATA_EDGE
}EN_MSPI_cpolSelect_t;

typedef enum
{
	MSPI_CLK_TO_ZERO = 0,
	MSPI_CLK_TO_ONE
}EN_MSPI_cphaSelect_t;


typedef struct
{
	EN_MSPI_cphaSelect_t		cphaSelect;
	EN_MSPI_cpolSelect_t		cpolSelect;
	EN_MSPI_deviceRole_t		deviceRole;
	EN_MSPI_buadRateSelect_t	buadRate;
	EN_MSPI_statusOfSpi_t		statusOfSpi;
	EN_MSPI_frameFormat			frameFormatSelection;
	EN_MSPI_ssiSelect_t			ssiSelect;
	EN_MSPI_ssmSelect_t			ssmSelect;
	EN_MSPI_dataFrame_t			dataFrameFormatSelection;

}ST_MSPI_cfg_t;




#endif /* MCAL_SPI_SPI_CONFIG_H_ */
