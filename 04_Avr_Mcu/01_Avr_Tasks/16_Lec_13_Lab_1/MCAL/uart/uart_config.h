/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : uart_config.h                                  	     
// Date          : 19 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_UART_UART_CONFIG_H_
#define MCAL_UART_UART_CONFIG_H_


typedef enum
{
	MUART_ONE_STOP_BIT = 0,
	MUART_TWO_STOP_BIT
}EN_MUART_stopBitOfFrame_t;


typedef enum
{
	MUART_PARITY_DISABLED = 0,
	MUART_PARITY_ENABLED_EVEN = 2,
	MUART_PARITY_ENABLED_ODD = 3
}EN_MUART_parityBitOfFrame_t;

typedef enum
{
	MUART_ASYNCHRONOUS_OPERATION = 1,
	MUART_SYNCHRONOUS_OPERATION = 3
}EN_MUART_operationMode_t;

typedef enum
{
	MUART_CHARACTER_SIZE_5_BIT = 0,
	MUART_CHARACTER_SIZE_6_BIT,
	MUART_CHARACTER_SIZE_7_BIT,
	MUART_CHARACTER_SIZE_8_BIT,
	MUART_CHARACTER_SIZE_9_BIT = 7
}EN_MUART_dataSizeOfFrame_t;

typedef enum
{
	MUART_DISABLE_INTERRUPT = 0,
	MUART_ENABLE_INTERRUPT
}EN_MUART_interruptStates_t;

typedef enum
{
	MUART_SPEED_U1X = 0,
	MUART_SPEED_U2X
}EN_MUART_transmitSpeed_t;


typedef enum
{
	MUART_UART_BR1X_2400 = 207,
	MUART_UART_BR1X_4800 = 103,
	MUART_UART_BR1X_9600 = 51,
	MUART_UART_BR1X_38400 = 12
}EN_MUART_baudRateForU1x_t;

typedef enum{
	MUART_UART_BR2X_2400 = 416,
	MUART_UART_BR2X_4800 = 207,
	MUART_UART_BR2X_9600 = 103,
	MUART_UART_BR2X_38400 = 25
}EN_MUART_baudRateForU2x_t;


typedef enum
{
	MUART_OK = 0,
	MUART_NOK,
	MUART_PTR_NULL,
	MUART_INVALID_PARAMTER
}EN_MUART_systeamState_t;

typedef struct
{
	EN_MUART_operationMode_t			operationMode;
	EN_MUART_parityBitOfFrame_t			parityBit;
	EN_MUART_stopBitOfFrame_t			stopBit;
	EN_MUART_dataSizeOfFrame_t			charSize;
	//EN_MUART_interruptStates_t			interruptStatus;
	EN_MUART_transmitSpeed_t			transmissionSpeed;
	EN_MUART_baudRateForU1x_t			baudRate1x;
	EN_MUART_baudRateForU2x_t			baudRate2x;
	//void(*ptr_func_tx_callback)(void);
	//void(*ptr_func_rx_callback)(void);

}ST_MUART_cfg_t;



#endif /* MCAL_UART_UART_CONFIG_H_ */
