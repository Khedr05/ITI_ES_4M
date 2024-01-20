/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : fdi_config.h                                  	     
// Date          : Sep 27, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_FDI_FDI_CONFIG_H_
#define MCAL_FDI_FDI_CONFIG_H_



#define WRITE_HALF_WORD  	1
#define WRITE_ONE_WORD   	2
#define WRITE_DOUBLE_WORD   4

#define SIZE_OF_WRITE_WORD 		WRITE_HALF_WORD

typedef enum
{
	MFDI_OK = 0,
	MFDI_NOK,
	MFDI_INVALID_PARAMTER
}EN_MFDI_systeamState_t;

#endif /* MCAL_FDI_FDI_CONFIG_H_ */
