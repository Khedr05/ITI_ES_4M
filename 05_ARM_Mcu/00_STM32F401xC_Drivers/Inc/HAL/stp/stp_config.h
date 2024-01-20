/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : stp_config.h                                  	     
// Date          : Sep 26, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_STP_STP_CONFIG_H_
#define HAL_STP_STP_CONFIG_H_

typedef enum
{
	HSTP_OK = 0,
	HSTP_NOK,
	HSTP_PTR_NULL
}EN_HSTP_systeamState_t;


typedef struct
{
	EN_MGPIO_portOptions_t dataPortName;
	EN_MGPIO_pinOptions_t  dataPinNumber;
	EN_MGPIO_portOptions_t latchBytePortName;
	EN_MGPIO_pinOptions_t  latchBytePinNumber;
	EN_MGPIO_portOptions_t latchBitPortName;
	EN_MGPIO_pinOptions_t  latchBitPinNumber;
}ST_HSTP_cfg_t;

#endif /* HAL_STP_STP_CONFIG_H_ */
