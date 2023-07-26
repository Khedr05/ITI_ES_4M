/*
 * mobileControllerInterface.h
 *
 * Created: 08/07/2023 21:46:40
 *  Author: 20101
 */ 


#ifndef MOBILECONTROLLERINTERFACE_H_
#define MOBILECONTROLLERINTERFACE_H_

#include "../../APPLICATION/app.h"
#include "mobileControllerCfg.h"


void mobileControllerModeInterface(void);

void carGoToForward(void);
void carGoToReverse(void);
void carGoToRotateLeft(void);
void carGoToRotateRight(void);
void carGoToStop(void);

#endif /* MOBILECONTROLLERINTERFACE_H_ */
