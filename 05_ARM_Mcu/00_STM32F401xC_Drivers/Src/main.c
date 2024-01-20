/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC_Drivers                                    	 
// File          : main.c                                  	     
// Date          : Sep 8, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../Inc/MCAL/rcc/rcc_interface.h"
#include "../Inc/HAL/hex parsing/hexParsing_interface.h"
#include "../Inc/MCAL/systick/systick_interface.h"
//#include "../Inc/HAL/stp/stp_interface.h"
//#include "../Inc/MCAL/nvic/nvic_interface.h"
//#include "../Inc/MCAL/dma/dma_interface.h"
#include "../Inc/MCAL/gpio/gpio_interface.h"

//#include "../Inc/HAL/ir/ir_interface.h"
#include "../Inc/MCAL/usart/usart_interface.h"
//#include "../Inc/MCAL/spi/spi_interface.h"



ST_MUSART_cfg_t uart =
{
		.copy_uddtUartNumber = MUSART_NUMBER_ONE,
		.copy_uddtBuadRateOption = MUSART_BUAD_RATE_9600_bps,
		.copy_uddtDataSizeOption = MUSART_DATA_SIZE_8_BIT,
		.copy_uddtParityControl = MUSART_PARITY_DISABLED,
		.copy_uddtSamplingModeOption = MUSART_SAMPLING_BY_8,
		.copy_uddtStopBitSelection = MUSART_ONE_STOP_BIT,
		.copy_uddtParitySelection = MUSART_EVEN_PARITY
};


void main(void)
{
	MRCC_Init();
	MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_GPIOB_PERIPHERAL);
	MRCC_enablePeripheral(MRCC_APB2_BUS , MRCC_USART1_PERIPHERAL);
	MUSART_uddtInit(&uart);
	MUSART_uddtEnable(MUSART_NUMBER_ONE , MUSART_ENABLE_BOTH);
	uint8_t data = '#';
	MUSART_uddtSendBlocking((uint8_t *)'s');
	MUSART_uddtSendBlocking((uint8_t *)'h');
	MUSART_uddtSendBlocking((uint8_t *)'e');
	MUSART_uddtSendBlocking((uint8_t *)'r');
	MUSART_uddtSendBlocking((uint8_t *)'i');
	MUSART_uddtSendBlocking((uint8_t *)'f');
	while(1)
	{
		MUSART_uddtReceiveBlocking(&data);
		if(data != '#')
		{
			MUSART_uddtSendBlocking(&data);
			data = '#';
		}
	}
}






//ST_MSPI_cfg_t spi =
//{
//		.cphaSelect = MSPI_CLK_TO_ONE,
//		.cpolSelect = MSPI_SECOND_CLK_FIRST_DATA_EDGE,
//		.deviceRole = MSPI_DEVICE_ROLE_MASTER,
//		.buadRate = MSPI_CLK_DIVSION_16,
//		.statusOfSpi = MSPI_ENABLE,
//		.frameFormatSelection = MSPI_FRAME_MSB,
//		.ssmSelect = MSPI_SSM_ENABLED,
//		.ssiSelect = MSPI_SSI_IS_SET,
//		.dataFrameFormatSelection = MSPI_DFF_8_BIT
//};


//ST_HSTP_cfg_t stp =
//{
//		.dataPortName = MGPIO_PORTA,
//		.dataPinNumber = MGPIO_PIN8,
//		.latchBitPortName = MGPIO_PORTA,
//		.latchBitPinNumber = MGPIO_PIN9,
//		.latchBytePortName = MGPIO_PORTA,
//		.latchBytePinNumber = MGPIO_PIN10
//};
//
//void main(void)
//{
//	MRCC_Init();
//	MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_GPIOA_PERIPHERAL);
//	HSTP_uddtInit(&stp);
//
//	while(1)
//	{
//		for(uint8_t i = 0 ;i <8 ; i++)
//		{
//			HSTP_uddtByteOutput(&stp,1<<i);
//			MSTK_setBusyWait(1000000);
//		}
//	}
//}


//void main(void)
//{
//	uint8_t data = '#';
//	MRCC_Init();
//	MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_GPIOA_PERIPHERAL);
//	//MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_GPIOB_PERIPHERAL);
//	MRCC_enablePeripheral(MRCC_APB2_BUS , MRCC_SPI1_PERIPHERAL);
//	MGPIO_setPinMode(MGPIO_PORTA,MGPIO_PIN6, MGPIO_MODE_ALTF);
//	MGPIO_setPinMode(MGPIO_PORTA,MGPIO_PIN7, MGPIO_MODE_ALTF);
//	MGPIO_SetAltFun(MGPIO_PORTA,MGPIO_PIN6,MGPIO_ALTFN_5);
//	MGPIO_SetAltFun(MGPIO_PORTA,MGPIO_PIN7,MGPIO_ALTFN_5);
//	MGPIO_setPinMode(MGPIO_PORTA, MGPIO_PIN1, MGPIO_MODE_OUTPUT);
//	MGPIO_setOutputMode(MGPIO_PORTA, MGPIO_PIN1, MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
//	MGPIO_setOutputSpeed(MGPIO_PORTA, MGPIO_PIN1, MGPIO_OUTPUT_SPEED_HIGH);
//	MGPIO_setPinVal(MGPIO_PORTA, MGPIO_PIN1, MGPIO_LOGIC_LOW);
//	MGPIO_setPinMode(MGPIO_PORTA, MGPIO_PIN0, MGPIO_MODE_OUTPUT);
//	MGPIO_setOutputMode(MGPIO_PORTA, MGPIO_PIN0, MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
//	MGPIO_setOutputSpeed(MGPIO_PORTA, MGPIO_PIN0, MGPIO_OUTPUT_SPEED_HIGH);
//	MGPIO_setPinVal(MGPIO_PORTA, MGPIO_PIN0, MGPIO_LOGIC_LOW);
//
//	MSPI_uddtInit(&spi);
//	MSPI_uddtSendBlocking((uint8_t *)'a');
//
//	while(1)
//	{
//		MSPI_uddtReceiveBlocking(&data);
//
//		if(data == 's')
//		{
//			MGPIO_setPinVal(MGPIO_PORTA, MGPIO_PIN1, MGPIO_LOGIC_HIGH);
//		}
//		else if(data == 'k')
//		{
//			MGPIO_setPinVal(MGPIO_PORTA, MGPIO_PIN0, MGPIO_LOGIC_HIGH);
//		}
//		else
//		{
//			/* Do Nothing */
//		}
//	}
//}

















//void led(void)
//{
//
//	 MGPIO_setPinVal(MGPIO_PORTA,MGPIO_PIN0,MGPIO_LOGIC_HIGH);
//	 MDMA_uddtClearFlag(MDMA_STREAM_ZERO);
//
//}

//void main(void)
//{
////	uint32_t arrSrc[5] = {1,2,3,4,5};
////	uint32_t arrdest[10] = {0};
////
////	uint32_t size = 5;
//
//	uint8_t dataa = 0;
//	MRCC_Init();
//	MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_GPIOA_PERIPHERAL);
//	MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_GPIOB_PERIPHERAL);
//
//	HIR_uddtIrReceiveInit(MGPIO_PORTB , MGPIO_PIN0);
//	MGPIO_setPinMode(MGPIO_PORTB, MGPIO_PIN1, MGPIO_MODE_OUTPUT);
//	MGPIO_setOutputMode(MGPIO_PORTB, MGPIO_PIN1, MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
//	MGPIO_setOutputSpeed(MGPIO_PORTB, MGPIO_PIN1, MGPIO_OUTPUT_SPEED_HIGH);

//	MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_DMA2_PERIPHERAL);
//	MGPIO_setPinMode(MGPIO_PORTA,MGPIO_PIN0,MGPIO_MODE_OUTPUT);
//	MGPIO_setOutputMode(MGPIO_PORTA,MGPIO_PIN0,MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
//	MGPIO_setOutputSpeed (MGPIO_PORTA , MGPIO_PIN0, MGPIO_OUTPUT_SPEED_LOW);
//	MNVIC_enableInterrupt(56);
//	MNVIC_SetInterruptGroup(GP_16_SP_00);
//	MNVIC_SetInterruptPriority(56 , GP_16_SP_00 ,1,0);
//
//	MDMA_uddtInit(MDMA_STREAM_ZERO);
//	MDMA_uddtSetAddress(MDMA_STREAM_ZERO , arrSrc ,arrdest , size);
//	MDMA_uddtSetCallBack(MDMA_STREAM_ZERO ,led);
//	MDMA_uddtStreamEnable(MDMA_STREAM_ZERO);
//
//	while(1)
//	{
//		HIR_uddtIrGetDataVal(&dataa);
//		if(dataa == 69)
//		{
//			MGPIO_setPinVal(MGPIO_PORTB, MGPIO_PIN1, MGPIO_LOGIC_HIGH);
//		}
//		else if(dataa == 70)
//		{
//			MGPIO_setPinVal(MGPIO_PORTB, MGPIO_PIN1, MGPIO_LOGIC_LOW);
//		}
//	}
//}
