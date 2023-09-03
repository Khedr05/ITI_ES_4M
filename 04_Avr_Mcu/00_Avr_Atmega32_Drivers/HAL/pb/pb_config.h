/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : pb_config.h                                  	     
// Date          : 14 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_PB_PB_CONFIG_H_
#define HAL_PB_PB_CONFIG_H_

typedef enum
{
	HPB_OK = 0,
	HPB_NOK,
	HPB_PTR_NULL
}EN_HPB_systeamState_t;

typedef enum
{
    HPB_STATE_PRESSED = 0,
	HPB_STATE_RELEASED
}EN_HPB_state_t;


typedef enum
{
	HPB_PULL_DOWN = 0,
    HPB_PULL_UP
}EN_HPB_internalResistor_t;


typedef struct
{
    EN_GPIO_mcuPins_t PbPin;
    EN_GPIO_mcuPorts_t pbPort;
    EN_HPB_internalResistor_t PbInternalResistor;
}ST_HPB_cfg_t;

#endif /* HAL_PB_PB_CONFIG_H_ */
