/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Atmega32_Drivers
// File          : kp_config.h
// Date          : 10 Aug 2023
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/
#ifndef ECUAL_KEYPAD_KP_CONFIG_H_
#define ECUAL_KEYPAD_KP_CONFIG_H_

#include "../../MCAL/gpio/gpio_interface.h"

#define KEYPAD_ROWS_SIZE 4
#define KEYPAD_COLUMNS_SIZE 4
#define LOOP_STARTING_VALUE 0

typedef enum { HKP_OK = 0, HKP_NOK, HKP_PTR_NULL } EN_HKP_systemStatus_t;

typedef struct {
  EN_GPIO_mcuPins_t arrOfRowPins[KEYPAD_ROWS_SIZE];
  EN_GPIO_mcuPorts_t arrOfRowPorts[KEYPAD_ROWS_SIZE];
  EN_GPIO_mcuPins_t arrOfColumnPins[KEYPAD_COLUMNS_SIZE];
  EN_GPIO_mcuPorts_t arrOfColumnPorts[KEYPAD_COLUMNS_SIZE];
} ST_HKP_cfg_t;

#endif /* ECUAL_KEYPAD_KP_CONFIG_H_ */
