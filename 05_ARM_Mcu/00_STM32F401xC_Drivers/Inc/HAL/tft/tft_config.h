/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : tft_config.h                                  	     
// Date          : Sep 20, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_TFT_TFT_CONFIG_H_
#define HAL_TFT_TFT_CONFIG_H_

#define HTFT_COMMAND_SLEEP_OUT					0x11
#define HTFT_COMMAND_COLOR_MODE					0x3A
#define HTFT_COMMAND_DISPLAY_ON					0x29
#define HTFT_COMMAND_X_AXIS						0x2A
#define HTFT_COMMAND_Y_AXIS						0x2B
#define HTFT_COMMAND_RAM_WRITE					0x2C

#define HTFT_COMMAND_PARAMTER_RGB_565			0x05
#define HTFT_COMMAND_PARAMTER_X_AXIS_START		0x0
#define HTFT_COMMAND_PARAMTER_X_AXIS_END		0x127
#define HTFT_COMMAND_PARAMTER_Y_AXIS_START		0x0
#define HTFT_COMMAND_PARAMTER_Y_AXIS_END		0x159



typedef enum
{
	HTFT_OK = 0,
	HTFT_NOK,
	HTFT_PTR_NULL
}EN_HTFT_systeamState_t;


typedef struct
{
	EN_MGPIO_portOptions_t		rstPort;
	EN_MGPIO_portOptions_t		rstPin;
	EN_MGPIO_portOptions_t		a0Port;
	EN_MGPIO_portOptions_t		a0Pin;
}ST_HTFT_cfg_t;



#endif /* HAL_TFT_TFT_CONFIG_H_ */
