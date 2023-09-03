/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : 11_Lec_4_Assignment_1                                    	 
// File          : calc_config.h                                  	     
// Date          : 23 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef CALCULATOR_CALC_CONFIG_H_
#define CALCULATOR_CALC_CONFIG_H_


#define OPERAND_MAX_SIZE		100


typedef enum
{
	CALC_SCANNING = 0,
	CALC_CHECK_INPUT,
	CALC_GET_RESUALT,
	CALC_CLR_LCD,
	CALC_FIRST_OPERAND_SAVE,
	CALC_SECOND_OPERAND_SAVE,
	CALC_OPERATOR_SAVE,
	CALC_GET_THE_TWO_OPERAND,
	CALC_DISPLAY_RESULT,
	CALC_INVALID_PARAMTERS
}EN_CALC_states_t;




#endif /* CALCULATOR_CALC_CONFIG_H_ */
