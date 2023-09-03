/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Atmega32_Drivers
// File          : led_prog.c
// Date          : 1 Aug 2023 */ GitHub        : https://github.com/sherifkhadr
/*************************************************************************/

#include "led_interface.h"

EN_LED_systemStates_t LED_init(ST_LED_cfg_t const *ST_ptrLedInstance) {
  EN_LED_systemStates_t ledRet = LED_NOK;
  EN_GPIO_systemState_t gpioRet = GPIO_NOK;
  if (PTR_NULL != ST_ptrLedInstance) {

    ST_GPIO_cfg_t copyOfLedInstance = {
        .logicOnPin = (EN_GPIO_pinLogic_t)ST_ptrLedInstance->ledDefaultState,
        .pinDirection = GPIO_OUTPUT,
        .pinNumber = ST_ptrLedInstance->ledPinNumber,
        .portName = ST_ptrLedInstance->ledPortName};
    gpioRet = GPIO_initPin(&copyOfLedInstance);
    if (GPIO_OK == gpioRet) {
      ledRet = LED_OK;
    } else {
      ledRet = LED_NOK;
    }
  } else {
    ledRet = LED_PTR_NULL;
  }
  return ledRet;
}
EN_LED_systemStates_t LED_turnOn(ST_LED_cfg_t const *ST_ptrLedInstance) {
  EN_LED_systemStates_t ledRet = LED_NOK;
  EN_GPIO_systemState_t gpioRet = GPIO_NOK;
  if (PTR_NULL != ST_ptrLedInstance) {

    ST_GPIO_cfg_t copyOfLedInstance = {
        .logicOnPin = (EN_GPIO_pinLogic_t)ST_ptrLedInstance->ledDefaultState,
        .pinDirection = GPIO_OUTPUT,
        .pinNumber = ST_ptrLedInstance->ledPinNumber,
        .portName = ST_ptrLedInstance->ledPortName};
    gpioRet = GPIO_writePinLogic(&copyOfLedInstance, GPIO_HIGH);
    if (GPIO_OK == gpioRet) {
      ledRet = LED_OK;
    } else {
      ledRet = LED_NOK;
    }
  } else {
    ledRet = LED_PTR_NULL;
  }
  return ledRet;
}
EN_LED_systemStates_t LED_turnOff(ST_LED_cfg_t const *ST_ptrLedInstance) {
  EN_LED_systemStates_t ledRet = LED_NOK;
  EN_GPIO_systemState_t gpioRet = GPIO_NOK;
  if (PTR_NULL != ST_ptrLedInstance) {

    ST_GPIO_cfg_t copyOfLedInstance = {
        .logicOnPin = (EN_GPIO_pinLogic_t)ST_ptrLedInstance->ledDefaultState,
        .pinDirection = GPIO_OUTPUT,
        .pinNumber = ST_ptrLedInstance->ledPinNumber,
        .portName = ST_ptrLedInstance->ledPortName};
    gpioRet = GPIO_writePinLogic(&copyOfLedInstance, GPIO_LOW);
    if (GPIO_OK == gpioRet) {
      ledRet = LED_OK;
    } else {
      ledRet = LED_NOK;
    }
  } else {
    ledRet = LED_PTR_NULL;
  }
  return ledRet;
}
EN_LED_systemStates_t LED_toggle(ST_LED_cfg_t const *ST_ptrLedInstance) {
  EN_LED_systemStates_t ledRet = LED_NOK;
  EN_GPIO_systemState_t gpioRet = GPIO_NOK;
  if (PTR_NULL != ST_ptrLedInstance) {

    ST_GPIO_cfg_t copyOfLedInstance = {
        .logicOnPin = (EN_GPIO_pinLogic_t)ST_ptrLedInstance->ledDefaultState,
        .pinDirection = GPIO_OUTPUT,
        .pinNumber = ST_ptrLedInstance->ledPinNumber,
        .portName = ST_ptrLedInstance->ledPortName};
    gpioRet = GPIO_togglePinLogic(&copyOfLedInstance);
    if (GPIO_OK == gpioRet) {
      ledRet = LED_OK;
    } else {
      ledRet = LED_NOK;
    }
  } else {
    ledRet = LED_PTR_NULL;
  }
  return ledRet;
}