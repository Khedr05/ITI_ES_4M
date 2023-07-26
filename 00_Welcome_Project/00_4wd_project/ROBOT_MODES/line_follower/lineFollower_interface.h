/*
 * lineFollower_interface.h
 *
 * Created: 19/07/2023 22:03:40
 *  Author: 20101
 */ 


#ifndef LINEFOLLOWER_INTERFACE_H_
#define LINEFOLLOWER_INTERFACE_H_

#include "../../APPLICATION/app.h"
#include "lineFollower_cfg.h"

void lineFollowerInterface(void);
void lineFollowerCarGoToForward(void);
void lineFollowerCarGoToRotateLeft(void);
void lineFollowerCarGoToRotateRight(void);
void lineFollowerCarGoToStop(void);


#endif /* LINEFOLLOWER_INTERFACE_H_ */