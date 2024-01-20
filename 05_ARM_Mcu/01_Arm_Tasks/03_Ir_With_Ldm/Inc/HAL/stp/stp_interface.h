/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : stp_interface.h                                  	     
// Date          : Sep 26, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_STP_STP_INTERFACE_H_
#define HAL_STP_STP_INTERFACE_H_

#include "../../../Inc/COMMON/std_types.h"
#include "../../../Inc/COMMON/bit_math.h"
#include "../../../Inc/MCAL/systick/systick_interface.h"
#include "../../../Inc/MCAL/gpio/gpio_interface.h"
#include "stp_config.h"

EN_HSTP_systeamState_t HSTP_uddtInit(ST_HSTP_cfg_t const *PS_stpCfg);
EN_HSTP_systeamState_t HSTP_uddtByteOutput(ST_HSTP_cfg_t const *PS_stpCfg , uint8_t  copy_u8DataToOutput);
EN_HSTP_systeamState_t HSTP_uddtHalfWordOutput(ST_HSTP_cfg_t const *PS_stpCfg ,uint16_t copy_u16DataToOutput);



#endif /* HAL_STP_STP_INTERFACE_H_ */
