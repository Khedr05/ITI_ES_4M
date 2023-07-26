/*
 * mobileControllerProg.c
 *
 * Created: 08/07/2023 21:46:16
 *  Author: 20101
 */ 

#include "mobileControllerInterface.h"

ENU_systemModeStates carState = CAR_IN_SCANNING_STATE;

void mobileControllerModeInterface(void)
{
	Uint8_t exitFlag = 0;
	while(1)
	{
		if(exitFlag == 1)break;
		switch(carState)
		{
			case CAR_IN_SCANNING_STATE :
			{
				BLUETOOTH_send((Uint8_t *)"\r\n");
				BLUETOOTH_send((Uint8_t *)"Now You Are In Mobile Control Mode\r\n");
				BLUETOOTH_send((Uint8_t *)"1 - To Move Forward\r\n");
				BLUETOOTH_send((Uint8_t *)"2 - To Move Backward\r\n");
				BLUETOOTH_send((Uint8_t *)"3 - Rotate Left\r\n");
				BLUETOOTH_send((Uint8_t *)"4 - Rotate Right\r\n");
				BLUETOOTH_send((Uint8_t *)"5 - Stop\r\n");
				BLUETOOTH_send((Uint8_t *)"6 - Exit Mode\r\n");
				BLUETOOTH_send((Uint8_t *)"\r\n");
				carState = BLUETOOTH_ReceiveData();
				BLUETOOTH_vSendData(carState);
				carState -= '0';			
				break;
			}
			case CAR_IN_MOVING_FORWARD_STATE :
			{
				carGoToForward();
				carState = CAR_IN_SCANNING_STATE;
				break;
			}
			case CAR_IN_MOVING_BACKWARD_STATE :
			{
				carGoToReverse();
				carState = CAR_IN_SCANNING_STATE;
				break;
			}
			case CAR_IN_MOVING_ROTATE_LEFT_STATE :
			{
				carGoToRotateLeft();
				carState = CAR_IN_SCANNING_STATE;
				break;
			}
			case CAR_IN_MOVING_ROTATE_RIGHT_STATE :
			{
				carGoToRotateRight();
				carState = CAR_IN_SCANNING_STATE;
				break;
			}
			case CAR_IN_MOVING_STOP_STATE :
			{
				carGoToStop();
				carState = CAR_IN_SCANNING_STATE;
				break;
			}
			case EXIT :
			{
				exitFlag = 1;
				carState = CAR_IN_SCANNING_STATE;
				break;
			}
			default :
			{
				BLUETOOTH_send((Uint8_t *)"Invalid Choice Please Try Again\r\n");
				carState = CAR_IN_SCANNING_STATE;
				break;
			}
		}
	}
}

void carGoToForward(void)
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
void carGoToReverse(void)
{
	DCM_changeDirection(&dcmCfgArr[0] , DCM_DIR_BACKWORD);
	DCM_changeDirection(&dcmCfgArr[1] , DCM_DIR_BACKWORD);
	DCM_changeDirection(&dcmCfgArr[2] , DCM_DIR_BACKWORD);
	DCM_changeDirection(&dcmCfgArr[3] , DCM_DIR_BACKWORD);	
	DCM_turnOn(&dcmCfgArr[0]);
	DCM_turnOn(&dcmCfgArr[1]);
	DCM_turnOn(&dcmCfgArr[2]);
	DCM_turnOn(&dcmCfgArr[3]);
}
void carGoToRotateLeft(void)
{
	DCM_changeDirection(&dcmCfgArr[2] , DCM_DIR_FORWARD);
	DCM_changeDirection(&dcmCfgArr[3] , DCM_DIR_FORWARD);
	DCM_turnOff(&dcmCfgArr[0]);
	DCM_turnOff(&dcmCfgArr[1]);
	DCM_turnOn(&dcmCfgArr[2]);
	DCM_turnOn(&dcmCfgArr[3]);
}
void carGoToRotateRight(void)
{
	DCM_changeDirection(&dcmCfgArr[0] , DCM_DIR_FORWARD);
	DCM_changeDirection(&dcmCfgArr[1] , DCM_DIR_FORWARD);
	DCM_turnOff(&dcmCfgArr[2]);
	DCM_turnOff(&dcmCfgArr[3]);
	DCM_turnOn(&dcmCfgArr[0]);
	DCM_turnOn(&dcmCfgArr[1]);
}
void carGoToStop(void)
{
	DCM_turnOff(&dcmCfgArr[0]);
	DCM_turnOff(&dcmCfgArr[1]);
	DCM_turnOff(&dcmCfgArr[2]);
	DCM_turnOff(&dcmCfgArr[3]);
}
