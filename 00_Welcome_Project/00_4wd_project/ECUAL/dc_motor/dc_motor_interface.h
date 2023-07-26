/*
 * dc_motor_interface.h
 *
 * Created: 07/07/2023 18:51:19
 *  Author: 20101
 */ 


#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

#include "../../COMMON/BIT_Math.h"
#include "../../COMMON/STD_Types.h"
#include "../../MCAL/dio/DIO_interface.h"
#include "dc_motor_cfg.h"

extern ST_DCM_cfg_t dcmCfgArr[4];

ENU_DCM_systemState_t DCM_init(ST_DCM_cfg_t *dcmCfg);
ENU_DCM_systemState_t DCM_turnOff(ST_DCM_cfg_t *dcmCfg);
ENU_DCM_systemState_t DCM_turnOn(ST_DCM_cfg_t *dcmCfg);
ENU_DCM_systemState_t DCM_changeDirection(ST_DCM_cfg_t *dcmCfg , ENU_DCM_direction_t dcmDirction);

#endif /* DC_MOTOR_INTERFACE_H_ */
