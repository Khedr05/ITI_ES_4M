/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : dac_interface.h                                  	     
// Date          : Sep 14, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_DAC_DAC_INTERFACE_H_
#define HAL_DAC_DAC_INTERFACE_H_


#include "../../MCAL/gpio/gpio_interface.h"
#include "dac_config.h"
#include "song.h"


EN_HDAC_systemState_t HDAC_uddtInit(void);

EN_HDAC_systemState_t HDAC_uddtSend(void);

#endif /* HAL_DAC_DAC_INTERFACE_H_ */
