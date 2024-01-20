/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : spi_interface.h                                  	     
// Date          : Sep 20, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "../../COMMON/bit_math.h"
#include "spi_private.h"
#include "spi_config.h"

EN_MSPI_systeamState_t MSPI_uddtInit(ST_MSPI_cfg_t const *PS_uddtSpiCfg);

EN_MSPI_systeamState_t MSPI_uddtSendBlocking(uint8_t copy_u8DataToSend);

EN_MSPI_systeamState_t MSPI_uddtReceiveBlocking(uint8_t *copy_u8DataToReceive);


#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
