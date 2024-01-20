/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : systick_interface.h                                  	     
// Date          : Sep 12, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_SYSTICK_SYSTICK_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "../../COMMON/bit_math.h"
#include "systick_private.h"
#include "systick_config.h"

EN_MSTK_systemState_t	MSTK_init(EN_MSTK_clkSourceOptions_t copy_uddtClkSource , EN_MSTK_interruptStates_t copy_uddtIntStates);
EN_MSTK_systemState_t	MSTK_setBusyWait(uint32_t copy_u32NumberOfTicks);
EN_MSTK_systemState_t	MSTK_SetIntervalSingle(uint32_t copy_u32NumberOfTicks, void (*Pf)(void));
EN_MSTK_systemState_t	MSTK_SetIntervalPeriodic(uint32_t copy_u32NumberOfTicks, void (*Pf)(void));
EN_MSTK_systemState_t	MSTK_StopInterval(void);
EN_MSTK_systemState_t	MSTK_getElapsedTime(uint32_t *copy_u32PtrRetOfElapsedTicks);
EN_MSTK_systemState_t	MSTK_getRemainingTime(uint32_t *copy_u32PtrRetOfRemainingTicks);

#endif /* MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
