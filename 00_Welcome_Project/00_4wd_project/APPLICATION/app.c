/*
 * app.c
 *
 * Created: 07/07/2023 18:41:38
 *  Author: 20101
 */ 

#include "app.h"

ENU_robotCarMode carMode = SLEEP_MODE;
Uint8_t userChoice = 0;

void app_init(void)
{
	   BLUETOOTH_init();
	   IR_SENSOR_init(&arr_irCfg[0]);
	   IR_SENSOR_init(&arr_irCfg[1]);
	   DCM_init(&dcmCfgArr[0]);
	   DCM_init(&dcmCfgArr[1]);
	   DCM_init(&dcmCfgArr[2]);
	   DCM_init(&dcmCfgArr[3]);
	   DCM_changeDirection(&dcmCfgArr[0] , DCM_DIR_FORWARD);
	   DCM_changeDirection(&dcmCfgArr[1] , DCM_DIR_FORWARD);
	   DCM_changeDirection(&dcmCfgArr[2] , DCM_DIR_FORWARD);
	   DCM_changeDirection(&dcmCfgArr[3] , DCM_DIR_FORWARD);
	   HCSR04_vInit();
}

void app_flow(void)
{	
	switch(carMode)
	{
		case SLEEP_MODE:
		{
			BLUETOOTH_send((Uint8_t *)"\r\n");
			BLUETOOTH_send((Uint8_t *)"Hello I am Your 4WD Robot Car Please Choose Operation Mode\r\n");
			BLUETOOTH_send((Uint8_t *)"1 - Mobile Controller Mode\r\n");
			BLUETOOTH_send((Uint8_t *)"2 - Line Follower Mode\r\n");
			BLUETOOTH_send((Uint8_t *)"3 - Avoiding Obstacles Mode\r\n");
			BLUETOOTH_send((Uint8_t *)"\r\n");
			carMode = BLUETOOTH_ReceiveData();
			BLUETOOTH_vSendData(carMode);
			carMode -= '0';		    
		    break;	
		}
		case MOBILE_CONTROLLER_MODE:
		{
			mobileControllerModeInterface();
			carMode = SLEEP_MODE;
			break;
		}
		case LINE_FOLLOWER_MODE:
		{	
			lineFollowerInterface();
			carMode = SLEEP_MODE;
			break;
		}
		case AVOIDING_OBSTACLES_MODE:
		{
			AVOID_OBSTACLES_INTERFACE();
			carMode = SLEEP_MODE;			
			break;
		}						
		default:
		{
			BLUETOOTH_send((Uint8_t *)"Invalid Choice Please Try Again\r\n");
			carMode = SLEEP_MODE;
			break;
		}	
	}	
}
