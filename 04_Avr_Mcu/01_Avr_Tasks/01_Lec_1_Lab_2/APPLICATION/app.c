/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : 00_Lab_1
// File          : app.c
// Date          : 1 Aug 2023 */ GitHub        : https://github.com/sherifkhadr
/*************************************************************************/

#include "app.h"

ST_LED_cfg_t pinA0Led = {.ledDefaultState = LED_STATUES_OFF,
                         .ledPortName = GPIO_PORTA,
                         .ledPinNumber = GPIO_PIN0};

void appInit() { LED_init(&pinA0Led); }
void appMain() {
  LED_turnOn(&pinA0Led);
  _delay_ms(1000);
  LED_turnOff(&pinA0Led);
}
