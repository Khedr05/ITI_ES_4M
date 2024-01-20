/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : fdi_private.h                                  	     
// Date          : Sep 27, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_FDI_FDI_PRIVATE_H_
#define MCAL_FDI_FDI_PRIVATE_H_

#define	 MFDI_PERIPHERAL_BASE_ADDR		(0x40023C00)

#define MFDI_FLASH_KEYR_KEY_1	0x45670123
#define MFDI_FLASH_KEYR_KEY_2	0xCDEF89AB


typedef struct
{

	vuint32_t	MFDI_FLASH_ACR;
	vuint32_t	MFDI_FLASH_KEYR;
	vuint32_t	MFDI_FLASH_OPTKEYR;
	vuint32_t	MFDI_FLASH_SR;
	vuint32_t	MFDI_FLASH_CR;
	vuint32_t	MFDI_FLASH_OPTCR;

}ST_MFDI_RegistersMap_t;



#define ST_MFDI_RegistersMap_t ((volatile ST_MFDI_RegistersMap_t *)MFDI_PERIPHERAL_BASE_ADDR)





#endif /* MCAL_FDI_FDI_PRIVATE_H_ */
