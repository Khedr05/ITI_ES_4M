/*
 * avoid_obstacles.c
 *
 * Created: 12/07/2023 22:42:33
 *  Author: 20101
 */ 

#include "avoid_obstacles_interface.h"


ENU_avoidSystemState_t AVOID_OBSTACLES_INTERFACE(void)
{
	ENU_avoidCarState_t AVOID_carState = AVOID_CAR_SET_DEFAULT_ROTATION;
	float64_t objectDistance = 0.0;
	ENU_avoidCarDefaultRotation_t carDefaultRotation = AVOID_CAR_ROTATION_RIGHT;
	Uint8_t rotationDirectionErrorFlag = 0;
	uint8_t obstcalesInAllDirection = 0;
	Uint8_t exitFlag = 0;
	while(1)
	{	
		if(exitFlag == 1) break;
		switch(AVOID_carState)
		{
			case AVOID_CAR_SET_DEFAULT_ROTATION :
			{
				if(rotationDirectionErrorFlag == 0)
				{
					BLUETOOTH_send((Uint8_t *)"Now You Are In The Avoid Obstacles Mode\r\n");
					BLUETOOTH_send((Uint8_t *)"Please Choose Car Default Direction In Rotation\r\n");
					BLUETOOTH_send((Uint8_t *)"0 - Right\r\n");
					BLUETOOTH_send((Uint8_t *)"1 - Left\r\n");
					BLUETOOTH_send((Uint8_t *)"\r\n");
					carDefaultRotation = BLUETOOTH_ReceiveData();
					carDefaultRotation -= '0';
					BLUETOOTH_vSendData(carDefaultRotation);
					
					if((carDefaultRotation == AVOID_CAR_ROTATION_RIGHT) || (carDefaultRotation == AVOID_CAR_ROTATION_LEFT))
					{
						rotationDirectionErrorFlag = 0;
						AVOID_carState = AVOID_CAR_STATE_SCANNING_OBJECT;
					}
					else
					{
						rotationDirectionErrorFlag = 1;
						AVOID_carState = AVOID_CAR_SET_DEFAULT_ROTATION;
					}
				}
				else if(rotationDirectionErrorFlag == 1)
				{
					BLUETOOTH_send((Uint8_t *)"Invalid Choice Please Try Again\r\n");
					BLUETOOTH_send((Uint8_t *)"Please Choose Car Default Direction In Rotation\r\n");
					BLUETOOTH_send((Uint8_t *)"0 - Right\r\n");
					BLUETOOTH_send((Uint8_t *)"1 - Left\r\n");
					BLUETOOTH_send((Uint8_t *)"\r\n");
					carDefaultRotation = BLUETOOTH_ReceiveData();
					carDefaultRotation -= '0';
					BLUETOOTH_vSendData(carDefaultRotation);		
					if((carDefaultRotation == AVOID_CAR_ROTATION_RIGHT) || (carDefaultRotation == AVOID_CAR_ROTATION_LEFT))
					{
						rotationDirectionErrorFlag = 0;
						AVOID_carState = AVOID_CAR_STATE_SCANNING_OBJECT;						
					}
					else
					{
						rotationDirectionErrorFlag = 1;
						AVOID_carState = AVOID_CAR_SET_DEFAULT_ROTATION;
					}							
				}		
				break;
			}
			case AVOID_CAR_STATE_SCANNING_OBJECT :
			{
				HCSR04_vGet_Reading(&objectDistance);
				_delay_ms(30);
				AVOID_carState = AVOID_CAR_CHECK_OBJECT_DISTANCE;
				break;
			}
			case AVOID_CAR_CHECK_OBJECT_DISTANCE :
			{
				if(objectDistance >= 50)
				{
					AVOID_carState = AVOID_CAR_DISTANCE_IN_SAFE;
				}
				else if(objectDistance <= 49)
				{
					AVOID_carState = AVOID_CAR_DISTANCE_IN_UNSAFE;
				}
				else
				{
					/* Do Nothing */
				}
				break;
			}
			case AVOID_CAR_DISTANCE_IN_SAFE :
			{
				DCM_changeDirection(&dcmCfgArr[0] , DCM_DIR_FORWARD);
				DCM_changeDirection(&dcmCfgArr[1] , DCM_DIR_FORWARD);
				DCM_changeDirection(&dcmCfgArr[2] , DCM_DIR_FORWARD);
				DCM_changeDirection(&dcmCfgArr[3] , DCM_DIR_FORWARD);
				DCM_turnOn(&dcmCfgArr[0]);
				DCM_turnOn(&dcmCfgArr[1]);
				DCM_turnOn(&dcmCfgArr[2]);
				DCM_turnOn(&dcmCfgArr[3]);
				AVOID_carState = AVOID_CAR_STATE_SCANNING_OBJECT;
				break;
			}
			case AVOID_CAR_DISTANCE_IN_UNSAFE :
			{
				/* Stop Car */
					/* rotate car to default direction */
				if(obstcalesInAllDirection < 4)
				{
					obstcalesInAllDirection++;
					if(carDefaultRotation == AVOID_CAR_ROTATION_RIGHT)
					{
						DCM_changeDirection(&dcmCfgArr[0] , DCM_DIR_FORWARD);
						DCM_changeDirection(&dcmCfgArr[1] , DCM_DIR_FORWARD);
						DCM_turnOn(&dcmCfgArr[0]);
						DCM_turnOn(&dcmCfgArr[1]);
						DCM_turnOff(&dcmCfgArr[2]);
						DCM_turnOff(&dcmCfgArr[3]);
						_delay_ms(1000);
						AVOID_carState = AVOID_CAR_STATE_SCANNING_OBJECT;

					}
					else if(carDefaultRotation == AVOID_CAR_ROTATION_LEFT)
					{
						DCM_changeDirection(&dcmCfgArr[2] , DCM_DIR_FORWARD);
						DCM_changeDirection(&dcmCfgArr[3] , DCM_DIR_FORWARD);
						DCM_turnOn(&dcmCfgArr[2]);
						DCM_turnOn(&dcmCfgArr[3]);
						DCM_turnOff(&dcmCfgArr[0]);
						DCM_turnOff(&dcmCfgArr[1]);
						_delay_ms(1000);
						AVOID_carState = AVOID_CAR_STATE_SCANNING_OBJECT;
					}
					else
					{
						/* Do Nothing */
					}
				}
				else
				{
					AVOID_carState = AVOID_CAR_EXIT;
				}
					break;
			}
			case AVOID_CAR_EXIT :
			{
				DCM_turnOff(&dcmCfgArr[0]);
				DCM_turnOff(&dcmCfgArr[1]);
				DCM_turnOff(&dcmCfgArr[2]);
				DCM_turnOff(&dcmCfgArr[3]);
				BLUETOOTH_send((Uint8_t *)"NO Possible Path For The Robot Exit.....\r\n");
				exitFlag = 1;
				break;
			}
			default :
			{
				/* Do Nothing */
				break;
			}
		}
	  }
	return AVOID_OK;
 }

