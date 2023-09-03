/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : uart_private.h                                  	     
// Date          : 19 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_


#define UDR_REG			*((vuint8_t *)0x2C)
#define UCSRA_REG		*((vuint8_t *)0x2B)
#define UCSRB_REG		*((vuint8_t *)0x2A)
#define UCSRC_REG		*((vuint8_t *)0x40)
#define UBRRL_REG		*((vuint8_t *)0x29)
#define UBRRH_REG		*((vuint8_t *)0x40)



#define			MPCM_BIT 		0
#define			U2X_BIT			1
#define			PE_BIT			2
#define			DOR_BIT			3
#define			FE_BIT			4
#define			UDRE_BIT		5
#define			TXC_BIT			6
#define			RXC_BIT			7



#define			TXB8_BIT  		0
#define			RXB8_BIT 		1
#define			UCSZ2_BIT		2
#define			TXEN_BIT		3
#define			RXEN_BIT		4
#define			UDRIE_BIT		5
#define			TXCIE_BIT		6
#define			RXCIE_BIT		7



#define			UCPOL_BIT 		0
#define			UCSZ0_BIT		1
#define			UCSZ1_BIT		2
#define			USBS_BIT		3
#define			UPM0_BIT		4
#define			UPM1_BIT		5
#define			UMSEL_BIT		6
#define			URSEL_BIT		7



#endif /* MCAL_UART_UART_PRIVATE_H_ */
