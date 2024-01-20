/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC_Drivers                                    	 
// File          : app.c                                  	     
// Date          : Sep 8, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/


#include "../../Inc/APPLICATION/app.h"


ST_HTFT_cfg_t tft =
{
		.a0Port = MGPIO_PORTA,
		.a0Pin = MGPIO_PIN1,
		.rstPort = MGPIO_PORTA,
		.rstPin = MGPIO_PIN0
};


uint8_t g_u8Region[2][2] =
{
		{'A','M'},
		{'P','M'}
};

uint8_t g_u8Days[7][10] =
{
	{'f','r','i','d','a','y','\0'},
	{'s','a','t','u','r','d','a','y','\0'},
    {'s','u','n','d','a','y','\0'},
    {'m','o','n','d','a','y','\0'},
    {'t','u','e','s','d','a','y','\0'},
    {'w','e','d','n','e','s','d','a','y','\0'},
    {'t','h','u','r','s','d','a','y','\0'},
};


uint8_t g_u8Hour = 0;
uint8_t g_u8Min = 0;
uint8_t g_u8Sec = 0;
uint8_t g_u8DayNumber = 0;
uint8_t g_u8Time = 0;

void appInit(void)
{
	MRCC_Init();
	MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_GPIOA_PERIPHERAL);
	MRCC_enablePeripheral(MRCC_APB2_BUS , MRCC_SPI1_PERIPHERAL);

	MGPIO_setPinMode(MGPIO_PORTA,MGPIO_PIN5, MGPIO_MODE_ALTF);
	MGPIO_setPinMode(MGPIO_PORTA,MGPIO_PIN6, MGPIO_MODE_ALTF);
	MGPIO_setPinMode(MGPIO_PORTA,MGPIO_PIN7, MGPIO_MODE_ALTF);
	MGPIO_SetAltFun(MGPIO_PORTA,MGPIO_PIN5,MGPIO_ALTFN_5);
	MGPIO_SetAltFun(MGPIO_PORTA,MGPIO_PIN6,MGPIO_ALTFN_5);
	MGPIO_SetAltFun(MGPIO_PORTA,MGPIO_PIN7,MGPIO_ALTFN_5);

	HTFT_uddtInit(&tft);
	HTFT_uddtClrDisplay(&tft);
	HTFT_uddtFillBackgroundColor(&tft, HTFT_BLACK_COLOR);
	clockDisplayTime();
	clockDisplayDay();
}
void appMain(void)
{
	while(1)
	{
		MSTK_SetIntervalPeriodic(1000000,clockLogic);
	}
}

void clockLogic(void)
{
	g_u8Sec++;

	if(g_u8Sec == 60)
	{
		g_u8Min++;
		g_u8Sec = 0;
		if(g_u8Min == 60)
		{
			g_u8Hour++;
			g_u8Min = 0;
		}
		if(g_u8Hour == 12)
		{
			g_u8Hour = 0;
			if(g_u8Time == 0)
			{
				g_u8Time = 1;
			}
			else
			{
				g_u8DayNumber++;
				g_u8Time = 0;
			}
		}
	}

	clockDisplayTime();
	clockDisplayDay();
}

void clockDisplayTime(void)
{
	HTFT_uddtDrawChar(&tft ,10,20,(g_u8Hour / 10)+'0',Font_11x18,HTFT_GREEN_COLOR,HTFT_BLACK_COLOR);
	HTFT_uddtDrawChar(&tft ,25,20,(g_u8Hour % 10)+'0',Font_11x18,HTFT_GREEN_COLOR,HTFT_BLACK_COLOR);
	HTFT_uddtDrawChar(&tft ,40,20,':',Font_11x18,HTFT_GREEN_COLOR,HTFT_BLACK_COLOR);


	HTFT_uddtDrawChar(&tft ,50,20,(g_u8Min / 10)+'0',Font_11x18,HTFT_GREEN_COLOR,HTFT_BLACK_COLOR);
	HTFT_uddtDrawChar(&tft ,65,20,(g_u8Min % 10)+'0',Font_11x18,HTFT_GREEN_COLOR,HTFT_BLACK_COLOR);
	HTFT_uddtDrawChar(&tft ,80,20,':',Font_11x18,HTFT_GREEN_COLOR,HTFT_BLACK_COLOR);

	HTFT_uddtDrawChar(&tft ,90,20,(g_u8Sec / 10)+'0',Font_11x18,HTFT_GREEN_COLOR,HTFT_BLACK_COLOR);
	HTFT_uddtDrawChar(&tft ,105,20,(g_u8Sec % 10)+'0',Font_11x18,HTFT_GREEN_COLOR,HTFT_BLACK_COLOR);

	HTFT_uddtDrawChar(&tft ,50,50,g_u8Region[g_u8Time][0],Font_11x18,HTFT_GREEN_COLOR,HTFT_BLACK_COLOR);
	HTFT_uddtDrawChar(&tft ,60,50,g_u8Region[g_u8Time][1],Font_11x18,HTFT_GREEN_COLOR,HTFT_BLACK_COLOR);

}

void clockDisplayDay(void)
{
	if(g_u8DayNumber == 7)
		g_u8DayNumber = 0;

	uint8_t x = 30;
	for(int j = 0; g_u8Days[g_u8DayNumber][j] != STR_NULL;j++)
	{

	  HTFT_uddtDrawChar(&tft ,x,80,g_u8Days[g_u8DayNumber][j],Font_11x18,HTFT_GREEN_COLOR,HTFT_BLACK_COLOR);
	  x += 11;
	}

}



