/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : uart_private.h                                  	     
// Date          : Sep 19, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_

#define	 MUART1_PERIPHERAL_BASE_ADDR			(0x40011000)
#define	 MUART2_PERIPHERAL_BASE_ADDR			(0x40004400)
#define	 MUART3_PERIPHERAL_BASE_ADDR			(0x40011400)



typedef struct
{

	vuint32_t MUSART_SR;
	vuint32_t MUSART_DR;
	vuint32_t MUSART_BRR;
	vuint32_t MUSART_CR1;
	vuint32_t MUSART_CR2;
	vuint32_t MUSART_CR3;
	vuint32_t MUSART_GTPR;

}ST_MUART_RegistersMap_t;


#define MUART1_PERIPHERAL 	((volatile ST_MUART_RegistersMap_t *)MUART1_PERIPHERAL_BASE_ADDR)
#define MUART2_PERIPHERAL 	((volatile ST_MUART_RegistersMap_t *)MUART2_PERIPHERAL_BASE_ADDR)
#define MUART3_PERIPHERAL 	((volatile ST_MUART_RegistersMap_t *)MUART3_PERIPHERAL_BASE_ADDR)


/* Registers Bits  */

/* Registers MUSART_SR Bits  */


#define MUSART_TXE_BIT		7
#define MUSART_TC_BIT		6
#define MUSART_RXNE_BIT		5



/* Registers MUSART_BRR Bits  */

#define MUSART_DIV_FRACTION0_BIT     0
#define MUSART_DIV_FRACTION1_BIT     1
#define MUSART_DIV_FRACTION2_BIT     2
#define MUSART_DIV_FRACTION3_BIT     3
#define MUSART_DIV_MANTISSA0_BIT     4
#define MUSART_DIV_MANTISSA1_BIT     5
#define MUSART_DIV_MANTISSA2_BIT     6
#define MUSART_DIV_MANTISSA3_BIT     7
#define MUSART_DIV_MANTISSA4_BIT     8
#define MUSART_DIV_MANTISSA5_BIT     9
#define MUSART_DIV_MANTISSA6_BIT     10
#define MUSART_DIV_MANTISSA7_BIT     11
#define MUSART_DIV_MANTISSA8_BIT     12
#define MUSART_DIV_MANTISSA9_BIT     13
#define MUSART_DIV_MANTISSA10_BIT    14
#define MUSART_DIV_MANTISSA11_BIT    15

/* Registers MUSART_CR1 Bits  */

#define MUSART_OVER8_BIT		15
#define MUSART_UE_BIT			13
#define MUSART_M_BIT			12
#define MUSART_PCE_BIT			10
#define MUSART_PS_BIT			9

/* Registers MUSART_CR2 Bits  */

#define MUSART_STOP0_BIT		12
#define MUSART_STOP1_BIT		13
#define MUSART_RE_BIT			2

#endif /* MCAL_USART_USART_PRIVATE_H_ */
