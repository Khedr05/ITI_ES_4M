/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 11_Lec_4_Assignment_1                                    	 
// File          : calc_interface.h                                  	     
// Date          : 23 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef CALCULATOR_CALC_INTERFACE_H_
#define CALCULATOR_CALC_INTERFACE_H_

#include <string.h>
#include "../APPLICATION/devices_cfg.h"
#include "calc_config.h"

void CALC_interface(void);


void CALC_checkInput(void);
void CALC_saveFirstOperand(void);
void CALC_saveSecondOperand(void);
void CALC_saveOperator(void);
void CALC_getValueOfOperand(void);
void CALC_getResult(void);
void CALC_afterResult(void);
void CALC_clrDisplay(void);

#endif /* CALCULATOR_CALC_INTERFACE_H_ */
