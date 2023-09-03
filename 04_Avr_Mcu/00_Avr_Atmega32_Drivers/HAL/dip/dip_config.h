/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Atmega32_Drivers
// File          : dip_config.h
// Date          : 10 Aug 2023
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/
#ifndef HAL_DIP_DIP_CONFIG_H_
#define HAL_DIP_DIP_CONFIG_H_

#include "../../MCAL/gpio/gpio_interface.h"

typedef enum {
  EDIP_OK = 0,
  EDIP_NOK,
  EDIP_PTR_NULL

} EN_EDIP_systemState_t;

typedef enum { EDIP_IS_OFF = 0, EDIP_IS_ON } EN_EDIP_logicStatus_t;

typedef struct {
  EN_GPIO_mcuPins_t dipPin;
  EN_GPIO_mcuPorts_t dipPort;
} ST_EDIP_cfg_t;

#endif /* HAL_DIP_DIP_CONFIG_H_ */
