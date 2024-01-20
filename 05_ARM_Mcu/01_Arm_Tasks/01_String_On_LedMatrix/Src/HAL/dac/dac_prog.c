/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : dac_prog.c                                  	     
// Date          : Sep 14, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/HAL/dac/dac_interface.h"
#include "../../../Inc/HAL/dac/song.h"
extern unsigned char Song[];

uint16_t counter = 0;

void init(void)
{
    for (uint8_t i = 0; i <= 7; i++) {
    	// Configure ROW pins as outputs
        MGPIO_setPinMode(MGPIO_PORTA,i, MGPIO_MODE_OUTPUT);
        MGPIO_setOutputMode(MGPIO_PORTA,i,  MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
        MGPIO_setOutputSpeed(MGPIO_PORTA,i,  MGPIO_OUTPUT_SPEED_HIGH);
        // Configure COL pins as outputs
    }
}

void send(void)
{
	MGPIO_setPortVal(MGPIO_PORTA, Song[counter]);
	counter++;
	if(counter == 59195)
	counter = 0;
}



