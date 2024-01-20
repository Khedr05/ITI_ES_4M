/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : dma_private.h                                  	     
// Date          : Sep 17, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_DMA_DMA_PRIVATE_H_
#define MCAL_DMA_DMA_PRIVATE_H_

#define	MDMA1_PERIPHERAL_BASE_ADDR	(0x40026000)
#define	MDMA2_PERIPHERAL_BASE_ADDR	(0x40026400)


typedef struct
{
	vuint32_t	MDMA_CR;    /* Configuration register     */
	vuint32_t	MDMA_NDTR;  /* Number of Data Register    */
	vuint32_t	MDMA_PAR;   /* Peripheral Address Register*/
	vuint32_t	MDMA_M0AR;  /* Memory 0 Address Register  */
	vuint32_t	MDMA_M1AR;  /* Memory 1 Address Register  */
	vuint32_t	MDMA_FCR;   /* FIFO Control Register      */

}ST_MDMA_streamMembers_t;

typedef struct
{
	vuint32_t 				MDMA_LISR;    /* DMA Low ISR register                   */
	vuint32_t 				MDMA_HISR;    /* DMA High ISR register                  */
	vuint32_t 				MDMA_LIFCR;   /* DMA Low Interrupt Flag Clear register  */
	vuint32_t 				MDMA_HIFCR;   /* DMA High Interrupt Flag Clear register */
	ST_MDMA_streamMembers_t MDMA_Streamx[8];

}ST_MDMAx_RegistersMap_t;



#define MDMA1_PERIPHERAL ((volatile ST_MDMAx_RegistersMap_t *)MDMA1_PERIPHERAL_BASE_ADDR)
#define MDMA2_PERIPHERAL ((volatile ST_MDMAx_RegistersMap_t *)MDMA2_PERIPHERAL_BASE_ADDR)



#endif /* MCAL_DMA_DMA_PRIVATE_H_ */
