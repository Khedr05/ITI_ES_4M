/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : tft_interface.h                                  	     
// Date          : Sep 20, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_TFT_TFT_INTERFACE_H_
#define HAL_TFT_TFT_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "../../COMMON/bit_math.h"
#include "../../MCAL/gpio/gpio_interface.h"
#include "../../MCAL/spi/spi_interface.h"
#include "../../MCAL/systick/systick_interface.h"
#include "tft_config.h"
#include "image.h"

EN_HTFT_systeamState_t HTFT_uddtInit(ST_HTFT_cfg_t const *PS_uddtTftCfg);
EN_HTFT_systeamState_t HTFT_uddtWriteCommand(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint8_t copy_u8CommandToSend);
EN_HTFT_systeamState_t HTFT_uddtWriteData(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint8_t copy_u8DataToSend);
EN_HTFT_systeamState_t HTFT_uddtReset(ST_HTFT_cfg_t const *PS_uddtTftCfg);
EN_HTFT_systeamState_t HTFT_uddtDisplayImage(ST_HTFT_cfg_t const *PS_uddtTftCfg);



#endif /* HAL_TFT_TFT_INTERFACE_H_ */
