/*
 * irSensor_Interface.h
 *
 * Created: 14/07/2023 22:44:17
 *  Author: 20101
 */ 


#ifndef IRSENSOR_INTERFACE_H_
#define IRSENSOR_INTERFACE_H_

#include "../../COMMON/STD_Types.h"
#include "../../MCAL/dio/DIO_interface.h"
#include "irSensor_cfg.h"

extern ST_IR_SENSOR_cfg_t arr_irCfg[IR_ARR_MAX_SIZE];

ENU_IR_SENSOR_systemState_t    IR_SENSOR_init(ST_IR_SENSOR_cfg_t *ptr_irCfg);
ENU_IR_SENSOR_systemState_t    IR_SENSOR_readData(ST_IR_SENSOR_cfg_t *ptr_irCfg , ENU_IR_SENSOR_surfaceState_t *irState);



#endif /* IRSENSOR_INTERFACE_H_ */