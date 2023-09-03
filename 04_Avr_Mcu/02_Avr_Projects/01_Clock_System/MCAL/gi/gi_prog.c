/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : gie_prog.c                                  	     
// Date          : 14 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "gi_interface.h"

void MGI_vGIE(void)
{
	SET_BIT(SREG_REG,I_BIT);
}

void MGI_vGID(void)
{
	CLR_BIT(SREG_REG,I_BIT);
}
