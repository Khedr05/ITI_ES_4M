/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Atmega32_Drivers
// File          : main.c
// Date          : 31 Jul 2023
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/

#include "ECUAL/ssd/ssd_interface.h"
#include <util/delay.h>

ST_SSD_DualCfg_t ssd = {.ssdPinAPortName = GPIO_PORTA,
		.ssdPinBPortName = GPIO_PORTA,
		.ssdPinCPortName = GPIO_PORTA,
		.ssdPinDPortName = GPIO_PORTA,
		.ssdPinEPortName = GPIO_PORTA,
		.ssdPinFPortName = GPIO_PORTA,
		.ssdPinGPortName = GPIO_PORTA,
		.ssdPinAPinNumber = GPIO_PIN0,
		.ssdPinBPinNumber = GPIO_PIN1,
		.ssdPinCPinNumber = GPIO_PIN2,
		.ssdPinDPinNumber = GPIO_PIN3,
		.ssdPinEPinNumber = GPIO_PIN4,
		.ssdPinFPinNumber = GPIO_PIN5,
		.ssdPinGPinNumber = GPIO_PIN6,
		.ssdFirstCommonType = SSD_ANODE_COMMON,
		.ssdSecondCommonType = SSD_ANODE_COMMON,
		.ssdPinFirstComPinNumber = GPIO_PIN5,
		.ssdPinSecondComPinNumber = GPIO_PIN1,
		.ssdPinFirstComPortName = GPIO_PORTC,
		.ssdPinSecondComPortName = GPIO_PORTC,
		.ssdCurrentDisplay = SSD_FIRST};




void main(void) {

	SSD_dualInit(&ssd);
	while (1) {

			for(int i=0;i<10;i++)
			{
				SSD_dualSwitchSegment(&ssd, SSD_FIRST);
				SSD_dualSetCurrentSegmentComPin(&ssd);
				SSD_dualSetNumberOnSsd(&ssd,i);
				for(int j = 0;j<10;j++)
				{
					SSD_dualSwitchSegment(&ssd, SSD_SECOND);
					SSD_dualSetCurrentSegmentComPin(&ssd);
					SSD_dualSetNumberOnSsd(&ssd,j);
					for(int s = 0;s < 30; s++)
					{
						SSD_dualSwitchSegment(&ssd, SSD_FIRST);
						SSD_dualSetCurrentSegmentComPin(&ssd);
						SSD_dualSetNumberOnSsd(&ssd,i);
						_delay_ms(10);
						SSD_dualSwitchSegment(&ssd, SSD_SECOND);
						SSD_dualSetCurrentSegmentComPin(&ssd);
						SSD_dualSetNumberOnSsd(&ssd,j);
						_delay_ms(10);
					}
				}
			}



	}
}
