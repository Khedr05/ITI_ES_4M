/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : dma_config.h                                  	     
// Date          : Sep 17, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_DMA_DMA_CONFIG_H_
#define MCAL_DMA_DMA_CONFIG_H_


typedef enum
{
	MDMA_OK = 0,
	MDMA_NOK,
	MDMA_INVALID_PARAMTER,
	MDMA_PTR_NULL
}EN_MDMA_systemState_t;


typedef enum
{
	MDMA_STREAM_ZERO = 0,
	MDMA_STREAM_ONE,
	MDMA_STREAM_TWO,
	MDMA_STREAM_THREE,
	MDMA_STREAM_FOUR,
	MDMA_STREAM_FIVE,
	MDMA_STREAM_SIX,
	MDMA_STREAM_SEVEN
}EN_MDMA_streamIdOptions_t;

#endif /* MCAL_DMA_DMA_CONFIG_H_ */
