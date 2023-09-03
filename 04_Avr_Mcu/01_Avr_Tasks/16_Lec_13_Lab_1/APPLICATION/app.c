/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 18_Lec_13_Lab_1                                    	 
// File          : app.c                                  	     
// Date          : 2 Sept 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "app.h"

ST_LED_cfg_t greenLed =
{
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN0,
		.ledDefaultState = LED_STATUES_OFF
};

ST_LED_cfg_t blueLed =
{
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN1,
		.ledDefaultState = LED_STATUES_OFF
};

ST_LED_cfg_t redLed =
{
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN2,
		.ledDefaultState = LED_STATUES_OFF
};

ST_LED_cfg_t bibyLed =
{
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN3,
		.ledDefaultState = LED_STATUES_OFF
};

ST_LED_cfg_t orangeLed =
{
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN4,
		.ledDefaultState = LED_STATUES_OFF
};

ST_LED_cfg_t pinkLed =
{
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN5,
		.ledDefaultState = LED_STATUES_OFF
};

ST_LED_cfg_t purpleLed =
{
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN6,
		.ledDefaultState = LED_STATUES_OFF
};

ST_LED_cfg_t yellowLed =
{
		.ledPortName = GPIO_PORTA,
		.ledPinNumber = GPIO_PIN7,
		.ledDefaultState = LED_STATUES_OFF
};


ST_MUART_cfg_t uart =
{

	.transmissionSpeed = MUART_SPEED_U1X,
	.stopBit = MUART_ONE_STOP_BIT,
	.parityBit = MUART_PARITY_DISABLED,
	.operationMode = MUART_SYNCHRONOUS_OPERATION,
	.charSize = MUART_CHARACTER_SIZE_8_BIT,
	.baudRate1x = MUART_UART_BR1X_9600,
	.baudRate2x = MUART_UART_BR2X_9600
};

void initMain(void)
{
	MUART_init(&uart);
	MUART_enable();

	LED_init(&greenLed);
	LED_init(&blueLed);
	LED_init(&bibyLed);
	LED_init(&redLed);
	LED_init(&orangeLed);
	LED_init(&pinkLed);
	LED_init(&yellowLed);
	LED_init(&purpleLed);
}

void appMain(void)
{
	uint8_t recivedData = '#';
	while(1)
	{
		MUART_receiveData(&recivedData);
		MUART_sendData(recivedData);
		if(recivedData != '#')
		{
			if(recivedData == '0')
			{
				LED_toggle(&greenLed);
				recivedData = '#';
			}
			else if(recivedData == '1')
			{
				LED_toggle(&blueLed);
				recivedData = '#';
			}
			else if(recivedData == '2')
			{
				LED_toggle(&redLed);
				recivedData = '#';
			}
			else if(recivedData == '3')
			{
				LED_toggle(&bibyLed);
				recivedData = '#';
			}
			else if(recivedData == '4')
			{
				LED_toggle(&orangeLed);
				recivedData = '#';
			}
			else if(recivedData == '5')
			{
				LED_toggle(&pinkLed);
				recivedData = '#';
			}
			else if(recivedData == '6')
			{
				LED_toggle(&purpleLed);
				recivedData = '#';
			}
			else if(recivedData == '7')
			{
				LED_toggle(&yellowLed);
				recivedData = '#';
			}
			else
			{
				recivedData = '#';
			}
		}
	}
}
















