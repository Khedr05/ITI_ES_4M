/*
 * bluetooth_interface.h
 *
 * Created: 19/07/2023 21:10:04
 *  Author: 20101
 */ 


#ifndef BLUETOOTH_INTERFACE_H_
#define BLUETOOTH_INTERFACE_H_


#include "../../MCAL/uart/usart_interface.h"


void BLUETOOTH_init(void);
Uint8_t BLUETOOTH_ReceiveData(void);
void BLUETOOTH_vSendData(Uint8_t LOCAL_Uint8_tData);
void BLUETOOTH_send(Uint8_t *data_to_send);




#endif /* BLUETOOTH_INTERFACE_H_ */
