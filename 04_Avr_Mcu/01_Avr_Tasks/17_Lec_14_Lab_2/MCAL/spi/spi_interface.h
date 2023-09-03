/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : spi_interface.h                                  	     
// Date          : 21 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "../../MCAL/gpio/gpio_interface.h"
#include "spi_private.h"
#include "spi_config.h"




EN_MSPI_systemState_t MSPI_init(ST_MSPI_cfg_t const *ST_ptrSpiCfgInstance);
EN_MSPI_systemState_t MSPI_enable(void);
EN_MSPI_systemState_t MSPI_disable(void);
EN_MSPI_systemState_t MSPI_recive(uint8_t *retOfData);
EN_MSPI_systemState_t MSPI_send(uint8_t DataToSend);






#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
