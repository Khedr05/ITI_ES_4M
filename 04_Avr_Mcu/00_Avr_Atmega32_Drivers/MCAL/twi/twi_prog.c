/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : twi_prog.c                                  	     
// Date          : 22 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "twi_interface.h"

#define F_CPU	8000000UL
#define SCL_CLOCK	100000L

EN_MTWI_systemState_t MTWI_init(ST_MTWI_cfg_t const * ST_ptrMtwiCfgInstance)
{
	EN_MTWI_systemState_t twiRet = MTWI_NOK;

	if(PTR_NULL != ST_ptrMtwiCfgInstance)
	{
		TWSR_REG = ((TWSR_REG & 0xFC ) | ST_ptrMtwiCfgInstance->prescalerSelection << TWPS0_BIT);
		TWAR_REG = ST_ptrMtwiCfgInstance->deviceAddress;
		TWBR_REG = ((F_CPU/SCL_CLOCK)-16)/2;

		twiRet = MTWI_OK;
	}
	else
	{
		twiRet = MTWI_PTR_NULL;
	}
	return twiRet;
}


EN_MTWI_systemState_t MTWI_enable(void)
{
	EN_MTWI_systemState_t twiRet = MTWI_NOK;

	TWCR_REG = ((TWCR_REG & 0xFB ) | MTWI_ENABLE << TWEN_BIT);

	twiRet = MTWI_OK;
	return twiRet;
}
EN_MTWI_systemState_t MTWI_disable(void)
{
	EN_MTWI_systemState_t twiRet = MTWI_NOK;

	TWCR_REG = ((TWCR_REG & 0xFB ) | MTWI_DISABLE << TWEN_BIT);

	twiRet = MTWI_OK;
	return twiRet;
}

EN_MTWI_systemState_t MTWI_start(void)
{
	EN_MTWI_systemState_t twiRet = MTWI_NOK;

	SET_BIT(TWCR_REG,TWINT_BIT);
	SET_BIT(TWCR_REG,TWSTA_BIT);
	TWCR_REG = ((TWCR_REG & 0xFB ) | MTWI_ENABLE << TWEN_BIT);
	while(!GET_BIT(TWCR_REG,TWINT_BIT));

	twiRet = MTWI_OK;
	return twiRet;
}
EN_MTWI_systemState_t MTWI_stop(void)
{
	EN_MTWI_systemState_t twiRet = MTWI_NOK;

	SET_BIT(TWCR_REG,TWINT_BIT);
	SET_BIT(TWCR_REG,TWSTO_BIT);
	TWCR_REG = ((TWCR_REG & 0xFB ) | MTWI_ENABLE << TWEN_BIT);
	while(!GET_BIT(TWCR_REG,TWINT_BIT));

	twiRet = MTWI_OK;
	return twiRet;

}
EN_MTWI_systemState_t MTWI_writedata(uint8_t dataToWrite)
{
	EN_MTWI_systemState_t twiRet = MTWI_NOK;

	TWDR_REG = dataToWrite;
	SET_BIT(TWCR_REG,TWINT_BIT);
	SET_BIT(TWCR_REG,TWEA_BIT);
	TWCR_REG = ((TWCR_REG & 0xFB ) | MTWI_ENABLE << TWEN_BIT);
	while(!GET_BIT(TWCR_REG,TWINT_BIT));

	twiRet = MTWI_OK;
	return twiRet;
}
EN_MTWI_systemState_t MTWI_readDataWithAck(uint8_t *retOfData)
{
	EN_MTWI_systemState_t twiRet = MTWI_NOK;

	while(!GET_BIT(TWCR_REG,TWINT_BIT));
	//SET_BIT(TWCR_REG,TWINT_BIT);
	SET_BIT(TWCR_REG,TWEA_BIT);
	TWCR_REG = ((TWCR_REG & 0xFB ) | MTWI_ENABLE << TWEN_BIT);
	while(!GET_BIT(TWCR_REG,TWINT_BIT));

	//TWDR_REG &= 0xF8;

	*retOfData = TWDR_REG;

	twiRet = MTWI_OK;
	return twiRet;
}
EN_MTWI_systemState_t MTWI_readDataWithNotAck(uint8_t *retOfData)
{
	EN_MTWI_systemState_t twiRet = MTWI_NOK;

	while(!GET_BIT(TWCR_REG,TWINT_BIT));
	CLR_BIT(TWCR_REG,TWEA_BIT);

	TWCR_REG = ((TWCR_REG & 0xFB ) | MTWI_ENABLE << TWEN_BIT);
	//SET_BIT(TWCR_REG,TWINT_BIT);

	while(!GET_BIT(TWCR_REG,TWINT_BIT));

	//TWDR_REG &= 0xF8;
	*retOfData = TWDR_REG;

	twiRet = MTWI_OK;
	return twiRet;
}
EN_MTWI_systemState_t MTWI_getStatus(uint8_t *retOfStates)
{
	EN_MTWI_systemState_t twiRet = MTWI_NOK;

	//TWCR_REG = ((TWCR_REG & 0xFB ) | MTWI_ENABLE << TWEN_BIT);
	*retOfStates = TWSR_REG;

	twiRet = MTWI_OK;
	return twiRet;
}
