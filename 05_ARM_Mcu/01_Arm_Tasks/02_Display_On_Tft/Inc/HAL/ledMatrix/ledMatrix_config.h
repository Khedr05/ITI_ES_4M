/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : ledMatrix_config.h                                  	     
// Date          : Sep 13, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_LEDMATRIX_LEDMATRIX_CONFIG_H_
#define HAL_LEDMATRIX_LEDMATRIX_CONFIG_H_


typedef enum
{
	HLDM_OK = 0,
	HLDM_NOK,
	HLDM_INVALID_PARAMTER
}EN_HLDM_systemState_t;


typedef struct
{
	EN_MGPIO_portOptions_t   copy_uddtLdmRowPort;
	EN_MGPIO_portOptions_t   copy_uddtLdmColPort;
	EN_MGPIO_pinOptions_t	 copy_uddtLdmRowPins[8];
	EN_MGPIO_pinOptions_t	 copy_uddtLdmColPins[8];


}ST_HLDM_cfg_t;


#endif /* HAL_LEDMATRIX_LEDMATRIX_CONFIG_H_ */
