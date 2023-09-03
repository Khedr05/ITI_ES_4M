/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 17_Clock_System                                    	 
// File          : app.c                                  	     
// Date          : 29 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "app.h"

void appInit(void)
{
	CLOCK_init();
}
void appMain(void)
{
	while(1)
	{
		CLOCK_interface();
	}
}
