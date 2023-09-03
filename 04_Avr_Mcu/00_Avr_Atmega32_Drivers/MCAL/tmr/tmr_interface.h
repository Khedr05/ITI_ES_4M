/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : tmr_interface.h                                  	     
// Date          : 17 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_TMR_TMR_INTERFACE_H_
#define MCAL_TMR_TMR_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "../../COMMON/vector_table.h"
#include "../../COMMON/bit_math.h"
#include "tmr_config.h"
#include "tmr_private.h"

EN_MTMR_systemState_t   MTMR_init(ST_MTMR_cfg_t const *ST_ptrCfgInstance_t);
EN_MTMR_systemState_t   MTMR_start(ST_MTMR_cfg_t const *ST_ptrCfgInstance_t);
EN_MTMR_systemState_t   MTMR_stop(ST_MTMR_cfg_t const *ST_ptrCfgInstance_t);
EN_MTMR_systemState_t   MTMR_readTcnt(ST_MTMR_cfg_t const *ST_ptrCfgInstance_t , Uint16_t *retOfTcntValue);
EN_MTMR_systemState_t   MTMR_writeTcntPreload(ST_MTMR_cfg_t const *ST_ptrCfgInstance_t , Uint16_t tcntPreloadValue);
EN_MTMR_systemState_t   MTMR_readOcr(ST_MTMR_cfg_t const *ST_ptrCfgInstance_t , Uint16_t *retOfOcrAValue , Uint16_t *retOfOcrBValue);


#endif /* MCAL_TMR_TMR_INTERFACE_H_ */
