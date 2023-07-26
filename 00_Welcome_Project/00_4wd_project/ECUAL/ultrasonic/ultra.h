/*
 * ultra.h
 *
 *  Created on: 21 Jul 2023
 *      Author: 20101
 */

#ifndef ULTRA_H_
#define ULTRA_H_

#include "../../COMMON/BIT_Math.h"
#include "../../MCAL/tmr/tmr.h"
#include "../../MCAL/dio/DIO_interface.h"
#include <util/delay.h>


#define TRIG_PORT		PORTD
#define TRIG_PIN		PIN7
#define ECHO_PORT		PORTD
#define ECHO_PIN		PIN6

#define ICU_PORT		PORTD
#define ICU_PIN			PIN6


void HCSR04_vInit();
void HCSR04_vGet_Reading(float64_t *Copy_f64Sensor_Reading);


#endif /* ULTRA_H_ */
