/*
 * tmr.c
 *
 *  Created on: 21 Jul 2023
 *      Author: 20101
 */


#include "tmr.h"

void TMR_vInit(void)
{
	TCCR1A_REG = (TCCR1A_REG & 0xFC);
	TCCR1B_REG = (TCCR1B_REG & 0xE7);
	TIMSK_REG = (TIMSK_REG   & 0xC3) | 0x04;
	MCU_vEnableInterrupt();

}

void TMR_vStartTimer(void)
{
	TCCR1B_REG = (TCCR1B_REG&0xF8) | 1;
}

