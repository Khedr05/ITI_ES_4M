/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : ssd_config.h                                  	     
// Date          : Sep 15, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_SSD_SSD_CONFIG_H_
#define HAL_SSD_SSD_CONFIG_H_


#define DOT_PIN    7
#define COM_PIN	   8


typedef enum
{
	HSSD_OK = 0,
	HSSD_NOK,
	HSSD_INVALID_PARAMTERS,
	HSSD_PTR_NULL
}EN_HSSD_systemState_t;

typedef enum
{
	HSSD_COMMAN_ANODE = 0,
	HSSD_COMMAN_CATHODE
}EN_HSSD_commanOptions_t;


typedef enum
{
	HSSD_ZERO = 0,
	HSSD_ONE,
	HSSD_TWO,
	HSSD_THREE,
	HSSD_FOUR,
	HSSD_FIVE,
	HSSD_SIX,
	HSSD_SEVEN,
	HSSD_EGIHT,
	HSSD_NINE
}EN_HSSD_numberOptions_t;

typedef struct
{
	EN_HSSD_commanOptions_t      uddtCommanPinMode;
	EN_MGPIO_portOptions_t		 uddtSsdPortsName[9];
	EN_MGPIO_pinOptions_t		 uddtSsdPinsNumber[9];

}ST_HSSD_cfg_t;

#endif /* HAL_SSD_SSD_CONFIG_H_ */
