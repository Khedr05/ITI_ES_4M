/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : gpio_interface.h                                  	     
// Date          : Sep 10, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "gpio_private.h"
#include "gpio_config.h"



EN_MGPIO_systemState_t MGPIO_uddtSetPinMode  	(ST_MGPIOx_RegistersMap_t  *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_pinModeOptions_t copy_uddtPinMode);
EN_MGPIO_systemState_t MGPIO_uddtSetOutputMode  (ST_MGPIOx_RegistersMap_t  *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_outputResistorOptions_t copy_uddtOutputResistor);
EN_MGPIO_systemState_t MGPIO_uddtSetOutputSpeed (ST_MGPIOx_RegistersMap_t  *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_outputSpeedOptions_t copy_uddtOutputSpeed );
EN_MGPIO_systemState_t MGPIO_uddtSetPullState   (ST_MGPIOx_RegistersMap_t  *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_pushPullOptions_t copy_uddtPullState );
EN_MGPIO_systemState_t MGPIO_uddtGetPinVal  	(ST_MGPIOx_RegistersMap_t  *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_pinLogicOptions_t *copy_uddtPtrRetOfPinLogic);
EN_MGPIO_systemState_t MGPIO_uddtSetPinVal  	(ST_MGPIOx_RegistersMap_t  *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_pinLogicOptions_t copy_uddtPinLogic);
EN_MGPIO_systemState_t MGPIO_uddtDirectSetReset (ST_MGPIOx_RegistersMap_t  *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_setResetOptions_t copy_uddtSetResetState );
EN_MGPIO_systemState_t MGPIO_uddtSetPortVal 	(ST_MGPIOx_RegistersMap_t  *PS_GPIOx , uint16_t copy_u16OutputVal);
EN_MGPIO_systemState_t MGPIO_uddtSetAltFun 		(ST_MGPIOx_RegistersMap_t  *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_altfnOptions_t Copy_uddtAltFun);
EN_MGPIO_systemState_t MGPIO_uddtInitPin		(ST_MGPIO_pinCfg_t *PS_pinInstance);
EN_MGPIO_systemState_t MGPIO_uddtInitAltPin		(ST_MGPIO_altPinCfg_t *PS_altPinInstance);



//EN_MGPIO_systemState_t MGPIO_PinLock 		(u8 copy_u8PortName , u8 copy_u8PinNum );
//EN_MGPIO_systemState_t MGPIO_SetPortMode (u8 Copy_u8PortName , u8 Copy_u8Mode);


#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
