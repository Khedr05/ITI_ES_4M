/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : ssd_interface.h                                  	     
// Date          : Sep 15, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "../../MCAL/gpio/gpio_interface.h"
#include "ssd_config.h"


EN_HSSD_systemState_t HSSD_init(ST_HSSD_cfg_t const *copy_uddtPsOfSsd);

EN_HSSD_systemState_t HSSD_displayNumber(ST_HSSD_cfg_t const *copy_uddtPsOfSsd , EN_HSSD_numberOptions_t copy_uddtNumber);

EN_HSSD_systemState_t HSSD_enableDot(ST_HSSD_cfg_t const *copy_uddtPsOfSsd);

EN_HSSD_systemState_t HSSD_disableDot(ST_HSSD_cfg_t const *copy_uddtPsOfSsd);


#endif /* HAL_SSD_SSD_INTERFACE_H_ */
