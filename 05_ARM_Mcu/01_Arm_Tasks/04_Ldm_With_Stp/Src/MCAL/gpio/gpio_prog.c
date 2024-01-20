/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : gpio_prog.c                                  	     
// Date          : Sep 10, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/MCAL/gpio/gpio_interface.h"


EN_MGPIO_systemState_t MGPIO_setPinMode (EN_MGPIO_portOptions_t copy_uddtPortName ,EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_pinModeOptions_t copy_uddtPinMode)
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((copy_uddtPortName >= MGPIO_PORTA && copy_uddtPortName <= MGPIO_PORTH)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (copy_uddtPinMode >= MGPIO_MODE_OUTPUT && copy_uddtPinMode <= MGPIO_MODE_ANALOG))
	{
		switch(copy_uddtPortName)
		{
			case MGPIO_PORTA :
			{
				MGPIOA_PERIPHERAL->MGPIOx_MODER |= (uint32_t) (copy_uddtPinMode <<((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTB :
			{
				MGPIOB_PERIPHERAL->MGPIOx_MODER |= (uint32_t) (copy_uddtPinMode <<((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTC :
			{
				MGPIOC_PERIPHERAL->MGPIOx_MODER |= (uint32_t) (copy_uddtPinMode <<((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTD :
			{
				MGPIOD_PERIPHERAL->MGPIOx_MODER |= (uint32_t) (copy_uddtPinMode <<((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTE :
			{
				MGPIOE_PERIPHERAL->MGPIOx_MODER |= (uint32_t) (copy_uddtPinMode <<((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTH :
			{
				MGPIOH_PERIPHERAL->MGPIOx_MODER |= (uint32_t) (copy_uddtPinMode <<((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			default :
			{
				ret = MGPIO_INVALID_PARAMTER;
				break;
			}
		}
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}




EN_MGPIO_systemState_t MGPIO_setOutputMode (EN_MGPIO_portOptions_t copy_uddtPortName , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_outputResistorOptions_t copy_uddtOutputResistor)
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((copy_uddtPortName >= MGPIO_PORTA && copy_uddtPortName <= MGPIO_PORTH)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (copy_uddtOutputResistor >= MGPIO_OUTPUT_RESISTOR_PUSH_PULL && copy_uddtOutputResistor <= MGPIO_OUTPUT_RESISTOR_OPEN_DRAIN))
	{
		switch(copy_uddtPortName)
		{
			case MGPIO_PORTA :
			{
				MGPIOA_PERIPHERAL->MGPIOx_OTYPER |= (uint32_t) (copy_uddtOutputResistor << copy_uddtPinNum);
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTB :
			{
				MGPIOB_PERIPHERAL->MGPIOx_OTYPER |= (uint32_t) (copy_uddtOutputResistor << copy_uddtPinNum);
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTC :
			{
				MGPIOC_PERIPHERAL->MGPIOx_OTYPER |= (uint32_t) (copy_uddtOutputResistor << copy_uddtPinNum);
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTD :
			{
				MGPIOD_PERIPHERAL->MGPIOx_OTYPER |= (uint32_t) (copy_uddtOutputResistor << copy_uddtPinNum);
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTE :
			{
				MGPIOE_PERIPHERAL->MGPIOx_OTYPER |= (uint32_t) (copy_uddtOutputResistor << copy_uddtPinNum);
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTH :
			{
				MGPIOH_PERIPHERAL->MGPIOx_OTYPER |= (uint32_t) (copy_uddtOutputResistor << copy_uddtPinNum);
				ret = MGPIO_OK;
				break;
			}
			default :
			{
				ret = MGPIO_INVALID_PARAMTER;
				break;
			}
		}
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}


EN_MGPIO_systemState_t MGPIO_setOutputSpeed  (EN_MGPIO_portOptions_t copy_uddtPortName , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_outputSpeedOptions_t copy_uddtOutputSpeed )
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((copy_uddtPortName >= MGPIO_PORTA && copy_uddtPortName <= MGPIO_PORTH)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (copy_uddtOutputSpeed >= MGPIO_OUTPUT_SPEED_LOW && copy_uddtOutputSpeed <= MGPIO_OUTPUT_SPEED_VERY_HIGH))
	{
		switch(copy_uddtPortName)
		{
			case MGPIO_PORTA :
			{
				MGPIOA_PERIPHERAL->MGPIOx_OSPEEDR |= (uint32_t) (copy_uddtOutputSpeed << ((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTB :
			{
				MGPIOB_PERIPHERAL->MGPIOx_OSPEEDR |= (uint32_t) (copy_uddtOutputSpeed << ((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTC :
			{
				MGPIOC_PERIPHERAL->MGPIOx_OSPEEDR |= (uint32_t) (copy_uddtOutputSpeed << ((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTD :
			{
				MGPIOD_PERIPHERAL->MGPIOx_OSPEEDR |= (uint32_t) (copy_uddtOutputSpeed << ((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTE :
			{
				MGPIOE_PERIPHERAL->MGPIOx_OSPEEDR |= (uint32_t) (copy_uddtOutputSpeed << ((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTH :
			{
				MGPIOH_PERIPHERAL->MGPIOx_OSPEEDR |= (uint32_t) (copy_uddtOutputSpeed << ((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			default :
			{
				ret = MGPIO_INVALID_PARAMTER;
				break;
			}
		}
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}


EN_MGPIO_systemState_t MGPIO_setPullState  (EN_MGPIO_portOptions_t copy_uddtPortName , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_pushPullOptions_t copy_uddtPullState )
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((copy_uddtPortName >= MGPIO_PORTA && copy_uddtPortName <= MGPIO_PORTH)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (copy_uddtPullState >= MGPIO_PULL_FLOATING && copy_uddtPullState <= MGPIO_PULL_PULL_DOWN))
	{
		switch(copy_uddtPortName)
		{
			case MGPIO_PORTA :
			{
				MGPIOA_PERIPHERAL->MGPIOx_PUPDR |= (uint32_t) (copy_uddtPullState << ((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTB :
			{
				MGPIOB_PERIPHERAL->MGPIOx_PUPDR |= (uint32_t) (copy_uddtPullState << ((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTC :
			{
				MGPIOC_PERIPHERAL->MGPIOx_PUPDR |= (uint32_t) (copy_uddtPullState << ((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTD :
			{
				MGPIOD_PERIPHERAL->MGPIOx_PUPDR |= (uint32_t) (copy_uddtPullState << ((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTE :
			{
				MGPIOE_PERIPHERAL->MGPIOx_PUPDR |= (uint32_t) (copy_uddtPullState << ((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTH :
			{
				MGPIOH_PERIPHERAL->MGPIOx_PUPDR |= (uint32_t) (copy_uddtPullState << ((2U) * copy_uddtPinNum));
				ret = MGPIO_OK;
				break;
			}
			default :
			{
				ret = MGPIO_INVALID_PARAMTER;
				break;
			}
		}
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}

EN_MGPIO_systemState_t MGPIO_getPinVal  (EN_MGPIO_portOptions_t copy_uddtPortName , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_pinLogicOptions_t *copy_uddtPtrRetOfPinLogic)
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((copy_uddtPortName >= MGPIO_PORTA && copy_uddtPortName <= MGPIO_PORTH)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (PTR_NULL != copy_uddtPtrRetOfPinLogic))
	{
		switch(copy_uddtPortName)
		{
			case MGPIO_PORTA :
			{
				*copy_uddtPtrRetOfPinLogic = GET_BIT(MGPIOA_PERIPHERAL->MGPIOx_IDR , copy_uddtPinNum);
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTB :
			{
				*copy_uddtPtrRetOfPinLogic = GET_BIT(MGPIOA_PERIPHERAL->MGPIOx_IDR , copy_uddtPinNum);
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTC :
			{
				*copy_uddtPtrRetOfPinLogic = GET_BIT(MGPIOA_PERIPHERAL->MGPIOx_IDR , copy_uddtPinNum);
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTD :
			{
				*copy_uddtPtrRetOfPinLogic = GET_BIT(MGPIOA_PERIPHERAL->MGPIOx_IDR , copy_uddtPinNum);
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTE :
			{
				*copy_uddtPtrRetOfPinLogic = GET_BIT(MGPIOA_PERIPHERAL->MGPIOx_IDR , copy_uddtPinNum);
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTH :
			{
				*copy_uddtPtrRetOfPinLogic = GET_BIT(MGPIOA_PERIPHERAL->MGPIOx_IDR , copy_uddtPinNum);
				ret = MGPIO_OK;
				break;
			}
			default :
			{
				ret = MGPIO_INVALID_PARAMTER;
				break;
			}
		}
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}

EN_MGPIO_systemState_t MGPIO_setPinVal(EN_MGPIO_portOptions_t copy_uddtPortName , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_pinLogicOptions_t copy_uddtPinLogic)
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((copy_uddtPortName >= MGPIO_PORTA && copy_uddtPortName <= MGPIO_PORTH)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (copy_uddtPinLogic >= MGPIO_LOGIC_LOW && copy_uddtPinLogic <= MGPIO_LOGIC_HIGH))
	{
		if(copy_uddtPinLogic == MGPIO_LOGIC_HIGH)
		{
			switch(copy_uddtPortName)
			{
				case MGPIO_PORTA :
				{
					SET_BIT(MGPIOA_PERIPHERAL->MGPIOx_ODR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTB :
				{
					SET_BIT(MGPIOB_PERIPHERAL->MGPIOx_ODR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTC :
				{
					SET_BIT(MGPIOC_PERIPHERAL->MGPIOx_ODR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTD :
				{
					SET_BIT(MGPIOD_PERIPHERAL->MGPIOx_ODR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTE :
				{
					SET_BIT(MGPIOE_PERIPHERAL->MGPIOx_ODR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTH :
				{
					SET_BIT(MGPIOH_PERIPHERAL->MGPIOx_ODR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				default :
				{
					ret = MGPIO_INVALID_PARAMTER;
					break;
				}
			}
		}
		else if(copy_uddtPinLogic == MGPIO_LOGIC_LOW)
		{
			switch(copy_uddtPortName)
			{
				case MGPIO_PORTA :
				{
					CLR_BIT(MGPIOA_PERIPHERAL->MGPIOx_ODR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTB :
				{
					CLR_BIT(MGPIOB_PERIPHERAL->MGPIOx_ODR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTC :
				{
					CLR_BIT(MGPIOC_PERIPHERAL->MGPIOx_ODR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTD :
				{
					CLR_BIT(MGPIOD_PERIPHERAL->MGPIOx_ODR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTE :
				{
					CLR_BIT(MGPIOE_PERIPHERAL->MGPIOx_ODR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTH :
				{
					CLR_BIT(MGPIOH_PERIPHERAL->MGPIOx_ODR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				default :
				{
					ret = MGPIO_INVALID_PARAMTER;
					break;
				}
			}
		}
		else
		{
			ret = MGPIO_INVALID_PARAMTER;
		}
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}

EN_MGPIO_systemState_t MGPIO_directSetReset (EN_MGPIO_portOptions_t copy_uddtPortName , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_setResetOptions_t copy_uddtSetResetState )
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((copy_uddtPortName >= MGPIO_PORTA && copy_uddtPortName <= MGPIO_PORTH)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (copy_uddtSetResetState >= MGPIO_PIN_RESET && copy_uddtSetResetState <= MGPIO_PIN_SET))
	{
		if(copy_uddtSetResetState == MGPIO_PIN_SET)
		{
			switch(copy_uddtPortName)
			{
				case MGPIO_PORTA :
				{
					SET_BIT(MGPIOA_PERIPHERAL->MGPIOx_BSRR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTB :
				{
					SET_BIT(MGPIOB_PERIPHERAL->MGPIOx_BSRR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTC :
				{
					SET_BIT(MGPIOC_PERIPHERAL->MGPIOx_BSRR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTD :
				{
					SET_BIT(MGPIOD_PERIPHERAL->MGPIOx_BSRR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTE :
				{
					SET_BIT(MGPIOE_PERIPHERAL->MGPIOx_BSRR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTH :
				{
					SET_BIT(MGPIOH_PERIPHERAL->MGPIOx_BSRR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				default :
				{
					ret = MGPIO_INVALID_PARAMTER;
					break;
				}
			}
		}
		else if(copy_uddtSetResetState == MGPIO_PIN_RESET)
		{
			copy_uddtPinNum += 16;
			switch(copy_uddtPortName)
			{
				case MGPIO_PORTA :
				{
					CLR_BIT(MGPIOA_PERIPHERAL->MGPIOx_BSRR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTB :
				{
					CLR_BIT(MGPIOB_PERIPHERAL->MGPIOx_BSRR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTC :
				{
					CLR_BIT(MGPIOC_PERIPHERAL->MGPIOx_BSRR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTD :
				{
					CLR_BIT(MGPIOD_PERIPHERAL->MGPIOx_BSRR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTE :
				{
					CLR_BIT(MGPIOE_PERIPHERAL->MGPIOx_BSRR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				case MGPIO_PORTH :
				{
					CLR_BIT(MGPIOH_PERIPHERAL->MGPIOx_BSRR , copy_uddtPinNum);
					ret = MGPIO_OK;
					break;
				}
				default :
				{
					ret = MGPIO_INVALID_PARAMTER;
					break;
				}
			}
		}
		else
		{
			ret = MGPIO_INVALID_PARAMTER;
		}
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}


EN_MGPIO_systemState_t MGPIO_setPortVal(EN_MGPIO_portOptions_t copy_uddtPortName , uint16_t copy_u16OutputVal)
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((copy_uddtPortName >= MGPIO_PORTA && copy_uddtPortName <= MGPIO_PORTH)
		&&(copy_u16OutputVal >= MIN_VAL_OF_U16 && copy_u16OutputVal <= MAX_VAL_OF_U16))
	{
		switch(copy_uddtPortName)
		{
			case MGPIO_PORTA :
			{
				MGPIOA_PERIPHERAL->MGPIOx_ODR = (uint32_t) copy_u16OutputVal;
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTB :
			{
				MGPIOB_PERIPHERAL->MGPIOx_ODR = (uint32_t) copy_u16OutputVal;
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTC :
			{
				MGPIOC_PERIPHERAL->MGPIOx_ODR = (uint32_t) copy_u16OutputVal;
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTD :
			{
				MGPIOD_PERIPHERAL->MGPIOx_ODR = (uint32_t) copy_u16OutputVal;
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTE :
			{
				MGPIOE_PERIPHERAL->MGPIOx_ODR = (uint32_t) copy_u16OutputVal;
				ret = MGPIO_OK;
				break;
			}
			case MGPIO_PORTH :
			{
				MGPIOH_PERIPHERAL->MGPIOx_ODR = (uint32_t) copy_u16OutputVal;
				ret = MGPIO_OK;
				break;
			}
			default :
			{
				ret = MGPIO_INVALID_PARAMTER;
				break;
			}
		}
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}

EN_MGPIO_systemState_t MGPIO_SetAltFun (EN_MGPIO_portOptions_t copy_uddtPortName , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_altfnOptions_t Copy_uddtAltFun)
{
	if (copy_uddtPinNum <= 7U )
	{
		switch (copy_uddtPortName)
		{
			case MGPIO_PORTA : MGPIOA_PERIPHERAL->MGPIOx_AFRL  |= (Copy_uddtAltFun << 4U * (copy_uddtPinNum))  ; break ;

			case MGPIO_PORTB : MGPIOB_PERIPHERAL->MGPIOx_AFRL  |= (Copy_uddtAltFun << 4U * (copy_uddtPinNum))  ; break ;

			case MGPIO_PORTC : MGPIOC_PERIPHERAL->MGPIOx_AFRL  |= (Copy_uddtAltFun << 4U * (copy_uddtPinNum))  ; break ;
		}
	}

	else  if (copy_uddtPinNum <= 15U )
	{
		switch (copy_uddtPortName)
		{
			case MGPIO_PORTA : MGPIOA_PERIPHERAL->MGPIOx_AFRH  |= (Copy_uddtAltFun << 4U * (copy_uddtPinNum))  ; break ;

			case MGPIO_PORTB : MGPIOB_PERIPHERAL->MGPIOx_AFRH  |= (Copy_uddtAltFun << 4U * (copy_uddtPinNum))  ; break ;

			case MGPIO_PORTC : MGPIOC_PERIPHERAL->MGPIOx_AFRH  |= (Copy_uddtAltFun << 4U * (copy_uddtPinNum))  ; break ;
		}
	}

	else
	{
		// report error
	}

}

















