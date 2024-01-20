/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : wifi_interface.h                                  	     
// Date          : Sep 25, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_WIFI_WIFI_INTERFACE_H_
#define HAL_WIFI_WIFI_INTERFACE_H_

#include "../../COMMON/std_types.h"

void HESP8266_VidInit(void);
void HESP8266_VidConnectToWiFi( uint8_t * SSID , uint8_t * Password);
void HESP8266_VidConnectToSrvTcp( uint8_t * Copy_u8Domain , uint8_t * Copy_u8Port);
void HESP8266_VidSendHttpReq(uint8_t * Copy_u8Key , uint8_t * Copy_u8Data , uint8_t * Copy_u8Length);
uint8_t HESP8266_u8ReceiveHttpReq( uint8_t * Copy_u8ChannelID , uint8_t * Copy_u8Length);
void HESP8266_VidClearBuffer(void);



#endif /* HAL_WIFI_WIFI_INTERFACE_H_ */
