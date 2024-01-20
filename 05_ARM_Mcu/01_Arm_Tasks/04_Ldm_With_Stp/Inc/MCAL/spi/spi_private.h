/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : spi_private.h                                  	     
// Date          : Sep 20, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#define	 MSPI1_PERIPHERAL_BASE_ADDR		(0x40013000)


typedef struct
{

}ST_MSPI_CR1_BITS;

typedef struct
{

}ST_MSPI_CR2_BITS;

typedef struct
{
	vuint32_t MSPI_CR1;
	vuint32_t MSPI_CR2;
	vuint32_t MSPI_SR;
	vuint32_t MSPI_DR;
	vuint32_t MSPI_CRCPR;
	vuint32_t MSPI_RXCRCR;
	vuint32_t MSPI_TXCRCR;
	vuint32_t MSPI_I2SCFGR;
	vuint32_t MSPI_I2SPR;


}ST_MSPI_RegistersMap_t;


#define MSPI1_PERIPHERAL ((volatile ST_MSPI_RegistersMap_t *)MSPI1_PERIPHERAL_BASE_ADDR)


/* Registers Bit */

/* CR1 Register Bits */

#define CPHA_BIT		0
#define CPOL_BIT		1
#define MSTR_BIT		2
#define BR0_BIT			3
#define BR1_BIT			4
#define BR2_BIT			5
#define SPE_BIT			6
#define LSBFIRST_BIT	7
#define SSI_BIT			8
#define SSM_BIT			9
#define RXONLY_BIT		10
#define DFF_BIT			11
#define CRCNEXT_BIT		12
#define CRCEN_BIT		13
#define BIDIOE_BIT		14
#define BIDIMODE		15

/* SR Register Bits */

#define BSY_BIT		7



#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
