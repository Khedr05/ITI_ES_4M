/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : twi_interface.h                                  	     
// Date          : 22 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "twi_private.h"
#include "twi_config.h"

EN_MTWI_systemState_t MTWI_init(ST_MTWI_cfg_t const * ST_ptrMtwiCfgInstance);
EN_MTWI_systemState_t MTWI_enable(void);
EN_MTWI_systemState_t MTWI_disable(void);
EN_MTWI_systemState_t MTWI_start(void);
EN_MTWI_systemState_t MTWI_stop(void);
EN_MTWI_systemState_t MTWI_writedata(uint8_t dataToWrite);
EN_MTWI_systemState_t MTWI_readDataWithAck(uint8_t *retOfData);
EN_MTWI_systemState_t MTWI_readDataWithNotAck(uint8_t *retOfData);
EN_MTWI_systemState_t MTWI_getStatus(uint8_t *retOfStates);



#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
