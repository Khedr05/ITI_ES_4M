/*
 * dc_motor_cfg.h
 *
 * Created: 07/07/2023 18:50:55
 *  Author: 20101
 */ 


#ifndef DC_MOTOR_CFG_H_
#define DC_MOTOR_CFG_H_

#include "../../MCAL/dio/DIO_interface.h"

typedef enum
{
 	DCM_OK = 0,
	DCM_NOK
}ENU_DCM_systemState_t;


typedef enum 
{
	
  DCM_TURN_OFF = 0,
  DCM_TURN_ON	
}ENU_DCM_states_t;

typedef enum
{	
	DCM_DIR_FORWARD = 0,
	DCM_DIR_BACKWORD
}ENU_DCM_direction_t;

typedef enum
{
   DCM_ROTATE_LEFT = 0,
   DCM_ROTATE_RIGHT
}ENU_DCM_rotation_t;

typedef struct  
{
	EN_port_index_t   DCM_5vPort;
	EN_pin_index_t    DCM_5vPin;
	EN_port_index_t   DCM_gndPort;
	EN_pin_index_t    DCM_gndPin;
	ENU_DCM_states_t  DCM_intialState;
    ENU_DCM_direction_t DCM_defaultDirection;
}ST_DCM_cfg_t;

#endif /* DC_MOTOR_CFG_H_ */