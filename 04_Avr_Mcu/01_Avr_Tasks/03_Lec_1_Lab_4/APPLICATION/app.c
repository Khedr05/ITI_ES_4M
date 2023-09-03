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

ST_LED_cfg_t pinA1Led = {.ledDefaultState = LED_STATUES_OFF,
                         .ledPortName = GPIO_PORTA,
                         .ledPinNumber = GPIO_PIN1};

ST_LED_cfg_t pinA2Led = {.ledDefaultState = LED_STATUES_OFF,
                         .ledPortName = GPIO_PORTA,
                         .ledPinNumber = GPIO_PIN2};

ST_LED_cfg_t pinA3Led = {.ledDefaultState = LED_STATUES_OFF,
                         .ledPortName = GPIO_PORTA,
                         .ledPinNumber = GPIO_PIN3};

ST_LED_cfg_t pinA4Led = {.ledDefaultState = LED_STATUES_OFF,
                         .ledPortName = GPIO_PORTA,
                         .ledPinNumber = GPIO_PIN4};

ST_LED_cfg_t pinA5Led = {.ledDefaultState = LED_STATUES_OFF,
                         .ledPortName = GPIO_PORTA,
                         .ledPinNumber = GPIO_PIN5};

ST_LED_cfg_t pinA6Led = {.ledDefaultState = LED_STATUES_OFF,
                         .ledPortName = GPIO_PORTA,
                         .ledPinNumber = GPIO_PIN6};

ST_LED_cfg_t pinA7Led = {.ledDefaultState = LED_STATUES_OFF,
                         .ledPortName = GPIO_PORTA,
                         .ledPinNumber = GPIO_PIN7};

void appInit() {
  LED_init(&pinA0Led);
  LED_init(&pinA1Led);
  LED_init(&pinA2Led);
  LED_init(&pinA3Led);
  LED_init(&pinA4Led);
  LED_init(&pinA5Led);
  LED_init(&pinA6Led);
  LED_init(&pinA7Led);
}
void appMain() {
  LED_turnOn(&pinA0Led);
  _delay_ms(250);
  LED_turnOn(&pinA1Led);
  _delay_ms(250);
  LED_turnOn(&pinA2Led);
  _delay_ms(250);
  LED_turnOn(&pinA3Led);
  _delay_ms(250);
  LED_turnOn(&pinA4Led);
  _delay_ms(250);
  LED_turnOn(&pinA5Led);
  _delay_ms(250);
  LED_turnOn(&pinA6Led);
  _delay_ms(250);
  LED_turnOn(&pinA7Led);
  _delay_ms(250);
  LED_turnOff(&pinA7Led);
  _delay_ms(100);
  LED_turnOff(&pinA6Led);
  _delay_ms(100);
  LED_turnOff(&pinA5Led);
  _delay_ms(100);
  LED_turnOff(&pinA4Led);
  _delay_ms(100);
  LED_turnOff(&pinA3Led);
  _delay_ms(100);
  LED_turnOff(&pinA2Led);
  _delay_ms(100);
  LED_turnOff(&pinA1Led);
  _delay_ms(100);
  LED_turnOff(&pinA0Led);
  _delay_ms(100);
}
