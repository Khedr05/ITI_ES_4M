/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : exti_interface.h                                  	     
// Date          : Sep 11, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "exti_private.h"
#include "exti_config.h"


EN_MEXTI_systemState_t MEXTI_enableEXTI (EN_MEXTI_lines_t copy_uddtLineNum);

EN_MEXTI_systemState_t MEXTI_disableEXTI (EN_MEXTI_lines_t copy_uddtLineNum);

EN_MEXTI_systemState_t MEXTI_softwareInterrupt (EN_MEXTI_lines_t copy_uddtLineNum);

EN_MEXTI_systemState_t MEXTI_setTriggerSource (EN_MEXTI_lines_t copy_uddtLineNum , EN_MEXTI_triggerOptions_t copy_uddtTriggerOption);

EN_MEXTI_systemState_t MEXTI_setExtiConfig (EN_MEXTI_lines_t copy_uddtLineNum , EN_MEXTI_port_t copy_uddtPortNum);

EN_MEXTI_systemState_t MEXTI_setCallBack (void(*ptr)(void) , EN_MEXTI_lines_t copy_uddtLineNum);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
