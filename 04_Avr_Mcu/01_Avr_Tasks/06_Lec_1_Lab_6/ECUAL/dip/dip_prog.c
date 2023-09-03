/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Atmega32_Drivers
// File          : dip_prog.c
// Date          : 10 Aug 2023
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/

#include "dip_interface.h"

EN_EDIP_systemState_t EDIP_init(ST_EDIP_cfg_t const *ST_ptrEdipCfgInstance) {
  EN_EDIP_systemState_t dipRet = EDIP_NOK;
  EN_GPIO_systemState_t gpioRet = GPIO_NOK;

  if (PTR_NULL != ST_ptrEdipCfgInstance) {
    ST_GPIO_cfg_t dipPinCfg = {.pinDirection = GPIO_INPUT,
                               .pinNumber = ST_ptrEdipCfgInstance->dipPin,
                               .portName = ST_ptrEdipCfgInstance->dipPort,
                               .logicOnPin = GPIO_HIGH};

    gpioRet = GPIO_initPin(&dipPinCfg);

    if (gpioRet == GPIO_OK) {
      dipRet = EDIP_OK;
    } else {
      dipRet = EDIP_NOK;
    }
  } else {
    dipRet = EDIP_PTR_NULL;
  }
  return dipRet;
}

EN_EDIP_systemState_t
EDIP_readStates(ST_EDIP_cfg_t const *ST_ptrEdipCfgInstance,
                EN_EDIP_logicStatus_t *retOfEdipStatus) {

  EN_EDIP_systemState_t dipRet = EDIP_NOK;
  EN_GPIO_systemState_t gpioRet = GPIO_NOK;

  if (PTR_NULL != ST_ptrEdipCfgInstance) {
    ST_GPIO_cfg_t dipPinCfg = {.pinDirection = GPIO_INPUT,
                               .pinNumber = ST_ptrEdipCfgInstance->dipPin,
                               .portName = ST_ptrEdipCfgInstance->dipPort};

    EN_GPIO_pinLogic_t currentSwitchStatus;
    gpioRet = GPIO_readPinLogic(&dipPinCfg, &currentSwitchStatus);
    if (gpioRet == GPIO_OK) {
      if (currentSwitchStatus == GPIO_LOW) {
        *retOfEdipStatus = EDIP_IS_ON;
        dipRet = EDIP_OK;
      } else if (currentSwitchStatus == GPIO_HIGH) {
        *retOfEdipStatus = EDIP_IS_OFF;
        dipRet = EDIP_OK;
      } else {
        dipRet = EDIP_NOK;
      }
    } else {
      dipRet = EDIP_NOK;
    }
  } else {
    dipRet = EDIP_PTR_NULL;
  }
  return dipRet;
}