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


EN_MUSART_systeamState_t MUSART_uddtInit(ST_MUSART_cfg_t const *PS_uddtUartCfg);

EN_MUSART_systeamState_t MUSART_uddtEnable(EN_MUSART_uartNumber_t copy_uddtUartNumber , EN_MUSART_uartEnableOption_t copy_uddtUartEnableOption);

EN_MUSART_systeamState_t MUSART_uddtDisable(EN_MUSART_uartNumber_t copy_uddtUartNumber , EN_MUSART_uartDisableOption_t copy_uddtUartDisableOption);

EN_MUSART_systeamState_t MUSART_uddtSend(uint8_t *copy_u32DataToSend);

EN_MUSART_systeamState_t MUSART_uddtReceive(uint8_t *copy_u32DataToReceive);

EN_MUSART_systeamState_t MUSART_uddtSendBlocking(uint8_t *copy_u8DataToSend);

EN_MUSART_systeamState_t MUSART_uddtReceiveBlocking(uint8_t *copy_u8DataToReceive);


#endif /* MCAL_USART_USART_INTERFACE_H_ */
