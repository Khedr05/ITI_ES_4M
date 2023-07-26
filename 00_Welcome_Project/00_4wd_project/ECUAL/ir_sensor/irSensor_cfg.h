/*
 * irSensor_cfg.h
 *
 * Created: 14/07/2023 22:44:58
 *  Author: 20101
 */ 


#ifndef IRSENSOR_CFG_H_
#define IRSENSOR_CFG_H_

#define IR_ARR_MAX_SIZE		2

typedef enum
{
  IR_SENSOR_OK = 0,
  IR_SENSOR_NOK	
}ENU_IR_SENSOR_systemState_t;


typedef enum
{
	IR_SENSOR_ON_WHITE = 0,
	IR_SENSOR_ON_BLACK	
}ENU_IR_SENSOR_surfaceState_t;


typedef struct  
{
	EN_pin_index_t    IR_pin;
	EN_port_index_t   IR_port;
}ST_IR_SENSOR_cfg_t;

#endif /* IRSENSOR_CFG_H_ */