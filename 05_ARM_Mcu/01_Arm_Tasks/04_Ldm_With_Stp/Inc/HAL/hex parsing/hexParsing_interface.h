/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : hexParsing_interface.h                                  	     
// Date          : Sep 28, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_HEX_PARSING_HEXPARSING_INTERFACE_H_
#define HAL_HEX_PARSING_HEXPARSING_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "../../COMMON/bit_math.h"
#include "../../MCAL/fdi/fdi_interface.h"

uint8_t HEX_parsAsciiToHex(uint8_t ascii);

void APARSER_voidParseRecord(uint8_t *BufRecord);

void HEX_parsData(uint8_t *data);


#endif /* HAL_HEX_PARSING_HEXPARSING_INTERFACE_H_ */
