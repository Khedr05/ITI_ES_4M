/*
 * avoid_obstacles_cfg.h
 *
 * Created: 12/07/2023 22:44:04
 *  Author: 20101
 */ 


#ifndef AVOID_OBSTACLES_CFG_H_
#define AVOID_OBSTACLES_CFG_H_


typedef enum
{
   AVOID_OK = 0,
   AVOID_NOK	
}ENU_avoidSystemState_t;

typedef enum
{
	AVOID_CAR_STATE_SCANNING_OBJECT = 0,
	AVOID_CAR_CHECK_OBJECT_DISTANCE,
	AVOID_CAR_DISTANCE_IN_SAFE,
	AVOID_CAR_DISTANCE_IN_UNSAFE,
	AVOID_CAR_SET_DEFAULT_ROTATION,
	AVOID_CAR_EXIT
}ENU_avoidCarState_t;


typedef enum 
{
	AVOID_CAR_ROTATION_RIGHT = 0,
	AVOID_CAR_ROTATION_LEFT
}ENU_avoidCarDefaultRotation_t;

#endif /* AVOID_OBSTACLES_CFG_H_ */
