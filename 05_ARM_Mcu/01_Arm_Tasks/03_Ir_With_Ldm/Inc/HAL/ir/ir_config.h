/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : ir_config.h                                  	     
// Date          : Sep 18, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_IR_IR_CONFIG_H_
#define HAL_IR_IR_CONFIG_H_

#define IR_ZERO_BTN_VAL              (uint8_t)22
#define IR_ONE_BTN_VAL               (uint8_t)12
#define IR_TWO_BTN_VAL               (uint8_t)24
#define IR_THREE_BTN_VAL             (uint8_t)94
#define IR_FOUR_BTN_VAL              (uint8_t)8
#define IR_FIVE_BTN_VAL              (uint8_t)28
#define IR_SIX_BTN_VAL               (uint8_t)90
#define IR_SEVEN_BTN_VAL             (uint8_t)66
#define IR_EIGHT_BTN_VAL             (uint8_t)82
#define IR_NINE_BTN_VAL              (uint8_t)74


typedef enum
{
	HIR_OK = 0,
	HIR_NOK,
	HIR_INVALID_PARAMTER
}EN_HIR_systemState_t;

#endif /* HAL_IR_IR_CONFIG_H_ */
