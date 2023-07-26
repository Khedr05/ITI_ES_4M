/*
 * bluetooth_prog.c
 *
 * Created: 19/07/2023 21:09:33
 *  Author: 20101
 */ 


#include "bluetooth_interface.h"

void BLUETOOTH_init(void)
{
	UART_init(9600);
}

Uint8_t BLUETOOTH_ReceiveData(void)
{
	Uint8_t data;
	data = UART_RxChar();
	return data;
}
void BLUETOOTH_vSendData(Uint8_t LOCAL_Uint8_tData)
{
	UART_TxChar(LOCAL_Uint8_tData);
}
void BLUETOOTH_send(Uint8_t *data_to_send)
{
	UART_SendString(data_to_send);
}
