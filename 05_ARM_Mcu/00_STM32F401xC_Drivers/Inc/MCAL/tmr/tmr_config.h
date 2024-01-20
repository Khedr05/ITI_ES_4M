/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : tmr_config.h                                  	     
// Date          : Oct 14, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_TMR_TMR_CONFIG_H_
#define MCAL_TMR_TMR_CONFIG_H_


typedef enum
{
	MTMR2 = 0,
	MTMR3,
	MTMR4,
	MTMR5
}EN_MTMR_number_t;

typedef enum
{
	MTMR_CH1 = 1,
	MTMR_CH2,
	MTMR_CH3,
	MTMR_CH4
}EN_MTMR_channel_t;

typedef enum
{
	MTMR_MODE_FROZEN = 0,
	MTMR_MODE_ACTIVE,
	MTMR_MODE_INACTIVE,
	MTMR_MODE_TOGGLE,
	MTMR_MODE_INACTIVE_FORCE,
	MTMR_MODE_ACTIVE_FORCE,
	MTMR_MODE_PWM_MODE1,
	MTMR_MODE_PWM_MODE2
}EN_MTMR_selectedMode_t;

typedef enum
{
	OUTPUT,
	IC_T2,
	IC_T1,
	IC_TRC
}CH_MODE_t;

typedef enum
{
	RISIN,
	FALLIN,
	RESERVED,
	BOTH
}EDGE_t;
#endif /* MCAL_TMR_TMR_CONFIG_H_ */
