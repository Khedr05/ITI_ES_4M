/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : usart_config.h                                  	     
// Date          : Sep 19, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_USART_USART_CONFIG_H_
#define MCAL_USART_USART_CONFIG_H_


#define MUSART_PERIPHERAL_CLK		16000000UL
#define MUASRT_ENABLE				1


typedef enum
{
	MUSART_OK = 0,
	MUSART_NOK,
	MUSART_INVALID_PARAMTER,
	MUSART_PTR_NULL
}EN_MUSART_systeamState_t;


typedef enum
{
	MUSART_NUMBER_ONE = 0,
	MUSART_NUMBER_TWO,
	MUSART_NUMBER_THREE
}EN_MUSART_uartNumber_t;

typedef enum
{
	MUSART_SAMPLING_BY_16 = 0,
	MUSART_SAMPLING_BY_8
}EN_MUSART_samplingModeOptions_t;

typedef enum
{
	MUSART_BUAD_RATE_1200_bps = 1200,
	MUSART_BUAD_RATE_2400_bps = 2400,
	MUSART_BUAD_RATE_9600_bps = 9600,
	MUSART_BUAD_RATE_19200_bps = 19200,
	MUSART_BUAD_RATE_38400_bps = 38400,
	MUSART_BUAD_RATE_57600_bps = 57600,
	MUSART_BUAD_RATE_115200_bps = 115200,
	MUSART_BUAD_RATE_230400_bps = 230400,
	MUSART_BUAD_RATE_460800_bps = 460800,
	MUSART_BUAD_RATE_921600_bps = 921600,
	MUSART_BUAD_RATE_1792000_bps = 1792000,
	MUSART_BUAD_RATE_1843200_bps = 1843200,
	MUSART_BUAD_RATE_3584000_bps = 3584000,
	MUSART_BUAD_RATE_3686400_bps = 3686400,
	MUSART_BUAD_RATE_7168000_bps = 7168000,
	MUSART_BUAD_RATE_7372800_bps = 7372800,
	MUSART_BUAD_RATE_9000000_bps = 9000000,
	MUSART_BUAD_RATE_10500000_bps = 10500000,

}EN_MUSART_baudRateOptions_t;


typedef enum
{
	MUSART_RECEIVE_ENABLED = 1,
	MUSART_TRANSMIT_ENABLED,
	MUSART_ENABLE_BOTH
}EN_MUSART_uartEnableOption_t;

typedef enum
{
	MUSART_DISABLE_BOTH = 0,
	MUSART_TRANSMIT_DISABLED,
	MUSART_RECEIVE_DISABLED
}EN_MUSART_uartDisableOption_t;

typedef enum
{
	MUSART_ONE_STOP_BIT = 0,
	MUSART_HALF_STOP_BIT,
	MUSART_TWO_STOP_BIT
}EN_MUSART_stopBitOption_t;

typedef enum
{
	MUSART_PARITY_DISABLED = 0,
	MUSART_PARITY_ENABLED,
}EN_MUSART_parityControlOption_t;

typedef enum
{
	MUSART_EVEN_PARITY = 0,
	MUSART_ODD_PARITY,
}EN_MUSART_paritySelectionOption_t;

typedef enum
{
	MUSART_DATA_SIZE_8_BIT = 0,
	MUSART_DATA_SIZE_9_BIT
}EN_MUSART_dataSizeOptions_t;

typedef struct
{
	EN_MUSART_uartNumber_t				copy_uddtUartNumber;
	EN_MUSART_samplingModeOptions_t		copy_uddtSamplingModeOption;
	EN_MUSART_baudRateOptions_t			copy_uddtBuadRateOption;
	EN_MUSART_dataSizeOptions_t 		copy_uddtDataSizeOption;
	EN_MUSART_parityControlOption_t     copy_uddtParityControl;
	EN_MUSART_paritySelectionOption_t   copy_uddtParitySelection;
	EN_MUSART_stopBitOption_t			copy_uddtStopBitSelection;

}ST_MUSART_cfg_t;

#endif /* MCAL_USART_USART_CONFIG_H_ */
