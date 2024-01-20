/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : dac_prog.c                                  	     
// Date          : Sep 14, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/HAL/dac/dac_interface.h"

extern unsigned char Song[];
extern unsigned int SongLen;

uint16_t counter = 0;

EN_HDAC_systemState_t HDAC_uddtInit(void)
{
	EN_HDAC_systemState_t dacRet = HDAC_NOK;
	EN_MGPIO_systemState_t gpioRet = MGPIO_NOK;

	for (uint8_t i = 0; i <= 7; i++) {

		gpioRet = MGPIO_setPinMode(MGPIO_PORTA,i, MGPIO_MODE_OUTPUT);

		if(gpioRet == MGPIO_OK)
		{
			gpioRet = MGPIO_setOutputMode(MGPIO_PORTA,i,  MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
		}
		else
		{
			dacRet = HDAC_NOK;
		}

		if(gpioRet == MGPIO_OK)
		{
			gpioRet = MGPIO_setOutputSpeed(MGPIO_PORTA,i,  MGPIO_OUTPUT_SPEED_HIGH);
		}
		else
		{
			dacRet = HDAC_NOK;
		}

		if(gpioRet == MGPIO_OK)
			dacRet = HDAC_OK;
		else
		{
			dacRet = HDAC_NOK;
			break;
		}
	}
	return dacRet;
}

EN_HDAC_systemState_t HDAC_uddtSend(void)
{
	EN_HDAC_systemState_t dacRet = HDAC_NOK;
	EN_MGPIO_systemState_t gpioRet = MGPIO_NOK;


	gpioRet = MGPIO_setPortVal(MGPIO_PORTA, Song[counter]);
	counter++;
	if(counter == SongLen)
		counter = 0;

	if(gpioRet == MGPIO_OK)
		dacRet = HDAC_OK;
	else
		dacRet = HDAC_NOK;

	return dacRet;
}



