/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : uart_prog.c                                  	     
// Date          : 19 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "uart_interface.h"


EN_MUART_systeamState_t  MUART_init(ST_MUART_cfg_t const *ST_ptrUartCfgInstance_t)
{
	EN_MUART_systeamState_t uartRet = MUART_NOK;

	if(PTR_NULL != ST_ptrUartCfgInstance_t)
	{
		UCSRC_REG = (  (UCSRC_REG & 0x3F ) | (ST_ptrUartCfgInstance_t->operationMode << URSEL_BIT));
		UCSRC_REG = (  (UCSRC_REG & 0xCF ) | (ST_ptrUartCfgInstance_t->parityBit << UPM0_BIT));
		UCSRC_REG = (  (UCSRC_REG & 0xF7 ) | (ST_ptrUartCfgInstance_t->stopBit << USBS_BIT));
		UCSRC_REG = (  (UCSRC_REG & 0xF8 ) | (ST_ptrUartCfgInstance_t->charSize << UCSZ0_BIT));
		//UCSRA_REG = (  (UCSRA_REG & 0xFD ) | (ST_ptrUartCfgInstance_t->transmissionSpeed << U2X_BIT));

		if(ST_ptrUartCfgInstance_t->transmissionSpeed == MUART_SPEED_U1X)
		{
			  CLR_BIT(UCSRA_REG,U2X_BIT);
			  CLR_BIT(UCSRC_REG,URSEL_BIT);
			  UBRRL_REG = ST_ptrUartCfgInstance_t->baudRate1x;
			  UBRRH_REG = ((ST_ptrUartCfgInstance_t->baudRate1x)>>8);
			  uartRet = MUART_OK;
		}
		else
		{
			  SET_BIT(UCSRA_REG,U2X_BIT);
			  CLR_BIT(UCSRC_REG,URSEL_BIT);
			  UBRRL_REG = ST_ptrUartCfgInstance_t->baudRate2x;
			  UBRRH_REG = ((ST_ptrUartCfgInstance_t->baudRate2x)>>8);
			  uartRet = MUART_OK;
		}

	}
	else
	{
		uartRet = MUART_PTR_NULL;
	}

	return uartRet;
}

EN_MUART_systeamState_t MUART_enable(void)
{
	EN_MUART_systeamState_t uartRet = MUART_NOK;
	SET_BIT(UCSRB_REG,RXEN_BIT);
	SET_BIT(UCSRB_REG,TXEN_BIT);
	uartRet = MUART_OK;
	return uartRet;
}



EN_MUART_systeamState_t MUART_receiveData(uint8_t *retOfRecivedData){

	EN_MUART_systeamState_t uartRet = MUART_NOK;
	while( GET_BIT(UCSRA_REG,RXC_BIT) != 1 );
	*retOfRecivedData = UDR_REG;
	CLR_BIT(UCSRA_REG,RXC_BIT);
	uartRet = MUART_OK;
	return uartRet;
}

EN_MUART_systeamState_t MUART_sendData(uint8_t u8DataToSend){

	EN_MUART_systeamState_t uartRet = MUART_NOK;
	while( GET_BIT(UCSRA_REG,UDRE_BIT) != 1 );
	UDR_REG = u8DataToSend;
	uartRet = MUART_OK;
	return uartRet;
}




