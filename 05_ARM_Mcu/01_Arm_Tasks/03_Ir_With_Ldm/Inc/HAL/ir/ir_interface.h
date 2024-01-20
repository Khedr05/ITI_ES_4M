/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : ir_interface.h                                  	     
// Date          : Sep 18, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_IR_IR_INTERFACE_H_
#define HAL_IR_IR_INTERFACE_H_


#include "../../MCAL/gpio/gpio_interface.h"
#include "../../MCAL/exti/exti_interface.h"
#include "../../MCAL/systick/systick_interface.h"
#include "../../MCAL/nvic/nvic_interface.h"
#include "ir_config.h"

EN_HIR_systemState_t HIR_uddtIrReceiveInit(EN_MGPIO_portOptions_t copy_uddtIrPortNumber , EN_MGPIO_pinOptions_t copy_uddtIrPinNumber);
static void HIR_uddtIrReceive(void);
static void HIR_uddtIrGetDataLogic(void);

EN_HIR_systemState_t HIR_uddtIrGetDataVal(uint8_t *retOfDataVal);



#endif /* HAL_IR_IR_INTERFACE_H_ */
