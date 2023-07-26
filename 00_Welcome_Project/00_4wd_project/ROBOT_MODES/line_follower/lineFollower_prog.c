/*
 * lineFollower_prog.c
 *
 * Created: 19/07/2023 22:04:29
 *  Author: 20101
 */ 



#include "lineFollower_interface.h"

void lineFollowerInterface(void)
{
	
	ENU_lineFollowerState_t robotState = LINE_FOLLOWER_IR_SCANNING;
	ENU_IR_SENSOR_surfaceState_t leftSensorRead = IR_SENSOR_ON_WHITE;
	ENU_IR_SENSOR_surfaceState_t rightSensorRead = IR_SENSOR_ON_WHITE;
	Uint8_t exitFlag = 0;
	
	BLUETOOTH_send((Uint8_t *)"Line Follower Start\r\n");
	while(1)
	{
		if(exitFlag == 1) break;
		switch(robotState)
		{
			case LINE_FOLLOWER_IR_SCANNING:
			{
				IR_SENSOR_readData(&arr_irCfg[0] , &rightSensorRead);
				IR_SENSOR_readData(&arr_irCfg[1] , &leftSensorRead);
				robotState = LINE_FOLLOWER_TAKE_DECISION;
				break;
			}
			case LINE_FOLLOWER_TAKE_DECISION :
			{
				if(rightSensorRead == IR_SENSOR_ON_WHITE && leftSensorRead == IR_SENSOR_ON_WHITE)
				{
					robotState = LINE_FOLLOWER_MOVE;
				}
				else if(rightSensorRead == IR_SENSOR_ON_BLACK && leftSensorRead == IR_SENSOR_ON_WHITE)
				{
					robotState = LINE_FOLLOWER_RIGHT;
				}
				else if(rightSensorRead == IR_SENSOR_ON_WHITE && leftSensorRead == IR_SENSOR_ON_BLACK)
				{
					robotState = LINE_FOLLOWER_LEFT;
				}
				else if(rightSensorRead == IR_SENSOR_ON_BLACK && leftSensorRead == IR_SENSOR_ON_BLACK)
				{
					robotState = LINE_FOLLOWER_STOP;
				}
				else
				{
					/* Do Nothing */
				}
				break;
			}
			case LINE_FOLLOWER_MOVE :
			{
				lineFollowerCarGoToForward();
				robotState = LINE_FOLLOWER_IR_SCANNING;
				break;
			}
			case LINE_FOLLOWER_LEFT :
			{
				lineFollowerCarGoToRotateLeft();
				robotState = LINE_FOLLOWER_IR_SCANNING;
				break;
			}
			case LINE_FOLLOWER_RIGHT :
			{
				lineFollowerCarGoToRotateRight();
				robotState = LINE_FOLLOWER_IR_SCANNING;
				break;
			}
			case LINE_FOLLOWER_STOP :
			{
				lineFollowerCarGoToStop();
				robotState = LINE_FOLLOWER_EXIT;
				break;
			}
			case LINE_FOLLOWER_EXIT :
			{
				BLUETOOTH_send((Uint8_t *)"Line Follower Reach The End Of The Line\r\n");
				exitFlag = 1;
				break;
			}
		}
	}
}


void lineFollowerCarGoToForward(void)
{
	DCM_changeDirection(&dcmCfgArr[0] , DCM_DIR_FORWARD);
	DCM_changeDirection(&dcmCfgArr[1] , DCM_DIR_FORWARD);
	DCM_changeDirection(&dcmCfgArr[2] , DCM_DIR_FORWARD);
	DCM_changeDirection(&dcmCfgArr[3] , DCM_DIR_FORWARD);
	DCM_turnOn(&dcmCfgArr[0]);
	DCM_turnOn(&dcmCfgArr[1]);
	DCM_turnOn(&dcmCfgArr[2]);
	DCM_turnOn(&dcmCfgArr[3]);
}
void lineFollowerCarGoToRotateLeft(void)
{
	DCM_changeDirection(&dcmCfgArr[2] , DCM_DIR_FORWARD);
	DCM_changeDirection(&dcmCfgArr[3] , DCM_DIR_FORWARD);
	DCM_turnOff(&dcmCfgArr[0]);
	DCM_turnOff(&dcmCfgArr[1]);
	DCM_turnOn(&dcmCfgArr[2]);
	DCM_turnOn(&dcmCfgArr[3]);
}
void lineFollowerCarGoToRotateRight(void)
{
	DCM_changeDirection(&dcmCfgArr[0] , DCM_DIR_FORWARD);
	DCM_changeDirection(&dcmCfgArr[1] , DCM_DIR_FORWARD);
	DCM_turnOff(&dcmCfgArr[2]);
	DCM_turnOff(&dcmCfgArr[3]);
	DCM_turnOn(&dcmCfgArr[0]);
	DCM_turnOn(&dcmCfgArr[1]);
}
void lineFollowerCarGoToStop(void)
{
	DCM_turnOff(&dcmCfgArr[0]);
	DCM_turnOff(&dcmCfgArr[1]);
	DCM_turnOff(&dcmCfgArr[2]);
	DCM_turnOff(&dcmCfgArr[3]);
}
