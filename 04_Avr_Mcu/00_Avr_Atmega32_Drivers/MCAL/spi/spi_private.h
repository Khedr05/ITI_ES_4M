/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : spi_private.h                                  	     
// Date          : 21 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#define SPCR_REG 	*(( vuint8_t *)0x2D)
#define SPSR_REG  	*(( vuint8_t *)0x2E)
#define SPDR_REG  	*(( vuint8_t *)0x2F)


#define			SPR0_BIT		0
#define			SPR1_BIT		1
#define			CPHA_BIT		2
#define			CPOL_BIT		3
#define			MSTR_BIT		4
#define			DORD_BIT		5
#define			SPE_BIT			6
#define			SPIE_BIT		7


#define 		SPI2X_BIT		0
#define 		RES4_BIT		1
#define 		RES3_BIT		2
#define 		RES2_BIT		3
#define 		RES1_BIT		4
#define 		RES0_BIT		5
#define 		WCOL_BIT		6
#define 		SPIF_BIT		7






#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
