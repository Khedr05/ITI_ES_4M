/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : 06_Lec_1_Lab_6
// File          : app.c
// Date          : 10 Aug 2023
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/

#include "app.h"

ST_LED_cfg_t led = {.ledDefaultState = LED_STATUES_OFF,
                    .ledPinNumber = GPIO_PIN0,
                    .ledPortName = GPIO_PORTD};

ST_EDIP_cfg_t dip = {.dipPin = GPIO_PIN1, .dipPort = GPIO_PORTD};

void appInit(void) {
  LED_init(&led);
  EDIP_init(&dip);
}

void appMain(void) {
  EN_EDIP_logicStatus_t dipstate = EDIP_IS_OFF;
  EDIP_readStates(&dip, &dipstate);

  if (dipstate == EDIP_IS_ON) {
    LED_turnOn(&led);
  } else if (dipstate == EDIP_IS_OFF) {
    LED_turnOff(&led);
  } else {
    /*do nothing*/
  }
}
