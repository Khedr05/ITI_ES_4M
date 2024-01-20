/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : dma_interface.h                                  	     
// Date          : Sep 17, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_DMA_DMA_INTERFACE_H_
#define MCAL_DMA_DMA_INTERFACE_H_


#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "dma_private.h"
#include "dma_config.h"



EN_MDMA_systemState_t MDMA_uddtInit(EN_MDMA_streamIdOptions_t copy_uddtStreamId);
EN_MDMA_systemState_t MDMA_uddtSetAddress(EN_MDMA_streamIdOptions_t copy_uddtStreamId , uint32_t *copy_u32SrcAddress,uint32_t *copy_u32DestAddress,uint32_t copy_u32Length);

EN_MDMA_systemState_t MDMA_uddtStreamEnable(EN_MDMA_streamIdOptions_t copy_uddtStreamId );
EN_MDMA_systemState_t MDMA_uddtStreamDisable(EN_MDMA_streamIdOptions_t copy_uddtStreamId );

EN_MDMA_systemState_t MDMA_uddtInterruptEnable(EN_MDMA_streamIdOptions_t copy_uddtStreamId );
EN_MDMA_systemState_t MDMA_uddtInterruptDisable(EN_MDMA_streamIdOptions_t copy_uddtStreamId );

EN_MDMA_systemState_t MDMA_uddtSetCallBack(EN_MDMA_streamIdOptions_t copy_uddtStreamId , void(*Pf)(void));
EN_MDMA_systemState_t MDMA_uddtClearFlag(EN_MDMA_streamIdOptions_t copy_uddtStreamId );


#endif /* MCAL_DMA_DMA_INTERFACE_H_ */
