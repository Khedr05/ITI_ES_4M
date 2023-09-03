/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 15_Lec_8_Lab_2
// File          : app.c                                  	     
// Date          : 24 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/


#include "app.h"

ST_HLCD_cfg_t myLcd =
{
		.dataPinsMode = HLCD_8_BIT_MODE,
		.dataPort = GPIO_PORTD,
		.controlPort = GPIO_PORTC,
		.rsPin = GPIO_PIN0,
		.rwPin = GPIO_PIN1,
		.enPin = GPIO_PIN2,
		.d0Pin = GPIO_PIN0,
		.d1Pin = GPIO_PIN1,
		.d2Pin = GPIO_PIN2,
		.d3Pin = GPIO_PIN3,
		.d4Pin = GPIO_PIN4,
		.d5Pin = GPIO_PIN5,
		.d6Pin = GPIO_PIN6,
		.d7Pin = GPIO_PIN7
};


ST_MADC_CFG_t adc =
{
		.triggerSource = MADC_POLLING_ON_FLAG,
		.resultAdjust = MADC_RIGHT_ADJUST,
		.referenceSource = MADC_AVCC_EXTERNAL_CAPACITOR,
		.prescalerDivision = MADC_DIV8,
		.channelSelection = MADC_CHANNEL_ZERO
};

void appInit(void)
{
	HLCD_init(&myLcd);
	MADC_init(&adc);
}

void appMain(void)
{
	Uint16_t adcReading = 0;
	Uint16_t tempValue = 0;
	while(1)
	{
		MADC_startConversion(&adc);
		MADC_getConversionResult(&adc,&adcReading);
		tempValue = (adcReading * 4.88);

		tempValue = tempValue / 10 ;
		HLCD_displayNumber(&myLcd,tempValue);
		_delay_ms(1000);
		HLCD_Clr(&myLcd);
	}
}
