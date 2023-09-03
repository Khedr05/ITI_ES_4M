/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : 04_Lec_1_Lab_5
// File          : main.c
// Date          : 9 Aug 2023
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/

#include "app.h"

static ST_SSD_cfg_t ssdAnode = {.ssdCommonType = SSD_ANODE_COMMON,
                         .ssdPinAPortName = GPIO_PORTC,
                         .ssdPinBPortName = GPIO_PORTC,
                         .ssdPinCPortName = GPIO_PORTC,
                         .ssdPinDPortName = GPIO_PORTC,
                         .ssdPinEPortName = GPIO_PORTC,
                         .ssdPinFPortName = GPIO_PORTC,
                         .ssdPinGPortName = GPIO_PORTC,
                         .ssdPinComPortName = GPIO_PORTC,
                         .ssdPinDotPortName = GPIO_PORTB,
                         .ssdPinAPinNumber = GPIO_PIN0,
                         .ssdPinBPinNumber = GPIO_PIN1,
                         .ssdPinCPinNumber = GPIO_PIN2,
                         .ssdPinDPinNumber = GPIO_PIN3,
                         .ssdPinEPinNumber = GPIO_PIN4,
                         .ssdPinFPinNumber = GPIO_PIN5,
                         .ssdPinGPinNumber = GPIO_PIN6,
                         .ssdPinComPinNumber = GPIO_PIN7,
                         .ssdPinDotPinNumber = GPIO_PIN6

};


void vInitApp(void) { SSD_int(&ssdAnode); }

void vMainApp(void) {
  SSD_setNumberOnSsd(&ssdAnode, SSD_ZERO);
  _delay_ms(1000);
  SSD_setNumberOnSsd(&ssdAnode, SSD_ONE);
  _delay_ms(1000);
  SSD_setNumberOnSsd(&ssdAnode, SSD_TWO);
  _delay_ms(1000);
  SSD_setNumberOnSsd(&ssdAnode, SSD_THREE);
  _delay_ms(1000);
  SSD_setNumberOnSsd(&ssdAnode, SSD_FOUR);
  _delay_ms(1000);
  SSD_setNumberOnSsd(&ssdAnode, SSD_FIVE);
  _delay_ms(1000);
  SSD_setNumberOnSsd(&ssdAnode, SSD_SIX);
  _delay_ms(1000);
  SSD_setNumberOnSsd(&ssdAnode, SSD_SEVEN);
  _delay_ms(1000);
  SSD_setNumberOnSsd(&ssdAnode, SSD_EGIHT);
  _delay_ms(1000);
  SSD_setNumberOnSsd(&ssdAnode, SSD_NINE);
  _delay_ms(1000);
}
