/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : systick_config.h                                  	     
// Date          : Sep 12, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_SYSTICK_SYSTICK_CONFIG_H_
#define MCAL_SYSTICK_SYSTICK_CONFIG_H_


#define MIN_VAL_OF_U32				0
#define MAX_VAL_OF_U32				0xFFFFFFFF

#define MSTK_IntervalSingle			0
#define MSTK_IntervalPeriodic		1

typedef enum
{
	MSTK_OK = 0,
	MSTK_NOK,
	MSTK_INVALID_PARAMTER
}EN_MSTK_systemState_t;


typedef enum
{
	MSTK_CLK_AHB_8 = 0,
	MSTK_CLK_PROCESSOR_AHB
}EN_MSTK_clkSourceOptions_t;

typedef enum
{
	MSTK_INTERRUPT_ENABLED = 0,
	MSTK_INTERRUPT_DISABLED
}EN_MSTK_interruptStates_t;

#endif /* MCAL_SYSTICK_SYSTICK_CONFIG_H_ */
