/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 11_Lec_4_Assignment_1                                    	 
// File          : calc_prog.c                                  	     
// Date          : 23 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "calc_interface.h"

	EN_CALC_states_t statesOfCalc = CALC_SCANNING;
	uint8_t pressedKeyVal = '#';
	uint8_t operandNumberFlag = 0;
	uint8_t counterOfOperandOneArr = 0;
	uint8_t counterOfOperandTwoArr = 0;
	uint8_t operator = '#';
	uint32_t operandOneVal = 0;
	uint32_t operandTwoVal = 0;
	uint32_t result = 0;

	uint8_t operandOne[OPERAND_MAX_SIZE];
	uint8_t operandTwo[OPERAND_MAX_SIZE];


void CALC_interface(void)
{
	while(1)
	{
		switch(statesOfCalc)
		{

		case CALC_SCANNING :
		{
			HKP_scanningForPressedBtn(&pressedKeyVal);
			while(pressedKeyVal == '#')
			{
				HKP_scanningForPressedBtn(&pressedKeyVal);
			}
			HLCD_displayChar(&myLcd,pressedKeyVal);
			statesOfCalc = CALC_CHECK_INPUT;
			break;
		}

		case CALC_CHECK_INPUT :
		{
			CALC_checkInput();
			break;
		}

		case CALC_FIRST_OPERAND_SAVE :
		{
			CALC_saveFirstOperand();
			break;
		}

		case CALC_SECOND_OPERAND_SAVE :
		{
			CALC_saveSecondOperand();
			break;
		}

		case CALC_OPERATOR_SAVE :
		{
			CALC_saveOperator();
			break;
		}

		case CALC_GET_THE_TWO_OPERAND :
		{
			CALC_getValueOfOperand();
			break;
		}

		case CALC_GET_RESUALT :
		{
			CALC_getResult();
			break;
		}
		case CALC_DISPLAY_RESULT :
		{
			CALC_afterResult();
			break;
		}
		case CALC_CLR_LCD :
		{
			CALC_clrDisplay();
			break;
		}

		case CALC_INVALID_PARAMTERS :
		{
			HLCD_Clr(&myLcd);
			HLCD_displayString(&myLcd,(uint8_t)"Invalid Input");
			HLCD_changeCursorPosation(&myLcd,1,0);
			HLCD_displayString(&myLcd,(uint8_t)"Try Again");
			HLCD_Clr(&myLcd);
			pressedKeyVal = '#';
			statesOfCalc = CALC_CLR_LCD;
			break;
		}

		default:
		{

			break;
		}
		}
	}
}


void CALC_checkInput(void)
{
	if((pressedKeyVal >= '0') && (pressedKeyVal <= '9'))
	{
		if(operandNumberFlag == 0)
		{
			statesOfCalc = CALC_FIRST_OPERAND_SAVE;
		}
		else if(operandNumberFlag == 1)
		{
			statesOfCalc = CALC_SECOND_OPERAND_SAVE;
		}
		else
		{
			/* Do Nothing */
		}
	}
	else if((pressedKeyVal == '+') || (pressedKeyVal == '-') || (pressedKeyVal == '*') || (pressedKeyVal == '/') )
	{
		operandNumberFlag = 1;
		statesOfCalc = CALC_OPERATOR_SAVE;
	}
	else if(pressedKeyVal == 'c')
	{
		statesOfCalc = CALC_CLR_LCD;
	}
	else if(pressedKeyVal == '=')
	{
		statesOfCalc = CALC_GET_THE_TWO_OPERAND;
	}
	else
	{
		statesOfCalc = CALC_INVALID_PARAMTERS;
	}
}

void CALC_saveFirstOperand(void)
{
	operandOne[counterOfOperandOneArr] = pressedKeyVal;
	counterOfOperandOneArr++;
	pressedKeyVal = '#';
	statesOfCalc = CALC_SCANNING;
}

void CALC_saveSecondOperand(void)
{
	operandTwo[counterOfOperandTwoArr] = pressedKeyVal;
	counterOfOperandTwoArr++;
	pressedKeyVal = '#';
	statesOfCalc = CALC_SCANNING;
}

void CALC_saveOperator(void)
{
	operator = pressedKeyVal;
	pressedKeyVal = '#';
	statesOfCalc = CALC_SCANNING;
}

void CALC_getValueOfOperand(void)
{
	operandOneVal = atoi((char *)operandOne);
	operandTwoVal = atoi((char *)operandTwo);
	statesOfCalc = CALC_GET_RESUALT;
}

void CALC_getResult(void)
{
	if(operator == '+')
	{
		result = operandOneVal + operandTwoVal;
		statesOfCalc = CALC_DISPLAY_RESULT;
	}
	else if(operator == '-')
	{
		result = operandOneVal - operandTwoVal;
		statesOfCalc = CALC_DISPLAY_RESULT;
	}
	else if(operator == '*')
	{
		result = operandOneVal * operandTwoVal;
		statesOfCalc = CALC_DISPLAY_RESULT;
	}
	else if(operator == '/')
	{
		result = operandOneVal / operandTwoVal;
		statesOfCalc = CALC_DISPLAY_RESULT;
	}
	else
	{
		statesOfCalc = CALC_INVALID_PARAMTERS;
	}
}

void CALC_afterResult(void)
{
	HLCD_displayNumber(&myLcd,result);
	pressedKeyVal = '#';
	operandNumberFlag = 0;
	counterOfOperandOneArr = 0;
	counterOfOperandTwoArr = 0;
	operator = '#';
	operandOneVal = 0;
	operandTwoVal = 0;

	memset(operandOne , 0 , sizeof(operandOne));
	memset(operandTwo , 0 , sizeof(operandTwo));
	statesOfCalc = CALC_SCANNING;
}

void CALC_clrDisplay(void)
{
	HLCD_Clr(&myLcd);
	pressedKeyVal = '#';
	operandNumberFlag = 0;
	counterOfOperandOneArr = 0;
	counterOfOperandTwoArr = 0;
	operator = '#';
	operandOneVal = 0;
	operandTwoVal = 0;

	memset(operandOne , 0 , sizeof(operandOne));
	memset(operandTwo , 0 , sizeof(operandTwo));
	statesOfCalc = CALC_SCANNING;

}

