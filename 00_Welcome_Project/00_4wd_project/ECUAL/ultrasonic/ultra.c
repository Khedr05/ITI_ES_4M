/*
 * ultra.c
 *
 *  Created on: 21 Jul 2023
 *      Author: 20101
 */

#include "ultra.h"

static Uint16_t timer1_counter;


/* ISR for Timer 1 Overflow */
void __vector_9(void) __attribute__((signal));
void __vector_9(void){
	timer1_counter++;
}

void HCSR04_vInit(){
	/* GPIO Pins Initialization */
	SET_BIT(DDRD_REG , 7);
	CLEAR_BIT(DDRD_REG , 6);

	SET_BIT(PORTD_REG , 6);
	CLEAR_BIT(PORTD_REG , 7);
	//DIO_vPinInit(TRIG_PORT, TRIG_PIN, OUTPUT, LOW);   7
	//DIO_vPinInit(ECHO_PORT, ECHO_PIN, INPUT, HIGH);  6

	/* Initialize Timer */
	TMR_vInit();

	/* Enable global interrupts */
	//GIE_vEnableInterrupts();

	MCU_vEnableInterrupt();
}

void HCSR04_vGet_Reading(float64_t *Copy_f64Sensor_Reading){
	Uint16_t ICR_Reg_Value;
	Uint32_t Elapsed_Time;
	float64_t Real_Distance;
	TCNT1_REG = 0; // Clear timer register
	CLEAR_ICU_FLAG(); // Clear ICU interrupt flag
	ICU_Rising_Edge(); // Set ICU to rising edge trigger
	TMR_vStartTimer(); // Start timer counting
	/* Send a 10uSec pulse to trig */
	//DIO_vSetPinValue(TRIG_PORT, TRIG_PIN, HIGH);
	SET_BIT(PORTD_REG , 7);
	_delay_us(10);
	CLEAR_BIT(PORTD_REG , 7);
	//DIO_vSetPinValue(TRIG_PORT, TRIG_PIN, LOW);

	/* Wait for rising edge from ECHO */
	while(!(TIFR_REG & (1<<ICF1_PIN)));
	TCNT1_REG = 0; // Clear timer register
	timer1_counter = 0;
	CLEAR_ICU_FLAG(); // clear ICP flag
	ICU_Falling_Edge(); // Set ICU to falling edge trigger

	/* Wait for falling edge from ECHO */
	while(!(TIFR_REG & (1<<ICF1_PIN)));
	/* Read ICU Register */
	ICR_Reg_Value = (Uint16_t)(ICR1L_REG + (ICR1H_REG << 8));
	CLEAR_ICU_FLAG(); // Clear ICU interrupt flag

	/* Get total time for logic HIGH */
	Elapsed_Time = (Uint32_t)(ICR_Reg_Value + (65535 * timer1_counter));

	/* Calculate distance */
	/* 8MHZ Timer Frequency, Speed of Sound = 343 m/s */
	Real_Distance = (float64_t)Elapsed_Time / 466.47;
	*Copy_f64Sensor_Reading = Real_Distance;
}
