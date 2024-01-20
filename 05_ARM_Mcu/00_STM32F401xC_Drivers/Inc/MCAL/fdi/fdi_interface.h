/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : fdi_interface.h                                  	     
// Date          : Sep 27, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_FDI_FDI_INTERFACE_H_
#define MCAL_FDI_FDI_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "../../COMMON/bit_math.h"

#include "fdi_private.h"
#include "fdi_config.h"

EN_MFDI_systeamState_t MFDI_uddtEraseSector(uint8_t copy_u8SectorNumber);
EN_MFDI_systeamState_t MFDI_uddtFlashWrite(uint32_t copy_u32Address , uint16_t *copy_u16PtrData , uint8_t copy_u8DataLength);
EN_MFDI_systeamState_t MFDI_uddtEraseAppArea(void);

#endif /* MCAL_FDI_FDI_INTERFACE_H_ */
