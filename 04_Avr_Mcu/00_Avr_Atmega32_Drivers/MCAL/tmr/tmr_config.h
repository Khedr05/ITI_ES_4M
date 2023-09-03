/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : tmr_config.h                                  	     
// Date          : 17 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_TMR_TMR_CONFIG_H_
#define MCAL_TMR_TMR_CONFIG_H_


typedef enum
{
	MTMR_OK = 0,
	MTMR_NOK,
	MTMR_PTR_NULL,
	MTMR_INVALID_PARAMTER
}EN_MTMR_systemState_t;

typedef enum
{
	MTMR_TMR0_NORMAL_MODE = 0,
	MTMR_TMR0_PWM_PHASE_CORRECT_MODE,
	MTMR_TMR0_CTC_MODE,
	MTMR_TMR0_FAST_PWM_MODE,
	MTMR_TMR1_NORMAL_MODE = 0,
	MTMR_TMR1_PWM_PHASE_CORRECT_MODE_8_BIT_MODE,
	MTMR_TMR1_PWM_PHASE_CORRECT_MODE_9_BIT_MODE,
	MTMR_TMR1_PWM_PHASE_CORRECT_MODE_10_BIT_MODE,
	MTMR_TMR1_CTC_OCR_MODE,
	MTMR_TMR1_FAST_PWM_8_BIT_MODE,
	MTMR_TMR1_FAST_PWM_9_BIT_MODE,
	MTMR_TMR1_FAST_PWM_10_BIT_MODE,
	MTMR_TMR1_PWM_PHASE_FREQ_CORRECT_ICR_TOP_MODE,
	MTMR_TMR1_PWM_PHASE_FREQ_CORRECT_OCR_TOP_MODE,
	MTMR_TMR1_CTC_ICR_MODE,
	MTMR_TMR1_RESERVED,
	MTMR_TMR1_FAST_PWM_ICR_MODE,
	MTMR_TMR1_FAST_PWM_OCR_MODE = 15,
	MTMR_TMR2_NORMAL_MODE = 0

}EN_MTMR_genrationMode_t;


typedef enum
{
	MTMR_OC_DISCONNECTED = 0,
	MTMR_OC_TOGGLE ,
	MTMR_OC_CLEAR,
	MTMR_OC_SET
}EN_MTMR_ocAction_t;


typedef enum
{
	MTMR_NO_CLK_PRESCALER = 0,
	MTMR_NO_PRESCALER,
	MTMR_8_PRESCALER,
	MTMR_64_PRESCALER,
	MTMR_256_PRESCALER,
	MTMR_1024_PRESCALER,
	MTMR_EXTERNAL_CLK_ON_FALLING_EDGE_PRESCALER,
	MTMR_EXTERNAL_CLK_ON_RAISING_EDGE_PRESCALER
}EN_MTMR_clkSelection;

typedef enum
{
	MTMR_INTERRUPT_DISABLED = 0,
	MTMR_TMR0_OVF_INTERRUPT_ENABLE,
	MTMR_TMR0_OC_INTERRUPT_ENABLE,
	MTMR_TMR1_OVF_INTERRUPT_ENABLE = 1,
	MTMR_TMR1_OC_CHANNELB_INTERRUPT_ENABLE,
	MTMR_TMR1_OC_CHANNELA_INTERRUPT_ENABLE = 4,
	MTMR_TMR1_ICU_INTERRUPT_ENABLE = 8,
	MTMR_TMR2_OVF_INTERRUPT_ENABLE = 1,
	MTMR_TMR2_OC_INTERRUPT_ENABLE

}EN_MTMR_interruptStates_t;

typedef enum
{
	MTMR_TIMER_0_Channel = 0,
	MTMR_TIMER_1_Channel,
	MTMR_TIMER_2_Channel,
}EN_MTMR_timerChannel_t;


typedef struct
{

	EN_MTMR_timerChannel_t		timerChannel;
	EN_MTMR_genrationMode_t		timerMode;
	EN_MTMR_ocAction_t			timerOcAAction;
	EN_MTMR_ocAction_t			timerOcBAction;
	EN_MTMR_clkSelection		timerClk;
	EN_MTMR_interruptStates_t 	timerInterruptStates;
	void(*MTMR_setCallbackForOvf)(void);
	void(*MTMR_setCallbackForOcChannelA)(void);
	void(*MTMR_setCallbackForOcChannelB)(void);
	void(*MTMR_setCallbackForIcu)(void);

}ST_MTMR_cfg_t;

#endif /* MCAL_TMR_TMR_CONFIG_H_ */
