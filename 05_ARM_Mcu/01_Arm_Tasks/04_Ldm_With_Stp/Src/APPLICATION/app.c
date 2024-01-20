/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 04_Ldm_With_Stp                                    	 
// File          : app.c                                  	     
// Date          : Sep 28, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../Inc/APPLICATION/app.h"


uint8_t Hello[35] = {0x00,0x00,0x00,0x00,0x00,0xF8,0x20,0xF8,
				0x00,0xF8,0xA8,0xA8,0x00,0xF8,0x80,0x80,
				0x00,0xF8,0x80,0x80,0x00,0xF0,0x90,0xF0,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00};

uint8_t Numbers [][8]={	{0x00, 0x3C, 0x24, 0x24, 0x24, 0x24, 0x3C, 0x00},
					{0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00},
					{0x00, 0x7C, 0x04, 0x7C, 0x40, 0x40, 0x7C, 0x00},
					{0x00, 0x7C, 0x04, 0x04, 0x7C, 0x04, 0x7C, 0x00},
					{0x00, 0x44, 0x44, 0x44, 0x7C, 0x04, 0x04, 0x00},
					{0x00, 0x7C, 0x40, 0x40, 0x7C, 0x04, 0x7C, 0x00},
					{0x00, 0x7C, 0x40, 0x40, 0x7C, 0x44, 0x7C, 0x00},
					{0x00, 0x7C, 0x04, 0x04, 0x7C, 0x04, 0x04, 0x00},
					{0x00, 0x7C, 0x44, 0x44, 0x7C, 0x44, 0x7C, 0x00},
					{0x00, 0x7C, 0x44, 0x44, 0x7C, 0x04, 0x7C, 0x00},
				};

uint8_t h[8] =
{
	0x0000,0x0000,0x00FF,0x0010,0x0010,0x00FF,0x0000,0x0000,
};



ST_HSTP_cfg_t stpOne =
{
		.dataPortName = MGPIO_PORTA,
		.dataPinNumber = MGPIO_PIN0,
		.latchBitPortName = MGPIO_PORTA,
		.latchBitPinNumber = MGPIO_PIN2,
		.latchBytePortName = MGPIO_PORTA,
		.latchBytePinNumber = MGPIO_PIN1
};





uint16_t L_u16SendData;
uint8_t L_u8Counter1,L_u8Counter2,L_u8Counter3;



uint8_t test[1][8] =
{
		{
			0b10000001,
		}
};

uint16_t sherif[6][8] = {
    {
        0x0000, 0x3E00, 0x2222, 0x3E22, 0x2222, 0x3E22, 0x0000, 0x0000
    }, // 's'
    {
        0x2222, 0x2222, 0x3E22, 0x2424, 0x2424, 0x2222, 0x2222, 0x0000
    }, // 'h'
    {
        0x3C00, 0x2222, 0x3C22, 0x2020, 0x2222, 0x3C00, 0x0000, 0x0000
    }, // 'e'
    {
        0x2222, 0x2222, 0x3E22, 0x2222, 0x2122, 0x3E00, 0x0000, 0x0000
    }, // 'r'
    {
        0x3E00, 0x0404, 0x0404, 0x0404, 0x0404, 0x3E00, 0x0000, 0x0000
    }, // 'i'
    {
        0x3E00, 0x0808, 0x1010, 0x2020, 0x3E00, 0x0000, 0x0000, 0x0000
    }  // 'f'
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
	HSTP_uddtInit(&stpOne);
}

void appMain(void)
{

	while(1)
	{
		for(uint8_t L_u8Counter1=0; L_u8Counter1<6;L_u8Counter1++)
		{
			for(uint8_t L_u8Counter2=0; L_u8Counter2<20;L_u8Counter2++)
			{
				for (L_u8Counter3=0;L_u8Counter3<8;L_u8Counter3++)
				{
					HSTP_uddtHalfWordOutput(&stpOne ,sherif[L_u8Counter1][L_u8Counter3]);

				}
			}
			MSTK_setBusyWait(1000);
		}
	}
}


