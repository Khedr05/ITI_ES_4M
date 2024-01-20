/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC_Drivers                                    	 
// File          : main.c                                  	     
// Date          : Sep 8, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../Inc/MCAL/rcc/rcc_interface.h"
#include "../Inc/HAL/tft/tft_interface.h"
#include "../Inc/HAL/tft/image.h"

ST_HTFT_cfg_t tft =
{
		.a0Port = MGPIO_PORTA,
		.a0Pin = MGPIO_PIN1,
		.rstPort = MGPIO_PORTA,
		.rstPin = MGPIO_PIN0
};


uint16_t font_s[16] ={
		0x80FF, 0x8081, 0x8081, 0x8081,
		0x8081, 0x8081, 0x8081, 0x8081,
		0x8081, 0x8081, 0x8081, 0x8081,
		0x8081, 0x8081, 0x8081, 0xFF81};

uint16_t font_u[16] = {
    0xFFFF, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0xFFFF
};

uint16_t font_n[16] = {
		0xFFFF, 0x8000, 0x8000, 0x8000,
		0x8000, 0x8000, 0x8000, 0x8000,
		0x8000, 0x8000, 0x8000, 0x8000,
		0x8000, 0x8000, 0x8000, 0xFFFF};



uint16_t font_d[16] = {
		0x1FF8, 0x2004, 0x4002, 0x8001,
		0x8001, 0x8001, 0x8001, 0x8001,
		0x8001, 0x8001, 0x8001, 0x8001,
		0x8001, 0x8001, 0x8001, 0xFFFF};


uint16_t font_a[16] = {
		0xFFFF, 0x8100, 0x8100, 0x8100,
		0x8100, 0x8100, 0x8100, 0x8100,
		0x8100, 0x8100, 0x8100, 0x8100,
		0x8100, 0x8100, 0x8100, 0xFFFF};

uint16_t font_y[16] = {
		0x8000, 0xC000, 0x6000, 0x3000,
		0x1800, 0x0C00, 0x0600, 0x07FF,
		0x07FF, 0x0600, 0x0C00, 0x1800,
		0x3000, 0x6000, 0xC000, 0x8000};

uint16_t font_1[16] = {
		0x0000, 0x0000, 0x0000, 0x0000,
		0x0001, 0x0001, 0x0001, 0x0001,
		0xFFFF, 0x8001, 0x4001, 0x2001,
		0x1001, 0x0A00, 0x0600, 0x0200};

void main(void)
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
	HTFT_uddtDrawChar(&tft , font_s , 0x07e0 ,110,20 );
	HTFT_uddtDrawChar(&tft , font_u , 0x07e0 ,90,20 );
	HTFT_uddtDrawChar(&tft , font_n , 0x07e0 ,70,20 );
	HTFT_uddtDrawChar(&tft , font_d , 0x07e0 ,50,20 );
	HTFT_uddtDrawChar(&tft , font_a , 0x07e0 ,30,20 );
	HTFT_uddtDrawChar(&tft , font_y , 0x07e0 ,10,20 );

	HTFT_uddtDrawChar(&tft , font_1 , 0x07e0 ,110,60 );

	//HTFT_uddtDrawTriangle(&tft,0x5cd9,0,127,0,60);
	//HTFT_uddtDrawVerticalLine(&tft,0x5cd9,64,0,159);
	//HTFT_uddtDrawHorizontalLine(&tft,0x07e0,0,127,80);
	//HTFT_uddtFillRetangle(&tft,0x07e0,42,84,53,106);
	//HTFT_uddtSetXYAxis(&tft,0,127,0,159);
	//HTFT_uddtDisplayImage(&tft,image);
	//HTFT_uddtFillBackgroundColor(&tft , 0x07e0);
	while(1)
	{

	}
}










