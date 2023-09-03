/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Atmega32_Drivers
// File          : led_config.h
// Date          : 1 Aug 2023 */ GitHub        : https://github.com/sherifkhadr
/*************************************************************************/
#ifndef HAL_LED_LED_CONFIG_H_
#define HAL_LED_LED_CONFIG_H_

#include "../../MCAL/gpio/gpio_config.h"

typedef enum { LED_OK = 0, LED_NOK, LED_PTR_NULL } EN_LED_systemStates_t;

typedef enum { LED_STATUES_OFF = 0, LED_STATUES_ON } EN_LED_states_t;

typedef struct {
  EN_LED_states_t ledDefaultState;
  EN_GPIO_mcuPorts_t ledPortName;
  EN_GPIO_mcuPins_t ledPinNumber;
} ST_LED_cfg_t;

#endif /* HAL_LED_LED_CONFIG_H_ */
