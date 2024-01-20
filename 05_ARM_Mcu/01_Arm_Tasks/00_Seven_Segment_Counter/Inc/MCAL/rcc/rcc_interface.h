/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC_Drivers                                    	 
// File          : rcc_interface.h                                  	     
// Date          : Sep 8, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_


#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "rcc_private.h"
#include "rcc_config.h"


EN_MRCC_systemState_t MRCC_Init(void);

EN_MRCC_systemState_t MRCC_enablePeripheral(EN_MRCC_busOptions_t busSelection,EN_MRCC_peripheralOptions_t PeripheralNumber);
EN_MRCC_systemState_t MRCC_disablePeripheral(EN_MRCC_busOptions_t busSelection,EN_MRCC_peripheralOptions_t PeripheralNumber);




#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
