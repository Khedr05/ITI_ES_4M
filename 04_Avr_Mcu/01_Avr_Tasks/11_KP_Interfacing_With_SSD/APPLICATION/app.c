/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : 09_KP_Interfacing_With_SSD
// File          : app.c
// Date          : 11 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/

#include "app.h"

extern ST_SSD_cfg_t ssdOne;
extern ST_EKP_cfg_t kp;

void appInit(void)
{
	SSD_int(&ssdOne);
	EKP_init(&kp);
}

void appMain(void)
{
	uint8_t btn = 's';
	SSD_setNumberOnSsd(&ssdOne,0);
	while(1)
	{
		EKP_scanningForPressedBtn(&btn);
		if(btn !='s')
		{
			btn -= '0';
			SSD_setNumberOnSsd(&ssdOne,btn);
			btn = 's';
		}
	}
}
