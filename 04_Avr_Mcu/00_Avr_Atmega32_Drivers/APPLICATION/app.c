/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 00_Gpio_Driver                                    	 
// File          : app.c                                  	     
// Date          : 31 Jul 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "app.h"


ST_LED_cfg_t led =
{
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN0,
		.ledDefaultState = LED_STATUES_OFF
};

vuint32_t counter = 0;

void led_int(void)
{
	if(counter == 16)
	{
		LED_toggle(&led);
		counter = 0;
	}
	else
	{
		counter++;
	}
}

ST_MTMR_cfg_t tmr =
{
		.timerOcAAction = MTMR_OC_DISCONNECTED,
		.timerOcBAction = MTMR_OC_DISCONNECTED,
		.timerClk = MTMR_8_PRESCALER,
		.timerChannel = MTMR_TIMER_1_Channel,
		.timerInterruptStates = MTMR_TMR1_OVF_INTERRUPT_ENABLE,
		.timerMode = MTMR_TMR1_NORMAL_MODE,
		.MTMR_setCallbackForOvf = led_int
};


ST_MUART_cfg_t uart =
{
		.transmissionSpeed = MUART_SPEED_U1X,
		.stopBit = MUART_ONE_STOP_BIT,
		.parityBit = MUART_PARITY_DISABLED,
		.operationMode = MUART_SYNCHRONOUS_OPERATION,
		.charSize = MUART_CHARACTER_SIZE_8_BIT,
		.baudRate1x = MUART_UART_BR1X_9600,
		.baudRate2x = MUART_UART_BR2X_9600,
};


ST_MSPI_cfg_t spi =
{
		.spiInterruptStates = MSPI_INTERRUPT_DISABLE,
		.spiDeviceType = MSPI_MASTER,
		.spiDataOrder = MSPI_LSB_DATA_ORDER,
		.spiCphaFunctionality = MSPI_CPHA_FUNCTIONALITY_SAMPLE_LEADING_SETUP_TRAILING,
		.spiClkPolarity = MSPI_CLK_POLARITY_RISING_LEADING_FALLING_TRAILING,
		.spiClkRate = MSPI_CLK_RATE_64
};


ST_MTWI_cfg_t twi =
{
		.prescalerSelection = MTWI_PRESCALER_16,
		.deviceAddress = 0x02
};


void appInit(void)
{
	MGI_vGIE();
	MTMR_init(&tmr);
	LED_init(&led);
	MTMR_start(&tmr);
}

void appMain(void)
{
	while(1)
	{

	}
}




