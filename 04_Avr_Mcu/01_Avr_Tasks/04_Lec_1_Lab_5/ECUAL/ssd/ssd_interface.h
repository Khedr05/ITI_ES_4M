/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Atmega32_Drivers
// File          : ssd_interface.h
// Date          : 6 Aug 2023
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/
#ifndef ECUAL_SSD_SSD_INTERFACE_H_
#define ECUAL_SSD_SSD_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "ssd_config.h"

EN_SSD_systemState_t SSD_int(ST_SSD_cfg_t const *ST_ptrSsdCfgInstamce);

EN_SSD_systemState_t
SSD_setNumberOnSsd(ST_SSD_cfg_t const *ST_ptrSsdCfgInstamce,
                   EN_SSD_numbers_t valueOfNumber);

EN_SSD_systemState_t SSD_enableDot(ST_SSD_cfg_t const *ST_ptrSsdCfgInstamce);
EN_SSD_systemState_t SSD_disableDot(ST_SSD_cfg_t const *ST_ptrSsdCfgInstamce);
#endif /* ECUAL_SSD_SSD_INTERFACE_H_ */
