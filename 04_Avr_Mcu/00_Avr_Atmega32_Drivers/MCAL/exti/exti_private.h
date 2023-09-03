/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : exti_private.h                                  	     
// Date          : 14 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define MCUCR_REG *(( vuint8_t *)0x55)
#define MCUCSR_REG *(( vuint8_t *)0x54)
#define GICR_REG *(( vuint8_t *)0x5B)
#define GIFR_REG *(( vuint8_t *)0x5A)


/** MCUCR_REG_BITS **/

#define			ISC00_BIT	  	0
#define			ISC01_BIT		1
#define			ISC10_BIT		2
#define			ISC11_BIT		3


/** MCUCSR_REG_BITS **/

#define		ISC2_BIT   6


/** GICR_REG_BITS **/

#define		INT2_BIT 	 5
#define		INT0_BIT	 6
#define		INT1_BIT	 7


/** GIFR_REG_BITS **/

#define		INTF2_BIT   5
#define	    INTF0_BIT	6
#define 	INTF1_BIT	7









#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
