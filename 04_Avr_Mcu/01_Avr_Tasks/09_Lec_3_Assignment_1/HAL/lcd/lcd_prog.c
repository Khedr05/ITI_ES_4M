/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : lcd_prog.c                                  	     
// Date          : 12 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/


#include "lcd_interface.h"


EN_HLCD_systemState_t HLCD_init(ST_HLCD_cfg_t const *ST_ptrLcdCfgInstance)
{
	EN_HLCD_systemState_t lcdRet = HLCD_NOK;
	EN_GPIO_systemState_t gpioRet = GPIO_NOK;

	if(PTR_NULL != ST_ptrLcdCfgInstance)
	{

		if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_4_BIT_MODE)
		{
			/* TODO : Handling The 4bit Mode */
		}
		else if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_8_BIT_MODE)
		{
			ST_GPIO_cfg_t rsPin =
			{
					.portName = ST_ptrLcdCfgInstance->controlPort,
					.pinNumber = ST_ptrLcdCfgInstance->rsPin,
					.logicOnPin = GPIO_LOW,
					.pinDirection = GPIO_OUTPUT
			};

			ST_GPIO_cfg_t rwPin =
			{
					.portName = ST_ptrLcdCfgInstance->controlPort,
					.pinNumber = ST_ptrLcdCfgInstance->rwPin,
					.logicOnPin = GPIO_LOW,
					.pinDirection = GPIO_OUTPUT
			};

			ST_GPIO_cfg_t enPin =
			{
					.portName = ST_ptrLcdCfgInstance->controlPort,
					.pinNumber = ST_ptrLcdCfgInstance->enPin,
					.logicOnPin = GPIO_LOW,
					.pinDirection = GPIO_OUTPUT
			};


			gpioRet = GPIO_initPin(&rsPin);

			if(gpioRet == GPIO_OK)gpioRet = GPIO_initPin(&rwPin);
			else lcdRet = HLCD_NOK;

			if(gpioRet == GPIO_OK)gpioRet = GPIO_initPin(&enPin);
			else lcdRet = HLCD_NOK;

			if(gpioRet == GPIO_OK)gpioRet = GPIO_initPort(ST_ptrLcdCfgInstance->dataPort,GPIO_OUTPUT,GPIO_LOW);
			else lcdRet = HLCD_NOK;

			_delay_ms(1);

			if(gpioRet == GPIO_OK)lcdRet = HLCD_sendCmd(ST_ptrLcdCfgInstance,TWO_LINE_LCD_EIGHT_BIT_MODE);
			else lcdRet = HLCD_NOK;

			_delay_ms(1);

			if(lcdRet == HLCD_OK)lcdRet = HLCD_sendCmd(ST_ptrLcdCfgInstance,CURSOR_OFF);
			else lcdRet = HLCD_NOK;

			_delay_ms(1);

			if(lcdRet == HLCD_OK)lcdRet = HLCD_sendCmd(ST_ptrLcdCfgInstance,CLEAR_COMMAND);
			else lcdRet = HLCD_NOK;

			_delay_ms(1);

		}
		else
		{
			lcdRet = HLCD_INVALID_DATA_BIT_MODE;
		}


	}
	else
	{
		lcdRet = HLCD_PTR_NULL;
	}

	return lcdRet;
}

EN_HLCD_systemState_t HLCD_sendCmd(ST_HLCD_cfg_t const *ST_ptrLcdCfgInstance , uint8_t Copy_u8Command)
{
	EN_HLCD_systemState_t lcdRet = HLCD_NOK;
	EN_GPIO_systemState_t gpioRet = GPIO_NOK;

	if(PTR_NULL != ST_ptrLcdCfgInstance)
	{
		if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_4_BIT_MODE)
		{
			/* TODO : Handling The 4bit Mode */
		}
		else if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_8_BIT_MODE)
		{
			ST_GPIO_cfg_t rsPin =
			{
					.portName = ST_ptrLcdCfgInstance->controlPort,
					.pinNumber = ST_ptrLcdCfgInstance->rsPin,
					.logicOnPin = GPIO_LOW,
					.pinDirection = GPIO_OUTPUT
			};

			ST_GPIO_cfg_t rwPin =
			{
					.portName = ST_ptrLcdCfgInstance->controlPort,
					.pinNumber = ST_ptrLcdCfgInstance->rwPin,
					.logicOnPin = GPIO_LOW,
					.pinDirection = GPIO_OUTPUT
			};

			ST_GPIO_cfg_t enPin =
			{
					.portName = ST_ptrLcdCfgInstance->controlPort,
					.pinNumber = ST_ptrLcdCfgInstance->enPin,
					.logicOnPin = GPIO_LOW,
					.pinDirection = GPIO_OUTPUT
			};

			gpioRet = GPIO_writePinLogic(&rsPin,GPIO_LOW);
			if(gpioRet == GPIO_OK)gpioRet = GPIO_writePinLogic(&rwPin,GPIO_LOW);
			else lcdRet = HLCD_NOK;

			_delay_ms(1);

			if(gpioRet == GPIO_OK)gpioRet = GPIO_writePinLogic(&enPin,GPIO_HIGH);
			else lcdRet = HLCD_NOK;

			_delay_ms(1);

			GPIO_SetPortValue(ST_ptrLcdCfgInstance->dataPort, Copy_u8Command);

			_delay_ms(1);

			if(gpioRet == GPIO_OK)gpioRet = GPIO_writePinLogic(&enPin,GPIO_LOW);
			else lcdRet = HLCD_NOK;

			_delay_ms(1);

			if(gpioRet == GPIO_OK)lcdRet = HLCD_OK;
			else lcdRet = HLCD_NOK;

		}
		else
		{
			lcdRet = HLCD_INVALID_DATA_BIT_MODE;
		}
	}
	else
	{
		lcdRet = HLCD_NOK;
	}

	return lcdRet;
}

EN_HLCD_systemState_t HLCD_displayChar(ST_HLCD_cfg_t const *ST_ptrLcdCfgInstance , uint8_t Copy_u8Char)
{
	EN_HLCD_systemState_t lcdRet = HLCD_NOK;
	EN_GPIO_systemState_t gpioRet = GPIO_NOK;

	if(PTR_NULL != ST_ptrLcdCfgInstance)
	{
		if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_4_BIT_MODE)
		{
			/* TODO : Handling The 4bit Mode */
		}
		else if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_8_BIT_MODE)
		{
			ST_GPIO_cfg_t rsPin =
			{
					.portName = ST_ptrLcdCfgInstance->controlPort,
					.pinNumber = ST_ptrLcdCfgInstance->rsPin,
					.logicOnPin = GPIO_LOW,
					.pinDirection = GPIO_OUTPUT
			};

			ST_GPIO_cfg_t rwPin =
			{
					.portName = ST_ptrLcdCfgInstance->controlPort,
					.pinNumber = ST_ptrLcdCfgInstance->rwPin,
					.logicOnPin = GPIO_LOW,
					.pinDirection = GPIO_OUTPUT
			};

			ST_GPIO_cfg_t enPin =
			{
					.portName = ST_ptrLcdCfgInstance->controlPort,
					.pinNumber = ST_ptrLcdCfgInstance->enPin,
					.logicOnPin = GPIO_LOW,
					.pinDirection = GPIO_OUTPUT
			};

			gpioRet = GPIO_writePinLogic(&rsPin,GPIO_HIGH);
			if(gpioRet == GPIO_OK)gpioRet = GPIO_writePinLogic(&rwPin,GPIO_LOW);
			else lcdRet = HLCD_NOK;

			_delay_ms(1);

			if(gpioRet == GPIO_OK)gpioRet = GPIO_writePinLogic(&enPin,GPIO_HIGH);
			else lcdRet = HLCD_NOK;

			_delay_ms(1);

			GPIO_SetPortValue(ST_ptrLcdCfgInstance->dataPort, Copy_u8Char);


			_delay_ms(1);

			if(gpioRet == GPIO_OK)gpioRet = GPIO_writePinLogic(&enPin,GPIO_LOW);
			else lcdRet = HLCD_NOK;

			_delay_ms(1);

			if(gpioRet == GPIO_OK)lcdRet = HLCD_OK;
			else lcdRet = HLCD_NOK;

		}
		else
		{
			lcdRet = HLCD_INVALID_DATA_BIT_MODE;
		}
	}
	else
	{
		lcdRet = HLCD_NOK;
	}

	return lcdRet;
}

EN_HLCD_systemState_t HLCD_displayString(ST_HLCD_cfg_t const *ST_ptrLcdCfgInstance ,uint8_t *Copy_u8String)
{
	EN_HLCD_systemState_t lcdRet = HLCD_NOK;

	if(PTR_NULL != ST_ptrLcdCfgInstance)
	{
		if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_4_BIT_MODE)
		{
			/* TODO : Handling The 4bit Mode */
		}
		else if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_8_BIT_MODE)
		{
			uint8_t strCounter;

			for(strCounter = 0;(*(Copy_u8String+strCounter) != STR_NULL);strCounter++)
			{
				lcdRet = HLCD_displayChar(ST_ptrLcdCfgInstance,(*(Copy_u8String+strCounter)));
			}
		}
		else
		{
			lcdRet = HLCD_INVALID_DATA_BIT_MODE;
		}
	}
	else
	{
		lcdRet = HLCD_PTR_NULL;
	}
	return lcdRet;
}

EN_HLCD_systemState_t HLCD_displayNumber(ST_HLCD_cfg_t const *ST_ptrLcdCfgInstance , uint32_t Copy_u8Number)
{
	EN_HLCD_systemState_t lcdRet = HLCD_NOK;

	if(PTR_NULL != ST_ptrLcdCfgInstance)
	{
		if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_4_BIT_MODE)
		{
			/* TODO : Handling The 4bit Mode */
		}
		else if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_8_BIT_MODE)
		{
			uint8_t numberCounter = 0;
			uint8_t digitsCounter = 0;
			uint8_t bufferForNumbers[11];

			if(Copy_u8Number == 0)
			{
				lcdRet = HLCD_displayChar(ST_ptrLcdCfgInstance,'0');
			}
			else
			{
				while(Copy_u8Number)
				{
					if(digitsCounter == 0)
					{
						bufferForNumbers[digitsCounter] = STR_NULL;
						digitsCounter++;
					}
					else
					{
						bufferForNumbers[digitsCounter] = Copy_u8Number%10;
						Copy_u8Number /=10;
						digitsCounter++;
					}
				}

				numberCounter = (digitsCounter-1);
				for(; bufferForNumbers[numberCounter] != STR_NULL ; numberCounter--)
				{
					lcdRet = HLCD_displayChar(ST_ptrLcdCfgInstance,((bufferForNumbers[numberCounter])+48));
				}
			}
		}
		else
		{
			lcdRet = HLCD_INVALID_DATA_BIT_MODE;
		}
	}
	else
	{
		lcdRet = HLCD_PTR_NULL;
	}
	return lcdRet;
}

EN_HLCD_systemState_t HLCD_changeCursorPosation(ST_HLCD_cfg_t const *ST_ptrLcdCfgInstance , uint8_t Copy_u8Row,uint8_t Copy_u8Column)
{
	EN_HLCD_systemState_t lcdRet = HLCD_NOK;

	if(PTR_NULL != ST_ptrLcdCfgInstance)
	{
		if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_4_BIT_MODE)
		{
			/* TODO : Handling The 4bit Mode */
		}
		else if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_8_BIT_MODE)
		{
			if (Copy_u8Row == ROW_ZERO && Copy_u8Column<MAX_NUMBER_OF_COLUMNS)
				lcdRet = HLCD_sendCmd(ST_ptrLcdCfgInstance , ((Copy_u8Column & 0x0F)|0x80));
			else if (Copy_u8Row == ROW_ONE && Copy_u8Column<MAX_NUMBER_OF_COLUMNS)
				lcdRet = HLCD_sendCmd(ST_ptrLcdCfgInstance , ((Copy_u8Column & 0x0F)|0xC0));
			else lcdRet = HLCD_INVALID_PARAMTERS;
		}
		else
		{
			lcdRet = HLCD_INVALID_DATA_BIT_MODE;
		}
	}
	else
	{
		lcdRet = HLCD_PTR_NULL;
	}
	return lcdRet;
}

EN_HLCD_systemState_t HLCD_shiftDisplay(ST_HLCD_cfg_t const *ST_ptrLcdCfgInstance ,uint8_t Copy_u8ShiftItirations,uint8_t Copy_u8ShiftDirection)
{
	EN_HLCD_systemState_t lcdRet = HLCD_NOK;

	if(PTR_NULL != ST_ptrLcdCfgInstance)
	{
		if(Copy_u8ShiftDirection == RIGHT || Copy_u8ShiftDirection == LEFT)
		{
			if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_4_BIT_MODE)
			{
				/* TODO : Handling The 4bit Mode */
			}
			else if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_8_BIT_MODE)
			{
				uint8_t loopCounter;
				for(loopCounter = 0;loopCounter<Copy_u8ShiftItirations;loopCounter++)
				{
					lcdRet = HLCD_sendCmd(ST_ptrLcdCfgInstance ,Copy_u8ShiftDirection);
				}
			}
			else
			{
				lcdRet = HLCD_INVALID_DATA_BIT_MODE;
			}
		}
		else
		{
			lcdRet = HLCD_INVALID_PARAMTERS;
		}
	}
	else
	{
		lcdRet = HLCD_PTR_NULL;
	}
	return lcdRet;
}

EN_HLCD_systemState_t HLCD_createNewCustomChar(ST_HLCD_cfg_t const *ST_ptrLcdCfgInstance , uint8_t *Copy_u8ArrayOfChar , uint8_t Copy_u8CgramPosition)
{
	EN_HLCD_systemState_t lcdRet = HLCD_NOK;

	if(PTR_NULL != ST_ptrLcdCfgInstance && PTR_NULL != Copy_u8ArrayOfChar)
	{
		if((Copy_u8CgramPosition >= 0) && (Copy_u8CgramPosition <= 7))
		{
			if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_4_BIT_MODE)
			{
				/* TODO : Handling The 4bit Mode */
			}
			else if(ST_ptrLcdCfgInstance->dataPinsMode == HLCD_8_BIT_MODE)
			{
				uint8_t loopCounter;

				lcdRet = HLCD_sendCmd(ST_ptrLcdCfgInstance , SET_CGRAM_LOCATION|(Copy_u8CgramPosition*8));
				if(lcdRet == HLCD_OK)
				{
					for(loopCounter = 0;loopCounter<8;loopCounter++)
					{
						lcdRet = HLCD_displayChar(ST_ptrLcdCfgInstance,Copy_u8ArrayOfChar[loopCounter]);
						if(lcdRet != HLCD_OK) break; else /*Do Notjhint*/;
					}
				}
				else
				{
					/* Do Nothing */
				}

				lcdRet = HLCD_sendCmd(ST_ptrLcdCfgInstance ,SET_CURSOR_LOCATION);
			}
			else
			{
				lcdRet = HLCD_INVALID_DATA_BIT_MODE;
			}
		}
		else
		{
			lcdRet = HLCD_INVALID_PARAMTERS;
		}
	}
	else
	{
		lcdRet = HLCD_PTR_NULL;
	}
	return lcdRet;
}



EN_HLCD_systemState_t HLCD_Clr(ST_HLCD_cfg_t const *ST_ptrLcdCfgInstance)
{
	EN_HLCD_systemState_t lcdRet = HLCD_NOK;

	lcdRet = HLCD_sendCmd(ST_ptrLcdCfgInstance, CLEAR_COMMAND);

	return lcdRet;
}
