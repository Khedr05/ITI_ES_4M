/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : pb_interface.h                                  	     
// Date          : 14 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_PB_PB_INTERFACE_H_
#define HAL_PB_PB_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "../../MCAL/gpio/gpio_interface.h"
#include "pb_config.h"

EN_HPB_systeamState_t HPB_init(ST_HPB_cfg_t const *ST_ptrPbCfgInstance);

EN_HPB_systeamState_t HPB_getBtnStates(ST_HPB_cfg_t const *ST_ptrPbCfgInstance , EN_HPB_state_t *ptrOfStatesRet);


#endif /* HAL_PB_PB_INTERFACE_H_ */
