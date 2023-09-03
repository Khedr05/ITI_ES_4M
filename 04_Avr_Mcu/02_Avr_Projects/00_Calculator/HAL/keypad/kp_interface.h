/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Atmega32_Drivers
// File          : kp_interface.h
// Date          : 10 Aug 2023
//GitHub        : https://github.com/sherifkhadr
/*************************************************************************/
#ifndef ECUAL_KEYPAD_KP_INTERFACE_H_
#define ECUAL_KEYPAD_KP_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "kp_config.h"

EN_HKP_systemStatus_t HKP_init(ST_HKP_cfg_t const *ST_ptrKeypadInstance);

EN_HKP_systemStatus_t
HKP_scanningForPressedBtn(uint8_t *pressedBtnVal);

#endif /* ECUAL_KEYPAD_KP_INTERFACE_H_ */
