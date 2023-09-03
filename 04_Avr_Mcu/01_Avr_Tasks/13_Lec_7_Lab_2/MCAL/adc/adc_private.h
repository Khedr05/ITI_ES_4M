/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : adc_private.h                                  	     
// Date          : 15 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define ADMUX_REG   	*(( vuint8_t *)0x27)  	/** ADC Multiplexer Selection Register 	**/
#define ADCSRA_REG  	*(( vuint8_t *)0x26)  	/** ADC Control and Status Register A  	**/
#define ADCL_REG		*(( vuint8_t *)0x24)	/** The ADC Data Register ADCL  		**/
#define ADCH_REG		*(( vuint8_t *)0x25)	/** The ADC Data Register ADCH  		**/
#define SFIOR_REG		*(( vuint8_t *)0x50)	/** Special FunctionIO Register 		**/
#define DATA_REG		*(( vuint16_t *)0x24)	/** The ADC Data Register ADCL & ADCH  	**/


/** ADMUX REG Bits **/

#define  MUX0_BIT 		0	/** Bit 0 – MUX0 Analog Channel and Gain Selection Bit	 	**/
#define  MUX1_BIT		1	/** Bit 1 – MUX1 Analog Channel and Gain Selection Bit	 	**/
#define  MUX2_BIT		2	/** Bit 2 – MUX2 Analog Channel and Gain Selection Bit	 	**/
#define  MUX3_BIT		3	/** Bit 3 – MUX3 Analog Channel and Gain Selection Bit	 	**/
#define  MUX4_BIT		4	/** Bit 4 – MUX4 Analog Channel and Gain Selection Bit	 	**/
#define  ADLAR_BIT		5	/** Bit 5 – ADLAR: ADC Left Adjust Result  					**/
#define  REFS0_BIT		6	/** Bit 6 – REFS0: Reference Selection Bits  				**/
#define  REFS1_BIT		7   /** Bit 7 – REFS1: Reference Selection Bits  				**/


/** ADCSRA REG Bits **/

#define	ADPS0_BIT 		0	/** Bit 0 – ADPS0 ADC Prescaler Select Bit					**/
#define	ADPS1_BIT		1	/** Bit 1 – ADPS1 ADC Prescaler Select Bit					**/
#define	ADPS2_BIT		2	/** Bit 2 – ADPS2 ADC Prescaler Select Bit					**/
#define	ADIE_BIT		3	/** Bit 3 – ADIE: ADC Interrupt Enable						**/
#define	ADIF_BIT		4	/** Bit 4 – ADIF: ADC Interrupt Flag						**/
#define	ADATE_BIT		5	/** Bit 5 – ADATE: ADC Auto Trigger Enable					**/
#define	ADSC_BIT		6	/** Bit 6 – ADSC: ADC Start Conversion						**/
#define	ADEN_BIT		7  	/** Bit 7 – ADEN: ADC Enable								**/



/** SFIOR REG Bits **/


#define ADTS0_BIT		5	/** Bit 5 – ADTS0 ADC Auto Trigger Source	   				**/														**/
#define ADTS1_BIT		6	/** Bit 6 – ADTS1 ADC Auto Trigger Source	   				**/
#define ADTS2_BIT		7	/** Bit 7 – ADTS2 ADC Auto Trigger Source	   				**/


#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
