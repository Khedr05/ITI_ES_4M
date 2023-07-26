/*
 * tmr.h
 *
 *  Created on: 21 Jul 2023
 *      Author: 20101
 */

#ifndef TMR_H_
#define TMR_H_

#include "../../COMMON/STD_Types.h"
#include "../../COMMON/BIT_Math.h"
#include "../../MCAL/mcu_cfg/MCU_Interface.h"
#include "tmr_praivate.h"


#define CLEAR_ICU_FLAG()		TIFR_REG = (1<<ICF1_PIN)
#define ICU_Rising_Edge()		SET_BIT(TCCR1B_REG, ICES1)
#define ICU_Falling_Edge()		CLEAR_BIT(TCCR1B_REG, ICES1)


void TMR_vInit(void);
void TMR_vStartTimer(void);

#endif /* TMR_H_ */
