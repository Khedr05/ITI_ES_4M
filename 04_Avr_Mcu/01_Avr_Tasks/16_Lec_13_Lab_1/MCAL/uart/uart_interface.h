/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : uart_interface.h                                  	     
// Date          : 19 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_


#include "../../COMMON/std_types.h"
#include "../../COMMON/vector_table.h"
#include "../../COMMON/bit_math.h"
#include "uart_private.h"
#include "uart_config.h"

EN_MUART_systeamState_t MUART_init(ST_MUART_cfg_t const *ST_ptrUartCfgInstance_t);
EN_MUART_systeamState_t MUART_enable(void);
EN_MUART_systeamState_t MUART_receiveData(uint8_t *retOfRecivedData);
EN_MUART_systeamState_t MUART_sendData(uint8_t u8DataToSend);


#endif /* MCAL_UART_UART_INTERFACE_H_ */
