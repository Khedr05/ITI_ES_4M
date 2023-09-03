/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Atmega32_Drivers
// File          : kp_prog.c
// Date          : 10 Aug 2023 */ GitHub        : https://github.com/sherifkhadr
/*************************************************************************/

#include "kp_interface.h"

static uint8_t KEYPAD_arrBtnVal[KEYPAD_ROWS_SIZE][KEYPAD_COLUMNS_SIZE] = {
		{'7', '8', '9', '/'},
		{'4', '5', '6', '*'},
		{'1', '2', '3', '-'},
		{'#', '0', '=', '+'},
};


static ST_GPIO_cfg_t arrOfRows[KEYPAD_ROWS_SIZE];
static ST_GPIO_cfg_t arrOfColumns[KEYPAD_COLUMNS_SIZE];


EN_EKP_systemStatus_t EKP_init(ST_EKP_cfg_t const *ST_ptrKeypadInstance) {
	EN_EKP_systemStatus_t kpRet = EKP_NOK;
	EN_GPIO_systemState_t gpioRet = GPIO_NOK;
	if (PTR_NULL != ST_ptrKeypadInstance) {
		uint8_t Rowscounter, Colscounter;
		for (Rowscounter = LOOP_STARTING_VALUE;Rowscounter < KEYPAD_ROWS_SIZE;Rowscounter++) {

			ST_GPIO_cfg_t tempStructForRowPin =
			{
					.pinDirection = GPIO_OUTPUT,
					.logicOnPin = GPIO_HIGH,
					.portName = ST_ptrKeypadInstance->arrOfRowPorts[Rowscounter],
					.pinNumber = ST_ptrKeypadInstance->arrOfRowPins[Rowscounter]
			};
			gpioRet = GPIO_initPin(&tempStructForRowPin);
			if (gpioRet == GPIO_OK)
			{
				arrOfRows[Rowscounter] = tempStructForRowPin;
				kpRet = EKP_OK;
			}
			else
			{
				kpRet = EKP_NOK;
				break;
			}
		}
		if (gpioRet == GPIO_OK) {
			for (Colscounter = LOOP_STARTING_VALUE;Colscounter < KEYPAD_COLUMNS_SIZE;Colscounter++) {

				ST_GPIO_cfg_t tempStructForColPin =
				{
						.pinDirection = GPIO_INPUT,
						.logicOnPin = GPIO_HIGH,
						.portName = ST_ptrKeypadInstance->arrOfColumnPorts[Colscounter],
						.pinNumber = ST_ptrKeypadInstance->arrOfColumnPins[Colscounter]
				};
				gpioRet = GPIO_initPin(&tempStructForColPin);
				if (gpioRet == GPIO_OK)
				{
					arrOfColumns[Colscounter] = tempStructForColPin;
					kpRet = EKP_OK;
				}
				else
				{
					kpRet = EKP_NOK;
					break;
				}

			}
		}
		else
		{
			kpRet = EKP_NOK;
		}

	}
	else
	{
		kpRet = EKP_PTR_NULL;
	}
	return kpRet;
}


EN_EKP_systemStatus_t
EKP_scanningForPressedBtn(uint8_t *pressedBtnVal) {

	EN_EKP_systemStatus_t kpRet = EKP_NOK;
	EN_GPIO_systemState_t gpioRet = GPIO_NOK;

	if (PTR_NULL != pressedBtnVal) {
		uint8_t Rowscounter, Colscounter;
		EN_GPIO_pinLogic_t valOfPressedBtn;

		for (Rowscounter = LOOP_STARTING_VALUE;Rowscounter<KEYPAD_ROWS_SIZE;Rowscounter++) {

			gpioRet = GPIO_writePinLogic(&(arrOfRows[Rowscounter]),GPIO_LOW);

			for (Colscounter = LOOP_STARTING_VALUE;Colscounter<KEYPAD_COLUMNS_SIZE;Colscounter++) {

				gpioRet = GPIO_readPinLogic(&(arrOfColumns[Colscounter]),&valOfPressedBtn);

				if (valOfPressedBtn == GPIO_LOW) {
					while(valOfPressedBtn == GPIO_LOW)
					{
						gpioRet = GPIO_readPinLogic(&(arrOfColumns[Colscounter]),&valOfPressedBtn);
					}
					*pressedBtnVal =KEYPAD_arrBtnVal[Rowscounter][Colscounter];
					break;
				}
			}

			gpioRet = GPIO_writePinLogic(&(arrOfRows[Rowscounter]),GPIO_HIGH);
		}
	} else {
		kpRet = EKP_PTR_NULL;
	}
	return kpRet;
}
