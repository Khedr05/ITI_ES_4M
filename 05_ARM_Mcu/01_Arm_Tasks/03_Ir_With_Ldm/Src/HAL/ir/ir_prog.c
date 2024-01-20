/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : ir_prog.c                                  	     
// Date          : Sep 18, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/HAL/ir/ir_interface.h"

EN_HIR_systemState_t HIR_uddtIrReceiveInit(EN_MGPIO_portOptions_t copy_uddtIrPortNumber , EN_MGPIO_pinOptions_t copy_uddtIrPinNumber)
{
	MGPIO_setPinMode(copy_uddtIrPortNumber, copy_uddtIrPinNumber, MGPIO_MODE_INPUT);
	MGPIO_setOutputSpeed(copy_uddtIrPortNumber, copy_uddtIrPinNumber, MGPIO_OUTPUT_SPEED_HIGH);
	MGPIO_setPullState(copy_uddtIrPortNumber,copy_uddtIrPinNumber,MGPIO_PULL_PULL_UP);
	MEXTI_enableEXTI(MEXTI_LINE0);
	MEXTI_setTriggerSource(MEXTI_LINE0 , MEXTI_FALLING_EDGE);
	MEXTI_setExtiConfig(MEXTI_LINE0 , copy_uddtIrPortNumber);
	MNVIC_enableInterrupt(6);
	MNVIC_SetInterruptGroup(GP_16_SP_00);
	MNVIC_SetInterruptPriority(6 , GP_16_SP_00 ,1,0);
	MEXTI_setCallBack(HIR_uddtIrReceive , MEXTI_LINE0);



}

static uint8_t g_u8StartFlag = 0;
static uint8_t g_u8BitCounter = 0;
static uint32_t g_u8DataReceiveBuffer[50] = {0};
uint8_t g_u8Data = 0;

static void HIR_uddtIrReceive(void)
{

	if(g_u8StartFlag == 0)
	{
		g_u8StartFlag = 1;
		MSTK_SetIntervalSingle(1000000, HIR_uddtIrGetDataLogic);
	}
	else if(g_u8StartFlag == 1)
	{
		uint32_t tempTime = 0;
		MSTK_getElapsedTime(&tempTime);
		g_u8DataReceiveBuffer[g_u8BitCounter] = tempTime;
		MSTK_SetIntervalSingle(1000000, HIR_uddtIrGetDataLogic);
		g_u8BitCounter++;

	}
	else
	{
		/* Do Nothing */
	}

}

static void HIR_uddtIrGetDataLogic(void)
{
	for(uint8_t i=0 ; i<8 ; i++)
	{
		if(g_u8DataReceiveBuffer[17+i] > 1000 && g_u8DataReceiveBuffer[17+i] < 1200)
		{
			CLR_BIT(g_u8Data , i);
		}
		else if(g_u8DataReceiveBuffer[17+i] > 2000 && g_u8DataReceiveBuffer[17+i] < 2300)
		{
			SET_BIT(g_u8Data , i);
		}
	}
	g_u8StartFlag = 0;
	g_u8BitCounter = 0;
}

EN_HIR_systemState_t HIR_uddtIrGetDataVal(uint8_t *retOfDataVal)
{
	*retOfDataVal = g_u8Data;
}
