/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : adc_interface.h                                  	     
// Date          : 15 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "../../COMMON/vector_table.h"
#include "adc_config.h"
#include "adc_private.h"


EN_MADC_systeamState_t MADC_init(ST_MADC_CFG_t const * ST_ptrAdcCfgInstance_t);
EN_MADC_systeamState_t MADC_deinit(ST_MADC_CFG_t const * ST_ptrAdcCfgInstance_t);
EN_MADC_systeamState_t MADC_startConversion(ST_MADC_CFG_t const * ST_ptrAdcCfgInstance_t);
EN_MADC_systeamState_t MADC_getConversionResult(ST_MADC_CFG_t const * ST_ptrAdcCfgInstance_t, Uint16_t *_ConversionResult);


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
