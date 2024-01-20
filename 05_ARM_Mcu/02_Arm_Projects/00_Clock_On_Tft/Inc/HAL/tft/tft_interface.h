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
//#include "image.h"

EN_HTFT_systeamState_t HTFT_uddtInit(ST_HTFT_cfg_t const *PS_uddtTftCfg);
EN_HTFT_systeamState_t HTFT_uddtWriteCommand(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint8_t copy_u8CommandToSend);
EN_HTFT_systeamState_t HTFT_uddtWriteData(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint8_t copy_u8DataToSend);
EN_HTFT_systeamState_t HTFT_uddtReset(ST_HTFT_cfg_t const *PS_uddtTftCfg);
EN_HTFT_systeamState_t HTFT_uddtDisplayImage(ST_HTFT_cfg_t const *PS_uddtTftCfg ,uint16_t const *copy_u16ArrayOfImage);
EN_HTFT_systeamState_t HTFT_uddtFillBackgroundColor(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint16_t copy_u16Color);
EN_HTFT_systeamState_t HTFT_uddtSetXYAxis(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint8_t copy_u8XAxisStart , uint8_t copy_u8XAxisEnd , uint8_t copy_u8YAxisStart , uint8_t copy_u8YAxisEnd);
EN_HTFT_systeamState_t HTFT_uddtFillRetangle(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint16_t copy_u16Color , uint8_t copy_u8XAxisStart , uint8_t copy_u8XAxisEnd , uint8_t copy_u8YAxisStart , uint8_t copy_u8YAxisEnd);
EN_HTFT_systeamState_t HTFT_uddtDrawHorizontalLine(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint16_t copy_u16Color ,  uint8_t copy_u8XAxisStart , uint8_t copy_u8XAxisEnd , uint8_t copy_u8YAxisStart);
EN_HTFT_systeamState_t HTFT_uddtDrawVerticalLine(ST_HTFT_cfg_t const *PS_uddtTftCfg ,  uint16_t copy_u16Color , uint8_t copy_u8XAxisStart , uint8_t copy_u8YAxisStart , uint8_t copy_u8YAxisEnd);
EN_HTFT_systeamState_t HTFT_uddtDrawTriangle(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint16_t copy_u16Color , uint8_t copy_u8XAxisStart , uint8_t copy_u8XAxisEnd , uint8_t copy_u8YAxisStart , uint8_t copy_u8YAxisEnd);
EN_HTFT_systeamState_t HTFT_uddtDrawCircle(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint16_t copy_u16Color , uint8_t copy_u8XAxisStart , uint8_t copy_u8XAxisEnd , uint8_t copy_u8YAxisStart , uint8_t copy_u8YAxisEnd);
EN_HTFT_systeamState_t HTFT_uddtDrawRetangle(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint16_t copy_u16Color , uint8_t copy_u8XAxisStart , uint8_t copy_u8XAxisEnd , uint8_t copy_u8YAxisStart , uint8_t copy_u8YAxisEnd);
EN_HTFT_systeamState_t HTFT_uddtClrDisplay(ST_HTFT_cfg_t const *PS_uddtTftCfg);

EN_HTFT_systeamState_t HTFT_uddtDrawChar(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint8_t copy_u8XAxis, uint8_t copy_u8YAxis , uint8_t Copy_u8Character,
						FontDef copy_uddtFontSize, uint16_t copy_u16Color, uint16_t copy_u16BgColor );

EN_HTFT_systeamState_t HTFT_uddtDrawString(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint16_t copy_u8XAxis , uint16_t copy_u8YAxis ,  char* copy_PtrStr,
						  FontDef copy_uddtFontSize, uint16_t copy_u16Color, uint16_t copy_u16BgColor);







#endif /* HAL_TFT_TFT_INTERFACE_H_ */
