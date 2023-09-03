/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : twi_config.h                                  	     
// Date          : 22 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_TWI_TWI_CONFIG_H_
#define MCAL_TWI_TWI_CONFIG_H_


typedef enum
{
	MTWI_OK = 0,
	MTWI_NOK,
	MTWI_PTR_NULL
}EN_MTWI_systemState_t;

typedef enum
{
	MTWI_PRESCALER_1 = 0,
	MTWI_PRESCALER_4,
	MTWI_PRESCALER_16,
	MTWI_PRESCALER_64
}EN_MTWI_prescalerSelect_t;

typedef enum
{
	MTWI_DISABLE = 0,
	MTWI_ENABLE,
}EN_MTWI_states_t;



typedef struct
{

	EN_MTWI_prescalerSelect_t		prescalerSelection;
	uint8_t 						deviceAddress;


}ST_MTWI_cfg_t;


#endif /* MCAL_TWI_TWI_CONFIG_H_ */
