/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : fdi_prog.c                                  	     
// Date          : Sep 27, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/MCAL/fdi/fdi_interface.h"


EN_MFDI_systeamState_t MFDI_uddtEraseSector(uint8_t copy_u8SectorNumber)
{
	EN_MFDI_systeamState_t ret = MFDI_NOK;

	if((copy_u8SectorNumber != 0) && (copy_u8SectorNumber <= 7))
	{
		// wait if busy bit is set
		while (GET_BIT(ST_MFDI_RegistersMap_t->MFDI_FLASH_SR , 16)==1);
		// check if Authorized for configurations
		if (GET_BIT(ST_MFDI_RegistersMap_t->MFDI_FLASH_CR , 31 )==1)
		{
			//Lock Sequence
			ST_MFDI_RegistersMap_t->MFDI_FLASH_KEYR = MFDI_FLASH_KEYR_KEY_1;
			ST_MFDI_RegistersMap_t->MFDI_FLASH_KEYR = MFDI_FLASH_KEYR_KEY_2;
		}

		// Selecting the sector to erase
		ST_MFDI_RegistersMap_t->MFDI_FLASH_CR &= 0xFFFFFF87;  // Clearing the Selection bits [bit3 to bit 5]
		ST_MFDI_RegistersMap_t->MFDI_FLASH_CR |= copy_u8SectorNumber<<3; // Selecting the sector

		// Activate Sector erase
		SET_BIT(ST_MFDI_RegistersMap_t->MFDI_FLASH_CR,1);

		// Set Start bit
		SET_BIT(ST_MFDI_RegistersMap_t->MFDI_FLASH_CR,16);

		// wait until erasing is finished
		while (GET_BIT(ST_MFDI_RegistersMap_t->MFDI_FLASH_SR , 16)==1);

		// Clear the EOP flag
		SET_BIT(ST_MFDI_RegistersMap_t->MFDI_FLASH_SR,0);

		// Deactivate the Sector erase
		CLR_BIT(ST_MFDI_RegistersMap_t->MFDI_FLASH_CR,1);

		ret = MFDI_OK;
	}
	else
	{
		ret = MFDI_INVALID_PARAMTER;
	}

	return ret;
}
EN_MFDI_systeamState_t MFDI_uddtFlashWrite(uint32_t copy_u32Address , uint16_t *copy_u16PtrData , uint8_t copy_u8DataLength)
{
	EN_MFDI_systeamState_t ret = MFDI_NOK;

	if(PTR_NULL != copy_u16PtrData)
	{
		// wait if busy bit is set
		while (GET_BIT(ST_MFDI_RegistersMap_t->MFDI_FLASH_SR , 16)==1);

		// check if Authorized for configurations
		if (GET_BIT(ST_MFDI_RegistersMap_t->MFDI_FLASH_CR , 31 )==1)
		{
			//Lock Sequence
			ST_MFDI_RegistersMap_t->MFDI_FLASH_KEYR = MFDI_FLASH_KEYR_KEY_1;
			ST_MFDI_RegistersMap_t->MFDI_FLASH_KEYR = MFDI_FLASH_KEYR_KEY_2;
		}

		ST_MFDI_RegistersMap_t->MFDI_FLASH_CR &= 0xFFFFFCFF;
		ST_MFDI_RegistersMap_t->MFDI_FLASH_CR |= WRITE_HALF_WORD << 8 ;

		for (uint8_t L_u8Iterator =0 ; L_u8Iterator < copy_u8DataLength ; L_u8Iterator ++ )
		{
			// Activate Programming Flash
			SET_BIT(ST_MFDI_RegistersMap_t->MFDI_FLASH_CR,0);

			*((vuint16_t*)copy_u32Address)= copy_u16PtrData[L_u8Iterator];
			copy_u32Address += 2;

			// wait if busy bit is set
			while (GET_BIT(ST_MFDI_RegistersMap_t->MFDI_FLASH_SR , 16)==1);
			// Clear the EOP flag
		    SET_BIT(ST_MFDI_RegistersMap_t->MFDI_FLASH_SR,0);
			// deactivate Programming Flash
			CLR_BIT(ST_MFDI_RegistersMap_t->MFDI_FLASH_CR,0);
		}

		ret = MFDI_OK;
	}
	else
	{
		ret = MFDI_INVALID_PARAMTER;
	}

	return ret;
}
EN_MFDI_systeamState_t MFDI_uddtEraseAppArea(void)
{
	EN_MFDI_systeamState_t ret = MFDI_NOK;

	uint8_t L_u8Iterator;

	for (L_u8Iterator=1 ; L_u8Iterator < 6 ; L_u8Iterator ++)
	{
		ret = MFDI_uddtEraseSector(L_u8Iterator);
		if(ret != MFDI_OK)
			break;
	}
	return ret;
}
