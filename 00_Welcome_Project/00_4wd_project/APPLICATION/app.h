/*
 * app.h
 *
 * Created: 07/07/2023 18:41:52
 *  Author: 20101
 */ 


#ifndef APP_H_
#define APP_H_

#define F_CPU 8000000UL

#include "../ECUAL/dc_motor/dc_motor_interface.h"
#include "../ECUAL/ultrasonic/ultra.h"
#include "../ECUAL/ir_sensor/irSensor_Interface.h"
#include "../ECUAL/bluetooth/bluetooth_interface.h"
#include "../ROBOT_MODES/avoiding_obstacles/avoid_obstacles_interface.h"
#include "../ROBOT_MODES/line_follower/lineFollower_interface.h"
#include "../ROBOT_MODES/mobile_controller/mobileControllerInterface.h"




typedef enum
{
	SLEEP_MODE = 0,
	MOBILE_CONTROLLER_MODE,
	LINE_FOLLOWER_MODE,
	AVOIDING_OBSTACLES_MODE
	
	
}ENU_robotCarMode;

void app_init(void);
void app_flow(void);


#endif /* APP_H_ */
