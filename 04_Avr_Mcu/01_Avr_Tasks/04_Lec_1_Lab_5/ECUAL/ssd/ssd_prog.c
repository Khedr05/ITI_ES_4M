/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Atmega32_Drivers
// File          : ssd_prog.c
// Date          : 6 Aug 2023
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/

#include "ssd_interface.h"

EN_GPIO_pinLogic_t arrOfNumbersForCathodeCom[10][7] = {
    {GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH,
     GPIO_LOW},
    {GPIO_LOW, GPIO_HIGH, GPIO_HIGH, GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_LOW},
    {GPIO_HIGH, GPIO_HIGH, GPIO_LOW, GPIO_HIGH, GPIO_HIGH, GPIO_LOW, GPIO_HIGH},
    {GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_LOW, GPIO_LOW, GPIO_HIGH},
    {GPIO_LOW, GPIO_HIGH, GPIO_HIGH, GPIO_LOW, GPIO_LOW, GPIO_HIGH, GPIO_HIGH},
    {GPIO_HIGH, GPIO_LOW, GPIO_HIGH, GPIO_HIGH, GPIO_LOW, GPIO_HIGH, GPIO_HIGH},
    {GPIO_HIGH, GPIO_LOW, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH,
     GPIO_HIGH},
    {GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_LOW},
    {GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH,
     GPIO_HIGH},
    {GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_LOW, GPIO_HIGH,
     GPIO_HIGH}};

EN_GPIO_pinLogic_t arrOfNumbersForAnodeCom[10][7] = {
    {GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_HIGH},
    {GPIO_HIGH, GPIO_LOW, GPIO_LOW, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH},
    {GPIO_LOW, GPIO_LOW, GPIO_HIGH, GPIO_LOW, GPIO_LOW, GPIO_HIGH, GPIO_LOW},
    {GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_HIGH, GPIO_HIGH, GPIO_LOW},
    {GPIO_HIGH, GPIO_LOW, GPIO_LOW, GPIO_HIGH, GPIO_HIGH, GPIO_LOW, GPIO_LOW},
    {GPIO_LOW, GPIO_HIGH, GPIO_LOW, GPIO_LOW, GPIO_HIGH, GPIO_LOW, GPIO_LOW},
    {GPIO_LOW, GPIO_HIGH, GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_LOW},
    {GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH, GPIO_HIGH},
    {GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_LOW},
    {GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_LOW, GPIO_HIGH, GPIO_LOW, GPIO_LOW}};

EN_SSD_systemState_t SSD_int(ST_SSD_cfg_t const *ST_ptrSsdCfgInstamce) {
  EN_SSD_systemState_t ssdRet = SSD_NOK;
  EN_GPIO_systemState_t gpioRet = GPIO_NOK;
  if (PTR_NULL != ST_ptrSsdCfgInstamce) {
    if (ST_ptrSsdCfgInstamce->ssdCommonType == SSD_ANODE_COMMON) {

      ST_GPIO_cfg_t pinCom = {
          .logicOnPin = GPIO_HIGH,
          .pinDirection = GPIO_OUTPUT,
          .pinNumber = ST_ptrSsdCfgInstamce->ssdPinComPinNumber,
          .portName = ST_ptrSsdCfgInstamce->ssdPinComPortName};

      ST_GPIO_cfg_t pinA = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinAPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinAPortName};

      ST_GPIO_cfg_t pinB = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinBPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinBPortName};

      ST_GPIO_cfg_t pinC = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinCPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinCPortName};

      ST_GPIO_cfg_t pinD = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinDPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinDPortName};

      ST_GPIO_cfg_t pinE = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinEPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinEPortName};

      ST_GPIO_cfg_t pinF = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinFPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinFPortName};

      ST_GPIO_cfg_t pinG = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinGPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinGPortName};

      gpioRet = GPIO_initPin(&pinCom);
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_initPin(&pinA);
      } else {
        /*Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        GPIO_initPin(&pinB);
      } else {
        /*Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        GPIO_initPin(&pinC);
      } else {
        /*Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        GPIO_initPin(&pinD);
      } else {
        /*Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        GPIO_initPin(&pinE);
      } else {
        /*Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        GPIO_initPin(&pinF);
      } else {
        /*Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        GPIO_initPin(&pinG);
      } else {
        /*Do Nothing*/
      }

      if (gpioRet == GPIO_OK) {
        ssdRet = SSD_OK;
      } else {
        ssdRet = SSD_NOK;
      }

    } else if (ST_ptrSsdCfgInstamce->ssdCommonType == SSD_CATHODE_COMMON) {
      ST_GPIO_cfg_t pinCom = {
          .logicOnPin = GPIO_LOW,
          .pinDirection = GPIO_OUTPUT,
          .pinNumber = ST_ptrSsdCfgInstamce->ssdPinComPinNumber,
          .portName = ST_ptrSsdCfgInstamce->ssdPinComPortName};

      ST_GPIO_cfg_t pinA = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinAPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinAPortName};

      ST_GPIO_cfg_t pinB = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinBPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinBPortName};

      ST_GPIO_cfg_t pinC = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinCPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinCPortName};

      ST_GPIO_cfg_t pinD = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinDPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinDPortName};

      ST_GPIO_cfg_t pinE = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinEPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinEPortName};

      ST_GPIO_cfg_t pinF = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinFPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinFPortName};

      ST_GPIO_cfg_t pinG = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinGPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinGPortName};

      gpioRet = GPIO_initPin(&pinCom);
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_initPin(&pinA);
      } else {
        /*Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        GPIO_initPin(&pinB);
      } else {
        /*Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        GPIO_initPin(&pinC);
      } else {
        /*Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        GPIO_initPin(&pinD);
      } else {
        /*Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        GPIO_initPin(&pinE);
      } else {
        /*Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        GPIO_initPin(&pinF);
      } else {
        /*Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        GPIO_initPin(&pinG);
      } else {
        /*Do Nothing*/
      }

      if (gpioRet == GPIO_OK) {
        ssdRet = SSD_OK;
      } else {
        ssdRet = SSD_NOK;
      }
    } else {
      /*Do Nothing*/
    }
  } else {
    ssdRet = SSD_NULL_PTR;
  }
  return ssdRet;
}

EN_SSD_systemState_t
SSD_setNumberOnSsd(ST_SSD_cfg_t const *ST_ptrSsdCfgInstamce,
                   EN_SSD_numbers_t valueOfNumber) {
  EN_SSD_systemState_t ssdRet = SSD_NOK;
  EN_GPIO_systemState_t gpioRet = GPIO_NOK;
  if (PTR_NULL != ST_ptrSsdCfgInstamce) {
    if (ST_ptrSsdCfgInstamce->ssdCommonType == SSD_ANODE_COMMON) {
      ST_GPIO_cfg_t pinA = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinAPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinAPortName};

      ST_GPIO_cfg_t pinB = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinBPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinBPortName};

      ST_GPIO_cfg_t pinC = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinCPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinCPortName};

      ST_GPIO_cfg_t pinD = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinDPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinDPortName};

      ST_GPIO_cfg_t pinE = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinEPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinEPortName};

      ST_GPIO_cfg_t pinF = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinFPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinFPortName};

      ST_GPIO_cfg_t pinG = {.logicOnPin = GPIO_HIGH,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinGPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinGPortName};

      gpioRet =
          GPIO_writePinLogic(&pinA, arrOfNumbersForAnodeCom[valueOfNumber][0]);
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_writePinLogic(&pinB,
                                     arrOfNumbersForAnodeCom[valueOfNumber][1]);
      } else {
        /* Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_writePinLogic(&pinC,
                                     arrOfNumbersForAnodeCom[valueOfNumber][2]);
      } else {
        /* Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_writePinLogic(&pinD,
                                     arrOfNumbersForAnodeCom[valueOfNumber][3]);
      } else {
        /* Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_writePinLogic(&pinE,
                                     arrOfNumbersForAnodeCom[valueOfNumber][4]);
      } else {
        /* Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_writePinLogic(&pinF,
                                     arrOfNumbersForAnodeCom[valueOfNumber][5]);
      } else {
        /* Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_writePinLogic(&pinG,
                                     arrOfNumbersForAnodeCom[valueOfNumber][6]);
      } else {
        /* Do Nothing*/
      }

      if (gpioRet == GPIO_OK) {
        ssdRet = SSD_OK;
      } else {
        ssdRet = SSD_NOK;
      }

    } else if (ST_ptrSsdCfgInstamce->ssdCommonType == SSD_CATHODE_COMMON) {
      ST_GPIO_cfg_t pinA = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinAPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinAPortName};

      ST_GPIO_cfg_t pinB = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinBPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinBPortName};

      ST_GPIO_cfg_t pinC = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinCPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinCPortName};

      ST_GPIO_cfg_t pinD = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinDPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinDPortName};

      ST_GPIO_cfg_t pinE = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinEPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinEPortName};

      ST_GPIO_cfg_t pinF = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinFPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinFPortName};

      ST_GPIO_cfg_t pinG = {.logicOnPin = GPIO_LOW,
                            .pinDirection = GPIO_OUTPUT,
                            .pinNumber = ST_ptrSsdCfgInstamce->ssdPinGPinNumber,
                            .portName = ST_ptrSsdCfgInstamce->ssdPinGPortName};

      gpioRet = GPIO_writePinLogic(&pinA,
                                   arrOfNumbersForCathodeCom[valueOfNumber][0]);
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_writePinLogic(
            &pinB, arrOfNumbersForCathodeCom[valueOfNumber][1]);
      } else {
        /* Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_writePinLogic(
            &pinC, arrOfNumbersForCathodeCom[valueOfNumber][2]);
      } else {
        /* Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_writePinLogic(
            &pinD, arrOfNumbersForCathodeCom[valueOfNumber][3]);
      } else {
        /* Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_writePinLogic(
            &pinE, arrOfNumbersForCathodeCom[valueOfNumber][4]);
      } else {
        /* Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_writePinLogic(
            &pinF, arrOfNumbersForCathodeCom[valueOfNumber][5]);
      } else {
        /* Do Nothing*/
      }
      if (gpioRet == GPIO_OK) {
        gpioRet = GPIO_writePinLogic(
            &pinG, arrOfNumbersForCathodeCom[valueOfNumber][6]);
      } else {
        /* Do Nothing*/
      }

      if (gpioRet == GPIO_OK) {
        ssdRet = SSD_OK;
      } else {
        ssdRet = SSD_NOK;
      }

    } else {
      /*Do Nothing*/
    }
  } else {
    ssdRet = SSD_NULL_PTR;
  }

  return ssdRet;
}

EN_SSD_systemState_t SSD_enableDot(ST_SSD_cfg_t const *ST_ptrSsdCfgInstamce) {

  EN_SSD_systemState_t ssdRet = SSD_NOK;
  EN_GPIO_systemState_t gpioRet = GPIO_NOK;

  if (PTR_NULL != ST_ptrSsdCfgInstamce) {
    if (ST_ptrSsdCfgInstamce->ssdCommonType == SSD_ANODE_COMMON) {

      ST_GPIO_cfg_t pinDot = {
          .logicOnPin = GPIO_HIGH,
          .pinDirection = GPIO_OUTPUT,
          .pinNumber = ST_ptrSsdCfgInstamce->ssdPinDotPinNumber,
          .portName = ST_ptrSsdCfgInstamce->ssdPinDotPortName};

      gpioRet = GPIO_initPin(&pinDot);
      if (gpioRet == GPIO_OK) {
        ssdRet = SSD_OK;
      } else {
        ssdRet = SSD_NOK;
      }
    } else if (ST_ptrSsdCfgInstamce->ssdCommonType == SSD_CATHODE_COMMON) {
      ST_GPIO_cfg_t pinDot = {
          .logicOnPin = GPIO_LOW,
          .pinDirection = GPIO_OUTPUT,
          .pinNumber = ST_ptrSsdCfgInstamce->ssdPinDotPinNumber,
          .portName = ST_ptrSsdCfgInstamce->ssdPinDotPortName};
      gpioRet = GPIO_initPin(&pinDot);
      if (gpioRet == GPIO_OK) {
        ssdRet = SSD_OK;
      } else {
        ssdRet = SSD_NOK;
      }
    } else {
      /* Do Nothing */
    }
  } else {
    ssdRet = SSD_NULL_PTR;
  }
  return ssdRet;
}

EN_SSD_systemState_t SSD_disableDot(ST_SSD_cfg_t const *ST_ptrSsdCfgInstamce) {
  EN_SSD_systemState_t ssdRet = SSD_NOK;
  EN_GPIO_systemState_t gpioRet = GPIO_NOK;

  if (PTR_NULL != ST_ptrSsdCfgInstamce) {
    if (ST_ptrSsdCfgInstamce->ssdCommonType == SSD_ANODE_COMMON) {

      ST_GPIO_cfg_t pinDot = {
          .logicOnPin = GPIO_LOW,
          .pinDirection = GPIO_OUTPUT,
          .pinNumber = ST_ptrSsdCfgInstamce->ssdPinDotPinNumber,
          .portName = ST_ptrSsdCfgInstamce->ssdPinDotPortName};

      gpioRet = GPIO_initPin(&pinDot);
      if (gpioRet == GPIO_OK) {
        ssdRet = SSD_OK;
      } else {
        ssdRet = SSD_NOK;
      }
    } else if (ST_ptrSsdCfgInstamce->ssdCommonType == SSD_CATHODE_COMMON) {
      ST_GPIO_cfg_t pinDot = {
          .logicOnPin = GPIO_HIGH,
          .pinDirection = GPIO_OUTPUT,
          .pinNumber = ST_ptrSsdCfgInstamce->ssdPinDotPinNumber,
          .portName = ST_ptrSsdCfgInstamce->ssdPinDotPortName};
      gpioRet = GPIO_initPin(&pinDot);
      gpioRet = GPIO_initPin(&pinDot);
      if (gpioRet == GPIO_OK) {
        ssdRet = SSD_OK;
      } else {
        ssdRet = SSD_NOK;
      }
    } else {
      /* Do Nothing */
    }
  } else {
    ssdRet = SSD_NULL_PTR;
  }
  return ssdRet;
}