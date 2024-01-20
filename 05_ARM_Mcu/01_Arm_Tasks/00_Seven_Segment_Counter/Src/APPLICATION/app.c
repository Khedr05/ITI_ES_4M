/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 00_Seven_Segment_Counter                                    	 
// File          : app.c                                  	     
// Date          : Sep 16, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../Inc/APPLICATION/app.h"

ST_HSSD_cfg_t ssdOne =
{
		.uddtCommanPinMode = HSSD_COMMAN_ANODE,
		.uddtSsdPortsName = {MGPIO_PORTA,MGPIO_PORTA,MGPIO_PORTA,MGPIO_PORTA,MGPIO_PORTA,MGPIO_PORTA,MGPIO_PORTA,MGPIO_PORTA,MGPIO_PORTA},
		.uddtSsdPinsNumber = {MGPIO_PIN0,MGPIO_PIN1,MGPIO_PIN2,MGPIO_PIN3,MGPIO_PIN4,MGPIO_PIN5,MGPIO_PIN6,MGPIO_PIN7,MGPIO_PIN8}
};

ST_HSSD_cfg_t ssdTwo =
{
		.uddtCommanPinMode = HSSD_COMMAN_ANODE,
		.uddtSsdPortsName = {MGPIO_PORTB,MGPIO_PORTB,MGPIO_PORTB,MGPIO_PORTB,MGPIO_PORTB,MGPIO_PORTB,MGPIO_PORTB,MGPIO_PORTB,MGPIO_PORTA},
		.uddtSsdPinsNumber = {MGPIO_PIN7,MGPIO_PIN8,MGPIO_PIN9,MGPIO_PIN10,MGPIO_PIN12,MGPIO_PIN13,MGPIO_PIN14,MGPIO_PIN15,MGPIO_PIN9}
};

void appInit(void)
{
	MRCC_Init();
	MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_GPIOA_PERIPHERAL);
	MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_GPIOB_PERIPHERAL);
	HSSD_init(&ssdOne);
	HSSD_init(&ssdTwo);
}

void appMain(void)
{
	while(1)
	{
		for(uint8_t i = 0 ; i<= 9 ; i++)
		{
			HSSD_displayNumber(&ssdOne,i);
			for(uint8_t j = 0 ; j<=9 ; j++)
			{
				HSSD_displayNumber(&ssdTwo,j);
				MSTK_setBusyWait(2000000);
			}
		}
	}
}
