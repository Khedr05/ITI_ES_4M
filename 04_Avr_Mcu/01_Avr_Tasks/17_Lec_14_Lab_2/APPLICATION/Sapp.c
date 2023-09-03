/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 19_Lec_14_Lab_2                                    	 
// File          : Sapp.c                                  	     
// Date          : 2 Sept 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "app.h"

void SLAVE_appInit(void)
{
	HLCD_init(&myLcd);
	MSPI_init(&SLAVE_spi);
	MSPI_enable();
}

void SLAVE_appMain(void)
{
	uint8_t data = 0;
	HLCD_Clr(&myLcd);
	HLCD_changeCursorPosation(&myLcd,0,0);
	HLCD_displayString(&myLcd,(uint8_t *)"Receiving....");

	while(1)
	{
		MSPI_recive(&data);
		HLCD_Clr(&myLcd);
		HLCD_changeCursorPosation(&myLcd,0,0);
		HLCD_displayString(&myLcd,(uint8_t *)"Received Data");
		HLCD_changeCursorPosation(&myLcd,1,0);
		HLCD_displayNumber(&myLcd,data);
	}
}
