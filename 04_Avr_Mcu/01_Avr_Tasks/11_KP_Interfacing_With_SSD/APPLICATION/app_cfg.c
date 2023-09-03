/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : 09_KP_Interfacing_With_SSD
// File          : app_cfg.c
// Date          : 11 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/

#include "app.h"

ST_SSD_cfg_t ssdOne =
{
		.ssdCommonType = SSD_ANODE_COMMON,
		.ssdPinAPinNumber = GPIO_PIN0,
		.ssdPinBPinNumber = GPIO_PIN1,
		.ssdPinCPinNumber = GPIO_PIN2,
		.ssdPinDPinNumber = GPIO_PIN3,
		.ssdPinEPinNumber = GPIO_PIN4,
		.ssdPinFPinNumber = GPIO_PIN5,
		.ssdPinGPinNumber = GPIO_PIN6,
		.ssdPinComPinNumber = GPIO_PIN7,
		.ssdPinAPortName = GPIO_PORTB,
		.ssdPinBPortName = GPIO_PORTB,
		.ssdPinCPortName = GPIO_PORTB,
		.ssdPinDPortName = GPIO_PORTB,
		.ssdPinEPortName = GPIO_PORTB,
		.ssdPinFPortName = GPIO_PORTB,
		.ssdPinGPortName = GPIO_PORTB,
		.ssdPinComPortName = GPIO_PORTB

};

ST_EKP_cfg_t kp =
{
		.arrOfRowPins =
		{
				{GPIO_PIN0},{GPIO_PIN1},{GPIO_PIN2},{GPIO_PIN3}
		},
		.arrOfRowPorts =
		{
				{GPIO_PORTC},{GPIO_PORTC},{GPIO_PORTC},{GPIO_PORTC}
		},
		.arrOfColumnPorts =
		{
				{GPIO_PORTC},{GPIO_PORTC},{GPIO_PORTC},{GPIO_PORTC}
		},
		.arrOfColumnPins =
		{
				{GPIO_PIN4},{GPIO_PIN5},{GPIO_PIN6},{GPIO_PIN7}
		}
};
