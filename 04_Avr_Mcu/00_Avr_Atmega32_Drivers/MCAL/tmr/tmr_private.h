/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : tmr_private.h                                  	     
// Date          : 17 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_TMR_TMR_PRIVATE_H_
#define MCAL_TMR_TMR_PRIVATE_H_


// Timer Zero 8-bit Register & Register Bits
// Register Address

#define TCCR0_REG *((vuint8_t *)0x53)   								/* Timer/Counter Control Register										*/
#define TCNT0_REG *((vuint8_t *)0x52)   								/* Timer/Counter Register 												*/
#define OCR0_REG  *((vuint8_t *)0x5C)   								/* Output Compare Register 												*/

// Register Bits
// Register TCCR0_REG Bits

#define FOC0_BIT  	  7													/* Bit 7 FOC0: Force Output Compare 									*/
#define WGM00_BIT	  6 												/* Bit 6 WGM000: Waveform Generation Mode								*/
#define COM01_BIT	  5 												/* Bit 5 COM01: Compare Match Output Mode								*/
#define COM00_BIT	  4													/* Bit 4 COM00: Compare Match Output Mode								*/
#define WGM01_BIT	  3 												/* Bit 3 WGM001: Waveform Generation Mode								*/
#define CS02_BIT	  2 												/* Bit 2 CS02: Clock Select 					    					*/
#define CS01_BIT	  1 												/* Bit 1 CS01: Clock Select 											*/
#define CS00_BIT	  0													/* Bit 0 CS00: Clock Select 											*/

// End Of Timer Zero


// Timer One 16-bit Register & Register Bits
// Register Address

#define TCCR1A_REG *((vuint8_t *)0x4F)   								/* Timer/Counter1 Control Register A 									*/
#define TCCR1B_REG *((vuint8_t *)0x4E)   								/* Timer/Counter1 Control Register B 									*/

#define TCNT1_REG *((vuint16_t *)0x4C)									/* Timer/Counter1 – TCNT1L & TCNT1H										*/
#define TCNT1L_REG *((vuint8_t *)0x4C)   								/* Timer/Counter1 – TCNT1L 												*/
#define TCNT1H_REG *((vuint8_t *)0x4D)   								/* Timer/Counter1 – TCNT1H 												*/

#define OCR1A_REG *((vuint16_t *)0x4A)									/* Output Compare Register 1 A – OCR1AL & OCR1AH 						*/
#define OCR1AL_REG *((vuint8_t *)0x4A)   								/* Output Compare Register 1 A – OCR1AL 								*/
#define OCR1AH_REG *((vuint8_t *)0x4B)   								/* Output Compare Register 1 A – OCR1AH 								*/

#define OCR1B_REG *((vuint16_t *)0x48)									/* Output Compare Register 1 B – OCR1BL & OCR1BH 						*/
#define OCR1BL_REG *((vuint8_t *)0x48)   								/* Output Compare Register 1 B – OCR1BL 								*/
#define OCR1BH_REG *((vuint8_t *)0x49)   								/* Output Compare Register 1 B – OCR1BH 								*/

#define ICR1_REG *((vuint16_T *)0x46)									/* Input Capture Register 1 – ICR1L &  ICR1H							*/
#define ICR1L_REG *((vuint8_t *)0x46)  								 	/* Input Capture Register 1 – ICR1L 									*/
#define ICR1H_REG *((vuint8_t *)0x47)   								/* Input Capture Register 1 – ICR1H 									*/

// Register Bits
// Register TCCR1A_REG Bits

#define COM1A1_BIT	 	 7 												/* Bit 7 COM1A1: Compare Output Mode for Channel A						*/
#define COM1A0_BIT  	 6 												/* Bit 6 COM1A0: Compare Output Mode for Channel A						*/
#define COM1B1_BIT	  	 5 												/* Bit 5 COM1B1: Compare Output Mode for Channel B						*/
#define COM1B0_BIT	  	 4 												/* Bit 4 COM1B0: Compare Output Mode for Channel B						*/
#define FOC1A_BIT 	 	 3 												/* Bit 3 FOC1A: Force Output Compare for Channel A 						*/
#define FOC1B_BIT 	 	 2 												/* Bit 2 FOC1A: Force Output Compare for Channel B 						*/
#define WGM11_BIT	     1 												/* Bit 1 WGM11 Waveform Generation Mode									*/
#define WGM10_BIT	     0 												/* Bit 0 WGM01 Waveform Generation Mode									*/

// Register TCCR1B_REG Bits

#define ICNC1_BIT    	 7 												/* Bit 7 ICNC1: Input Capture Noise Canceler							*/
#define ICES1_BIT    	 6 												/* Bit 6 ICES1: Input Capture Edge Select 								*/
#define Reserved_BIT	 5 												/* Bit 5 Reserved Bit 													*/
#define WGM13_BIT		 4 												/* Bit 4 WGM13: Waveform Generation Mode 								*/
#define WGM12_BIT		 3 												/* Bit 3 WGM12: Waveform Generation Mode 								*/
#define CS12_BIT		 2 												/* Bit 2 WGM11: Waveform Generation Mode 								*/
#define CS11_BIT		 1 												/* Bit 1 CS11 Clock Select 												*/
#define CS10_BIT		 0 												/* Bit 0 CS10 Clock Select 												*/



// End Of Timer One

// Timer Two 8-bit Register & Register Bits
// Register Address

#define TCCR2_REG *((vuint8_t *)0x45)   								/* Timer/Counter Control Register										*/
#define TCNT2_REG *((vuint8_t *)0x44)   								/* Timer/Counter Register 												*/
#define OCR2_REG  *((vuint8_t *)0x43)   								/* Output Compare Register 												*/
#define ASSR_REG  *((vuint8_t *)0x42)  									/* Asynchronous Status Register 										*/

// Register Bits
// Register TCCR2_REG Bits

#define FOC2_BIT    	 7 												/* Bit 7 FOC2: Force Output Compare										*/
#define WGM20_BIT    	 6 												/* Bit 6 WGM20: Waveform Generation Mode 								*/
#define COM21_BIT	 	 5 												/* Bit 5 COM21: Compare Match Output Mode								*/
#define COM20_BIT		 4 												/* Bit 4 COM20: Compare Match Output Mode								*/
#define WGM21_BIT		 3 												/* Bit 3 WGM21: Waveform Generation Mode 								*/
#define CS22_BIT		 2 												/* Bit 2 CS22 : Clock Select 											*/
#define CS21_BIT		 1 												/* Bit 1 CS21 : Clock Select 											*/
#define CS20_BIT		 0 												/* Bit 0 CS20 Clock Select 												*/

// Register ASSRREG Bits


#define AS2		  3   													/* Bit 3 AS2: Asynchronous Timer/Counter2 								*/
#define TCN2UB	  2	  													/* Bit 2 TCN2UB: Timer/Counter2 Update Busy 							*/
#define OCR2UB	  1	  													/* Bit 1 OCR2UB: Output Compare Register2 Update Busy					*/
#define TCR2UB    0   													/* Bit 0 TCR2UB: Timer/Counter Control Register2 Update Busy 			*/


// End Of Timer Two

// Global Registers For The Three Timers
// Register Address

#define TIMSK_REG *((vuint8_t *)0x59)   								/* Timer/Counter Interrupt Mask Register 								*/
#define TIFR_REG  *((vuint8_t *)0x58)   								/* Timer/Counter Interrupt Flag Register 								*/
#define SFIOR_REG *((vuint8_t *)0x50)  									/* Special Function IO Register 		 								*/


// Register Bits
// Register TIMSK_REG Bits


#define OCIE2_BIT   7													/* Bit 7 OCIE2: Timer/Counter2 Output Compare Match Interrupt Enable 	 */
#define TOIE2_BIT   6													/* Bit 6 TOIE2: Timer/Counter2 Overflow Interrupt Enable 				 */
#define TICIE1_BIT	5													/* Bit 5 TICIE1: Timer/Counter1, Input Capture Interrupt Enable 		 */
#define OCIE1A_BIT	4													/* Bit 4 OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable */
#define OCIE1B_BIT	3													/* Bit 3 OCIE1B: Timer/Counter1, Output Compare B Match Interrupt Enable */
#define TOIE1_BIT	2													/* Bit 2 TOIE1: Timer/Counter1, Overflow Interrupt Enable                */
#define OCIE0_BIT   1													/* Bit 1 OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable     */
#define TOIE0_BIT	0													/* Bit 0 TOIE0: Timer/Counter0 Overflow Interrupt Enable                 */

// Register TIFR_REG Bits


#define OCF2_BIT   7  													/* Bit 7 OCF2: Output Compare Flag 2 									 */
#define TOV2_BIT   6  													/* Bit 6 TOV2: Timer/Counter2 Overflow Flag 							 */
#define ICF1_BIT   5  													/* Bit 5 ICF1:  Timer/Counter1, Input Capture Flag 						 */
#define OCF1A_BIT  4  													/* Bit 4 OCF1A: Timer/Counter1, Output Compare A Match Flag 			 */
#define OCF1B_BIT  3  													/* Bit 3 OCF1B: Timer/Counter1, Output Compare B Match Flag				 */
#define TOV1_BIT   2  													/* Bit 2 TOV1: Timer/Counter1, Overflow Flag 					         */
#define OCF0_BIT   1  													/* Bit 1 OCF0: Output Compare Flag 0  					       			 */
#define TOV0_BIT   0  													/* Bit 0 TOV0: Timer/Counter0 Overflow Flag 						     */

// Register SFIOR_REG Bits


#define PSR2_BIT	1 													/* Bit 1 PSR2 : Prescaler Reset Timer/Counter2 						     */
#define PSR10_BIT	0 													/* Bit 0 PSR10: Prescaler Reset Timer/Counter1 and Timer/Counter0 		 */





#endif /* MCAL_TMR_TMR_PRIVATE_H_ */
