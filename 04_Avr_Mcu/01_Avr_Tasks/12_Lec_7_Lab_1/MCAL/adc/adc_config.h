/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : adc_config.h                                  	     
// Date          : 15 Aug 2023	                                                                                                 */
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_


typedef enum
{
	MADC_OK = 0,						/** MADC_OK   				: Will Return When Everything In Function Is Ok		 	 **/
	MADC_NOK,							/** MADC_NOK  				: Will Return When Anything   In Function Is NOk		 **/
	MADC_PTR_NULL,						/** MADC_PTR_NULL   		: Will Return When Pass To The Function Null Pointer	 **/
	MADC_INVALID_PARAMTERS				/** MADC_INVLID_PARAMTERS   : Will Return When Pass To The Function Null Pointer	 **/
}EN_MADC_systeamState_t;




typedef enum
{
	MADC_AREF_INTERNAL = 0, 						/** AREF, Internal Vref turned off = 0  								 	 **/
	MADC_AVCC_EXTERNAL_CAPACITOR,					/** AVCC with external capacitor at AREF pin = 1						 	 **/
	MADC_RESERVED,									/**  Reserved = 2                               						 	 **/
	MADC_INTERNAL_VOLTAGE_EXTERNAL_CAPACITOR		/** Internal 2.56V Voltage Reference with external capacitor at AREF pin = 3 **/
}EN_MADC_reffSelect_t;

typedef enum
{
	MADC_RIGHT_ADJUST = 0,  					 	/**  ADC Left Adjust Result = 0  										**/
	MADC_LEFT_ADJUST		 						/**  ADC Left Adjust Result = 1  										**/
}EN_MADC_AdjustResualt_t;


typedef enum
{
	MADC_CHANNEL_ZERO = 0,							/**  Analog Channel ADC0 = 0   								            **/
	MADC_CHANNEL_ONE,								/**  Analog Channel ADC1 = 1  								            **/
	MADC_CHANNEL_TWO,								/**  Analog Channel ADC2 = 2   								            **/
	MADC_CHANNEL_THREE,								/**  Analog Channel ADC3 = 3   								            **/
	MADC_CHANNEL_FOUR,								/**  Analog Channel ADC4 = 4   								            **/
	MADC_CHANNEL_FIVE,								/**  Analog Channel ADC5 = 5   								            **/
	MADC_CHANNEL_SIX,								/**  Analog Channel ADC6 = 6   								            **/
	MADC_CHANNEL_SEVEN								/**  Analog Channel ADC7 = 7   								            **/
}EN_MADC_ChannelSelection_t;


typedef enum
{
	MADC_DIV2 = 1,									/** ADC Prescaler Division Factor 2   =  1							    **/
	MADC_DIV4,										/** ADC Prescaler Division Factor 4   =  2								**/
	MADC_DIV8,										/** ADC Prescaler Division Factor 8   =  3								**/
	MADC_DIV16,										/** ADC Prescaler Division Factor 16  =  4								**/
	MADC_DIV32, 									/** ADC Prescaler Division Factor 32  =  5								**/
	MADC_DIV64,										/** ADC Prescaler Division Factor 64  =  6								**/
	MADC_DIV128										/** ADC Prescaler Division Factor 128 =  7								**/
}EN_MADC_PrescalerSelection_t;


typedef enum
{
	MADC_POLLING_ON_FLAG = 0,								/** ADC Interrupt Enabled 												**/
	MADC_INTERRUPT ,										/** ADC Interrupt Disabled 												**/
}EN_MADC_tiggerSource_t;

typedef struct
{
	void(*MADC_setCallback)(void);
	EN_MADC_reffSelect_t 			referenceSource;
	EN_MADC_AdjustResualt_t 		resultAdjust;
	EN_MADC_ChannelSelection_t		channelSelection;
	EN_MADC_PrescalerSelection_t 	prescalerDivision;
	EN_MADC_tiggerSource_t 			triggerSource;
}ST_MADC_CFG_t;


#endif /* MCAL_ADC_ADC_CONFIG_H_ */
