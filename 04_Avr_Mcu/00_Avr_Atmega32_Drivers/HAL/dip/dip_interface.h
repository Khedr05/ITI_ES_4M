/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Atmega32_Drivers
// File          : dip_interface.h
// Date          : 10 Aug 2023
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/
#ifndef HAL_DIP_DIP_INTERFACE_H_
#define HAL_DIP_DIP_INTERFACE_H_

#include "../../HAL/dip/dip_config.h"

EN_EDIP_systemState_t EDIP_init(ST_EDIP_cfg_t const *ST_ptrEdipCfgInstance);
EN_EDIP_systemState_t
EDIP_readStates(ST_EDIP_cfg_t const *ST_ptrEdipCfgInstance,
                EN_EDIP_logicStatus_t *retOfEdipStatus);

#endif /* HAL_DIP_DIP_INTERFACE_H_ */
