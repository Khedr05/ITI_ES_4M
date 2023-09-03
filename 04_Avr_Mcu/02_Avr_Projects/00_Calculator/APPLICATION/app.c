/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 11_Lec_4_Assignment_1                                    	 
// File          : app.c                                  	     
// Date          : 23 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "app.h"

void appInit(void)
{
	HLCD_init(&myLcd);
	HKP_init(&myKeypad);
}
void appMain(void)
{
	while(1)
	{
		CALC_interface();
	}
}
