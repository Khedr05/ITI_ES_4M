/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : exti_config.h                                  	     
// Date          : 14 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

typedef enum
{
	MEXTI_OK = 0,
	MEXTI_NOK,
	MEXTI_PTR_NULL,
	MEXTI_INVALID_PARAMTER
}EN_MEXTI_systemState_t;

typedef enum
{
	MEXTI_LOW_LEVEL_SENSE_CONTROL = 0,
	MEXTI_ANY_LOGICAL_SENSE_CONTROL,
	MEXTI_FALLING_EDGE_SENSE_CONTROL,
	MEXTI_RISING_EDGE_SENSE_CONTROL

}EN_MEXTI_SenseControl_t;


typedef enum
{
	MEXTI_EXTI0_INTERRUPT = 0,
	MEXTI_EXTI1_INTERRUPT,
	MEXTI_EXTI2_INTERRUPT
}EN_MEXTI_interruptsPins_t;


typedef struct
{
	void(*MEXTI_ptrCallbackHandler)(void);
	EN_MEXTI_interruptsPins_t   numberOfExti;
	EN_MEXTI_SenseControl_t 	extiTriggerSence;

}ST_MEXTI_cfg_t;

#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
