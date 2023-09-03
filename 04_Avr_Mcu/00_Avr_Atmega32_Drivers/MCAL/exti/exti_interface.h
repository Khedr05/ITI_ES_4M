/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : exti_interface.h                                  	     
// Date          : 14 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


#include "../../COMMON/std_types.h"
#include "../../COMMON/bit_math.h"
#include "../../COMMON/vector_table.h"
#include "exti_private.h"
#include "exti_config.h"


EN_MEXTI_systemState_t MEXTI_initExti(ST_MEXTI_cfg_t const *ST_ptrExtiCfgInstance);

EN_MEXTI_systemState_t MEXTI_enableExti(ST_MEXTI_cfg_t const *ST_ptrExtiCfgInstance);

EN_MEXTI_systemState_t MEXTI_disableExti(ST_MEXTI_cfg_t const *ST_ptrExtiCfgInstance);



#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
