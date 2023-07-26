/*
 * usart_prog.c
 *
 * Created: 23/05/2023 21:22:46
 *  Author: 20101
 */ 

#include "usart_interface.h"

void UART_init(long USART_BAUDRATE)
{
	UCSRB_REG |= (1 << UCSRB_REG_RXEN_BIT) | (1 << UCSRB_REG_TXEN_BIT);/* Turn on transmission and reception */
	UCSRC_REG |= (1 << UCSRC_REG_URSEL_BIT) | (1 << UCSRC_REG_UCSZ0_BIT) | (1 << UCSRC_REG_UCSZ1_BIT);/* Use 8-bit character sizes */
	UBRRL_REG = BAUD_PRESCALE;		/* Load lower 8-bits of the baud rate value */
	UBRRH_REG = (BAUD_PRESCALE >> 8);	/* Load upper 8-bits*/
}
unsigned char UART_RxChar()
{
	while ((UCSRA_REG & (1 << UCSRB_REG_RXCIE_BIT)) == 0);/* Wait till data is received */
	return(UDR_REG);
}
void UART_TxChar(char letter)
{
	while (! (UCSRA_REG & (1<<UCSRB_REG_UDRIE_BIT)));	/* Wait for empty transmit buffer*/
	UDR_REG = letter ;
}
void UART_SendString(char *str)
{
	unsigned char j=0;

	while (str[j]!=0)		/* Send string till null */
	{
		UART_TxChar(str[j]);
		j++;
	}
}
