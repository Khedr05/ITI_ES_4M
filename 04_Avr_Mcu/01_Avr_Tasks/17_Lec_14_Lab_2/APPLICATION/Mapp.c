/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 19_Lec_14_Lab_2                                    	 
// File          : Mapp.c
// Date          : 2 Sept 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "app.h"

void MASTER_appInit(void)
{
	HLCD_init(&myLcd);
	MSPI_init(&MASTER_spi);
	MSPI_enable();
}

void MASTER_appMain(void)
{

	uint8_t data = 0;


	while(1)
	{
		HLCD_Clr(&myLcd);
		HLCD_changeCursorPosation(&myLcd,0,0);
		HLCD_displayString(&myLcd,(uint8_t *)"Sending 5");
		HLCD_changeCursorPosation(&myLcd,1,0);
		HLCD_displayString(&myLcd,(uint8_t *)"In 1 sec");
		_delay_ms(1000);
		data = 5;
		MSPI_send(data);
		HLCD_Clr(&myLcd);
		HLCD_changeCursorPosation(&myLcd,0,0);
		HLCD_displayString(&myLcd,(uint8_t *)"Sending 2");
		HLCD_changeCursorPosation(&myLcd,1,0);
		HLCD_displayString(&myLcd,(uint8_t *)"In 1 sec");
		_delay_ms(1000);
		data = 2;
		MSPI_send(data);
		HLCD_Clr(&myLcd);
		HLCD_changeCursorPosation(&myLcd,0,0);
		HLCD_displayString(&myLcd,(uint8_t *)"Sending 4");
		HLCD_changeCursorPosation(&myLcd,1,0);
		HLCD_displayString(&myLcd,(uint8_t *)"In 1 sec");
		_delay_ms(1000);
		data = 4;
		MSPI_send(data);
		HLCD_Clr(&myLcd);
		HLCD_changeCursorPosation(&myLcd,0,0);
		HLCD_displayString(&myLcd,(uint8_t *)"Repeat All");
		HLCD_changeCursorPosation(&myLcd,1,0);
		HLCD_displayString(&myLcd,(uint8_t *)"Again In 1 sec");
		_delay_ms(1000);
	}
}







