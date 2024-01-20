/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : nvic_config.h                                  	     
// Date          : Sep 10, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_NVIC_NVIC_CONFIG_H_
#define MCAL_NVIC_NVIC_CONFIG_H_

#define POS_OF_FIRST_INT			0
#define POS_OF_LAST_INT				84

#define getIntRegNumber(IntNumber)		(IntNumber / 32)
#define getIntBitNumber(IntNumber)		(IntNumber % 32)


typedef enum
{
	MNVIC_OK = 0,
	MNVIC_NOK,
	MNVIC_INVALID_PARAMTER
}EN_MNVIC_systemState_t;


typedef enum
{
	GP_16_SP_00	= 0,
	GP_08_SP_02,
	GP_04_SP_04,
	GP_02_SP_08,
	GP_00_SP_16,
}EN_MNVIC_priorityGrouping_t;


#endif /* MCAL_NVIC_NVIC_CONFIG_H_ */
