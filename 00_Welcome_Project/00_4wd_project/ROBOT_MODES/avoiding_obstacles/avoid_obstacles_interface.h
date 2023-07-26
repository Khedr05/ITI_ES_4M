/*
 * avoid_obstacles_interface.h
 *
 * Created: 12/07/2023 22:43:42
 *  Author: 20101
 */ 


#ifndef AVOID_OBSTACLES_INTERFACE_H_
#define AVOID_OBSTACLES_INTERFACE_H_

#include "avoid_obstacles_cfg.h"
#include "../../APPLICATION/app.h"




ENU_avoidSystemState_t AVOID_OBSTACLES_INTERFACE(void);

ENU_avoidSystemState_t AVOID_objectScanning(float64_t *objectDistance);

ENU_avoidSystemState_t AVOID_autoSuddenBreak(void);


#endif /* AVOID_OBSTACLES_INTERFACE_H_ */
