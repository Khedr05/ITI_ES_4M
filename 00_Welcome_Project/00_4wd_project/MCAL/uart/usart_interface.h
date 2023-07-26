/*
 * usart_interface.h
 *
 * Created: 23/05/2023 21:23:20
 *  Author: 20101
 */ 


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include "../../COMMON/STD_Types.h"
#include "../../COMMON/BIT_Math.h"
#include "usart_private.h"

#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


void UART_init(long USART_BAUDRATE);
unsigned char UART_RxChar();
void UART_TxChar(char letter);
void UART_SendString(char *str);






#endif /* USART_INTERFACE_H_ */
