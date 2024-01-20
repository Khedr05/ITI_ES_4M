/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : uart_interface.h                                  	     
// Date          : Sep 19, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "../../COMMON/bit_math.h"
#include "../../MCAL/gpio/gpio_interface.h"
#include "usart_private.h"
#include "usart_config.h"


EN_MUSART_systeamState_t MUSART_uddtInit( ST_MUART_RegistersMap_t *PS_USARTx , ST_MUSART_cfg_t const *PS_uddtUartCfg);
EN_MUSART_systeamState_t MUSART_uddtEnable(ST_MUART_RegistersMap_t *PS_USARTx);
EN_MUSART_systeamState_t MUSART_uddtDisable(ST_MUART_RegistersMap_t *PS_USARTx);
EN_MUSART_systeamState_t MUSART_uddtTransmitByte(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t copy_u8ByteToSend);
EN_MUSART_systeamState_t MUSART_uddtTransmitString(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8StringToSend);
EN_MUSART_systeamState_t MUSART_uddtReadDataRegister(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8ByteToReceive);
EN_MUSART_systeamState_t MUSART_uddtClearFlags(ST_MUART_RegistersMap_t *PS_USARTx);
EN_MUSART_systeamState_t MUSART_uddtReceiveByteSynchNonBlocking(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8ByteToReceive);
EN_MUSART_systeamState_t MUSART_uddtReceiveStringAsynchBlocking (ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8ByteToReceive);
EN_MUSART_systeamState_t MUSART_uddtReceiveStringSynchNonBlocking (ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8ByteToReceive);

EN_MUSART_systeamState_t MUSART_RxIntSetStatus(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t copy_u8Status);
EN_MUSART_systeamState_t MUSART1_uddtSetCallBack( void (*ptr) (void) );
EN_MUSART_systeamState_t MUSART2_uddtSetCallBack( void (*ptr) (void) );
EN_MUSART_systeamState_t MUSART6_uddtSetCallBack( void (*ptr) (void) );


#endif /* MCAL_USART_USART_INTERFACE_H_ */
