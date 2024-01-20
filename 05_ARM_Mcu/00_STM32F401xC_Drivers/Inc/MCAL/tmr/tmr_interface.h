/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : tmr_interface.h                                  	     
// Date          : Oct 14, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_TMR_TMR_INTERFACE_H_
#define MCAL_TMR_TMR_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "tmr_private.h"
#include "tmr_config.h"


void 	 MTMR_vStartTimer(EN_MTMR_number_t copy_uddtTMRNumber);
void 	 MTMR_vStopTimer(EN_MTMR_number_t copy_uddtTMRNumber);
void 	 MTMR_vSetTimerPrescaler(EN_MTMR_number_t copy_uddtTMRNumber, uint16_t copy_u16Value);
void 	 MTMR_vEnableTimerOPM(EN_MTMR_number_t copy_uddtTMRNumber);
void 	 MTMR_vTimerCountRst(EN_MTMR_number_t copy_uddtTMRNumber);
void 	 MTMR_vSetTimerChannelOutput(EN_MTMR_number_t copy_uddtTMRNumber, EN_MTMR_selectedMode_t copy_uddtTimerMode, EN_MTMR_channel_t copy_uddtChannelNumber);
void 	 MTMR_vSetTimerChannelInput(EN_MTMR_number_t copy_uddtTMRNumber, EN_MTMR_channel_t copy_uddtChannelNumber);
void 	 MTMR_vSetTimerARR(EN_MTMR_number_t copy_uddtTMRNumber, uint32_t copy_u32Value);
void 	 MTMR_vSetTimerStop(EN_MTMR_number_t copy_uddtTMRNumber);
void 	 MTMR_vClearTimerCount(EN_MTMR_number_t copy_uddtTMRNumber);
void 	 MTMR_vEnableTimerICUInt(EN_MTMR_number_t copy_uddtTMRNumber);
void 	 MTMR_vSetTimerCMPVal(EN_MTMR_number_t copy_uddtTMRNumber, EN_MTMR_channel_t copy_uddtChannelNumber, uint32_t copy_u32CmpValue);
uint32_t MTMR_vReadCaptureVal(EN_MTMR_number_t copy_uddtTMRNumber, EN_MTMR_channel_t copy_uddtChannelNumber);
void 	 MTMR3_vCaptureCompareInit(void);

void HLIDAR_controlSpeed(uint8_t copy_u8Speed);


#endif /* MCAL_TMR_TMR_INTERFACE_H_ */
