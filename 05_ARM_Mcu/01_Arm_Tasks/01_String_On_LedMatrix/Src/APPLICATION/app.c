/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 01_String_On_LedMatrix                                    	 
// File          : app.c                                  	     
// Date          : Sep 16, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../Inc/APPLICATION/app.h"


ST_HLDM_cfg_t ledMatrix =
{
		.copy_uddtLdmRowPort = MGPIO_PORTA,
		.copy_uddtLdmColPort = MGPIO_PORTB,
		.copy_uddtLdmRowPins = {MGPIO_PIN0 ,MGPIO_PIN1 , MGPIO_PIN2 , MGPIO_PIN3 , MGPIO_PIN4 , MGPIO_PIN5 , MGPIO_PIN6 , MGPIO_PIN7 },
		.copy_uddtLdmColPins = {MGPIO_PIN7 , MGPIO_PIN8 , MGPIO_PIN9 , MGPIO_PIN10 , MGPIO_PIN12 , MGPIO_PIN13 , MGPIO_PIN14 , MGPIO_PIN15}
};


uint16_t hello[48] = {
    0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x00FF,0x0010,0x0010,0x00FF,0x0000,0x0000,
	0x0000,0x0000,0x00FF,0x0091,0x0091,0x0091,0x0000,0x0000,
	0x0000,0x0000,0x00FF,0x0080,0x0080,0x0080,0x0000,0x0000,
	0x0000,0x0000,0x00FF,0x0080,0x0080,0x0080,0x0000,0x0000,
	0x0000,0x0000,0x003C,0x0042,0x0042,0x003C,0x0000,0x0000,
};

void appInit(void)
{
	MRCC_Init();
	MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_GPIOA_PERIPHERAL);
	MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_GPIOB_PERIPHERAL);
	HLDM_init(&ledMatrix);
}

void appMain(void)
{
    while (1)
    {

		for(uint8_t i=0; i<48;i++)
		{
			for(uint8_t j=0; j<8;j++)
			{
				HLDM_enable(&ledMatrix,&hello[i]);
			}
		}
    }
}


