/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 19_Lec_14_Lab_2                                    	 
// File          : device_cfg.h                                  	     
// Date          : 2 Sept 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef APPLICATION_DEVICE_CFG_H_
#define APPLICATION_DEVICE_CFG_H_

#include "../HAL/lcd/lcd_interface.h"
#include "../MCAL/spi/spi_interface.h"

extern ST_HLCD_cfg_t myLcd;
extern ST_MSPI_cfg_t MASTER_spi;
extern ST_MSPI_cfg_t SLAVE_spi;

#endif /* APPLICATION_DEVICE_CFG_H_ */
