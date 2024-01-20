/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : ledMatrix_interface.h                                  	     
// Date          : Sep 13, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_LEDMATRIX_LEDMATRIX_INTERFACE_H_
#define HAL_LEDMATRIX_LEDMATRIX_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "../../MCAL/gpio/gpio_interface.h"
#include "../../MCAL/systick/systick_interface.h"
#include "ledMatrix_config.h"


EN_HLDM_systemState_t HLDM_init(ST_HLDM_cfg_t const *copy_uddtPsOfLdm);

EN_HLDM_systemState_t HLDM_enable(ST_HLDM_cfg_t const *copy_uddtPsOfLdm , uint16_t *copy_u8ArrOfMatrix);


#endif /* HAL_LEDMATRIX_LEDMATRIX_INTERFACE_H_ */
