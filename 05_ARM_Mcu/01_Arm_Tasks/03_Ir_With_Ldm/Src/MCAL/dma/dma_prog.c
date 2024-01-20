/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : dma_prog.c                                  	     
// Date          : Sep 17, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/MCAL/dma/dma_interface.h"

static void (*MDMA2_CallBackHandler)(void) = PTR_NULL;

EN_MDMA_systemState_t MDMA_uddtInit(EN_MDMA_streamIdOptions_t copy_uddtStreamId)
{
    // Step 1: Check if the stream is enabled and clear it if necessary
    if (GET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 0) == 1)
    {
        CLR_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 0);
    }

    // Step 2: Select channel by clearing bits 25, 26, and 27
    CLR_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 27);
    CLR_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 26);
    CLR_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 25);

    // Step 3: Set software priority to the highest (bits 17 and 16)
    SET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 17);
    SET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 16);

    // Step 4: Set data transfer direction (bits 7 and 6)
    SET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 7);
    CLR_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 6);

    // Step 5: Enable circular mode (bit 8)
    SET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 8);

    // Step 6: Set source and destination data size (bits 14, 13, 12, and 11)
    SET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 14);
    CLR_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 13);
    SET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 12);
    CLR_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 11);

    // Step 7: Disable direct mode (bit 2 in MDMA_FCR)
    SET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_FCR, 2);

    // Step 8: Set threshold (bits 1 and 0 in MDMA_FCR)
    SET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_FCR, 1);
    SET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_FCR, 0);

    // Step 9: Enable source and destination address increment (bits 10 and 9)
    SET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 10); // MINC
    SET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 9);  // PINC

    // Step 10: Enable interrupt on transfer complete (bit 4)
    SET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR, 4);

    return MDMA_OK;
}



EN_MDMA_systemState_t MDMA_uddtSetAddress(EN_MDMA_streamIdOptions_t copy_uddtStreamId , uint32_t *copy_u32SrcAddress,uint32_t *copy_u32DestAddress,uint32_t copy_u32Length)
{
	// send src address to PAr
	MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_PAR = (uint32_t)copy_u32SrcAddress;
	//send dest address to m0ar
	MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_M0AR = (uint32_t)copy_u32DestAddress;
	//send length to ndtr
	MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_NDTR = copy_u32Length;
}


EN_MDMA_systemState_t MDMA_uddtStreamEnable(EN_MDMA_streamIdOptions_t copy_uddtStreamId )
{
	EN_MDMA_systemState_t ret = MDMA_NOK;

	if(copy_uddtStreamId >= MDMA_STREAM_ZERO && copy_uddtStreamId <= MDMA_STREAM_SEVEN)
	{
		MDMA_uddtClearFlag(copy_uddtStreamId);
		SET_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR , 0);
		ret = MDMA_OK;
	}
	else
	{
		ret = MDMA_INVALID_PARAMTER;
	}

	return ret;
}

EN_MDMA_systemState_t MDMA_uddtStreamDisable(EN_MDMA_streamIdOptions_t copy_uddtStreamId )
{
	EN_MDMA_systemState_t ret = MDMA_NOK;

	if(copy_uddtStreamId >= MDMA_STREAM_ZERO && copy_uddtStreamId <= MDMA_STREAM_SEVEN)
	{
		CLR_BIT(MDMA2_PERIPHERAL->MDMA_Streamx[copy_uddtStreamId].MDMA_CR , 0);
		ret = MDMA_OK;
	}
	else
	{
		ret = MDMA_INVALID_PARAMTER;
	}

	return ret;
}

EN_MDMA_systemState_t MDMA_uddtSetCallBack(EN_MDMA_streamIdOptions_t copy_uddtStreamId , void(*Pf)(void))
{
	EN_MDMA_systemState_t ret = MDMA_NOK;
	if(PTR_NULL != Pf)
	{
		MDMA2_CallBackHandler = Pf;
		ret = MDMA_OK;
	}
	else
	{
		ret = MDMA_PTR_NULL;
	}
	return ret;
}

EN_MDMA_systemState_t MDMA_uddtClearFlag(EN_MDMA_streamIdOptions_t copy_uddtStreamId )
{
	MDMA2_PERIPHERAL->MDMA_LIFCR|=(1U<<0)|(1U<<2)|(1U<<3)|(1U<<4)|(1U<<5);
}


void DMA2_Stream0_IRQHandler(void)
{
	if(PTR_NULL != MDMA2_CallBackHandler)
	{
		MDMA2_CallBackHandler();
	}
	else
	{
		/* Do Nothing */
	}
	MDMA_uddtClearFlag(MDMA_STREAM_ZERO);
}

