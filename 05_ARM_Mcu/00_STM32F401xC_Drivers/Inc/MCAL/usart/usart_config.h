/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : usart_config.h                                  	     
// Date          : Sep 19, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_USART_USART_CONFIG_H_
#define MCAL_USART_USART_CONFIG_H_

#define THRESHOLD_VALUE		50000
#define __PCLK__	        8000000UL

#define MUSART_ENABLE				1
#define MUSART_DISABLE				0

typedef enum
{
	MUSART_NOK = 0,
	MUSART_OK,
	MUSART_PTR_NULL
}EN_MUSART_systeamState_t;


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
	MUSART_TX_ONLY = 0,
	MUSART_RX_ONLY,
	MUSART_TX_RX
}EN_MUSART_transferControl_t;

typedef enum
{
	MUSART_ONE_STOP_BIT = 0,
	MUSART_HALF_STOP_BIT,
	MUSART_TWO_STOP_BIT,
	MUSART_ONE_AND_HALF_BIT
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
	uint8_t clockOutput;
	uint8_t clockPolarity;
	uint8_t clockPhase;
	uint8_t lastBitClockPulse;
}ST_MUSART_clockInit_t;

typedef struct
{
	EN_MUSART_transferControl_t         copy_uddtTransferDirection;
	EN_MUSART_samplingModeOptions_t		copy_uddtSamplingModeOption;
	EN_MUSART_baudRateOptions_t			copy_uddtBuadRateOption;
	EN_MUSART_dataSizeOptions_t 		copy_uddtDataSizeOption;
	EN_MUSART_parityControlOption_t     copy_uddtParityControl;
	EN_MUSART_paritySelectionOption_t   copy_uddtParitySelection;
	EN_MUSART_stopBitOption_t			copy_uddtStopBitSelection;
	uint8_t								copy_HardwareFlowControl;
	ST_MUSART_clockInit_t				copy_uddtUartClockInit;

}ST_MUSART_cfg_t;




#endif /* MCAL_USART_USART_CONFIG_H_ */
