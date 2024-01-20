/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : nvic_interface.h                                  	     
// Date          : Sep 10, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "nvic_private.h"
#include "nvic_config.h"


EN_MNVIC_systemState_t MNVIC_enableInterrupt(uint8_t copy_u8IntPos);
EN_MNVIC_systemState_t MNVIC_disableInterrupt(uint8_t copy_u8IntPos);

EN_MNVIC_systemState_t MNVIC_enableInterruptPending(uint8_t copy_u8IntPos);
EN_MNVIC_systemState_t MNVIC_disableInterruptPending(uint8_t copy_u8IntPos);

EN_MNVIC_systemState_t MNVIC_IsInterruptActive(uint8_t copy_u8IntPos , uint8_t *ptrOfRetReading);

EN_MNVIC_systemState_t MNVIC_SetInterruptPriority(uint8_t copy_u8IntPos , EN_MNVIC_priorityGrouping_t copy_uddtGroupOption ,uint8_t copy_u8GroupPriority , uint8_t copy_u8SubPriority);
EN_MNVIC_systemState_t MNVIC_SetInterruptGroup(EN_MNVIC_priorityGrouping_t copy_uddtGroupOption);


#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
