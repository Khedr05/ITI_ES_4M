/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 04_Ldm_With_Stp                                    	 
// File          : app.c                                  	     
// Date          : Sep 28, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../Inc/APPLICATION/app.h"

ST_HLDM_cfg_t ldmOne =
{
		.copy_uddtLdmColPort = MGPIO_PORTA,
		.copy_uddtLdmRowPort = MGPIO_PORTB,
		.copy_uddtLdmColPins = {MGPIO_PIN0,MGPIO_PIN1,MGPIO_PIN2,MGPIO_PIN3,MGPIO_PIN4,MGPIO_PIN5,MGPIO_PIN6,MGPIO_PIN7},
		.copy_uddtLdmRowPins = {MGPIO_PIN7,MGPIO_PIN8,MGPIO_PIN9,MGPIO_PIN10,MGPIO_PIN12,MGPIO_PIN13,MGPIO_PIN14,MGPIO_PIN15}
};

uint16_t zero[8] = {
    0x00F8,
    0x0118,
    0x0128,
    0x0148,
    0x0188,
    0x0118,
    0x00F8,
    0x0000
};

uint16_t one[8] = {
    0x0000,
    0x0010,
    0x0010,
    0x0010,
    0x0010,
    0x0010,
    0x0010,
    0x0010
};

uint16_t two[8] = {
    0x00F8,
    0x0104,
    0x0104,
    0x0008,
    0x0010,
    0x0020,
    0x0040,
    0x01FC
};

uint16_t three[8] = {
    0x00F8,
    0x0104,
    0x0104,
    0x0008,
    0x0104,
    0x0104,
    0x0104,
    0x00F8
};

uint16_t four[8] = {
    0x0008,
    0x0018,
    0x0028,
    0x0048,
    0x0088,
    0x01FC,
    0x0008,
    0x0008
};

uint16_t five[8] = {
    0x01FC,
    0x0100,
    0x0100,
    0x01F8,
    0x0004,
    0x0004,
    0x0104,
    0x00F8
};

uint16_t six[8] = {
    0x00F8,
    0x0104,
    0x0100,
    0x01F8,
    0x0104,
    0x0104,
    0x0104,
    0x00F8
};

uint16_t seven[8] = {
    0x01FC,
    0x0104,
    0x0008,
    0x0008,
    0x0010,
    0x0020,
    0x0020,
    0x0040
};

uint16_t eight[8] = {
    0x00F8,
    0x0104,
    0x0104,
    0x00F8,
    0x0104,
    0x0104,
    0x0104,
    0x00F8
};

uint16_t nine[8] = {
    0x00F8,
    0x0104,
    0x0104,
    0x0104,
    0x00FC,
    0x0008,
    0x0008,
    0x00F0
};




void appInit(void)
{
	MRCC_Init();
	MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_GPIOA_PERIPHERAL);
	MRCC_enablePeripheral(MRCC_AHP1_BUS,MRCC_GPIOB_PERIPHERAL);
	MRCC_enablePeripheral(MRCC_APB2_BUS, MRCC_SYSCFG_PERIPHERAL);
	HLDM_init(&ldmOne);
	HIR_uddtIrReceiveInit(MGPIO_PORTB,MGPIO_PIN0);
}

void appMain(void)
{
	uint8_t l_u8IrVal = 0;
	while(1)
	{
		HIR_uddtIrGetDataVal(&l_u8IrVal);

		switch(l_u8IrVal)
		{
			case IR_ZERO_BTN_VAL :
			{
				HLDM_enable(&ldmOne , zero);
				break;
			}
			case IR_ONE_BTN_VAL :
			{
				HLDM_enable(&ldmOne , one);
				break;
			}
			case IR_TWO_BTN_VAL :
			{
				HLDM_enable(&ldmOne , two);
				break;
			}
			case IR_THREE_BTN_VAL :
			{
				HLDM_enable(&ldmOne , three);
				break;
			}
			case IR_FOUR_BTN_VAL :
			{
				HLDM_enable(&ldmOne , four);
				break;
			}
			case IR_FIVE_BTN_VAL :
			{
				HLDM_enable(&ldmOne , five);
				break;
			}
			case IR_SIX_BTN_VAL :
			{
				HLDM_enable(&ldmOne , six);
				break;
			}
			case IR_SEVEN_BTN_VAL :
			{
				HLDM_enable(&ldmOne , seven);
				break;
			}
			case IR_EIGHT_BTN_VAL :
			{
				HLDM_enable(&ldmOne , eight);
				break;
			}
			case IR_NINE_BTN_VAL :
			{
				HLDM_enable(&ldmOne , nine);
				break;
			}
			default :
			{
				/* Do Nothing */
			}
		}
	}
}



