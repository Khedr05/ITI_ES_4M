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
#define HTFT_COMMAND_PARAMTER_X_AXIS_START		0
#define HTFT_COMMAND_PARAMTER_X_AXIS_END		127
#define HTFT_COMMAND_PARAMTER_Y_AXIS_START		0
#define HTFT_COMMAND_PARAMTER_Y_AXIS_END		159

#define HTFT_BLACK_COLOR 			 0x0000
#define HTFT_BLUE_COLOR 			 0x001F
#define HTFT_RED_COLOR 				 0xF800
#define HTFT_GREEN_COLOR 			 0x0400
#define HTFT_LIME_COLOR 			 0x07E0
#define HTFT_CYAN_COLOR 			 0x07FF
#define HTFT_MAGENTA_COLOR 			 0xF81F
#define HTFT_YELLOW_COLOR 			 0xFFE0
#define HTFT_WHITE_COLOR			 0xFFFF

typedef struct
{
    const uint8_t width;
    uint8_t height;
    const uint16_t *data;
} FontDef;


extern FontDef Font_7x10;
extern FontDef Font_11x18;
extern FontDef Font_16x26;


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
