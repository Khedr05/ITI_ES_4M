/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Atmega32_Drivers
// File          : dip_interface.h
// Date          : 10 Aug 2023 \
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/
#ifndef ECUAL_DIP_DIP_INTERFACE_H_
#define ECUAL_DIP_DIP_INTERFACE_H_

#include "dip_config.h"

EN_EDIP_systemState_t EDIP_init(ST_EDIP_cfg_t const *ST_ptrEdipCfgInstance);
EN_EDIP_systemState_t
EDIP_readStates(ST_EDIP_cfg_t const *ST_ptrEdipCfgInstance,
                EN_EDIP_logicStatus_t *retOfEdipStatus);

#endif /* ECUAL_DIP_DIP_INTERFACE_H_ */
