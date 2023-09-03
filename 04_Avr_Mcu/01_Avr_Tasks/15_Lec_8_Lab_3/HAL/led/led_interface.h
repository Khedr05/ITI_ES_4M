/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Atmega32_Drivers
// File          : led_interface.h
// Date          : 1 Aug 2023
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/
#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include "../../HAL/led/led_config.h"
#include "../../MCAL/gpio/gpio_interface.h"

EN_LED_systemStates_t LED_init(ST_LED_cfg_t const *ST_ptrLedInstance);
EN_LED_systemStates_t LED_turnOn(ST_LED_cfg_t const *ST_ptrLedInstance);
EN_LED_systemStates_t LED_turnOff(ST_LED_cfg_t const *ST_ptrLedInstance);
EN_LED_systemStates_t LED_toggle(ST_LED_cfg_t const *ST_ptrLedInstance);

#endif /* HAL_LED_LED_INTERFACE_H_ */
