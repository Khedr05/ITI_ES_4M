/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : ledMatrix_prog.c                                  	     
// Date          : Sep 13, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/HAL/ledMatrix/ledMatrix_interface.h"


EN_HLDM_systemState_t HLDM_init(ST_HLDM_cfg_t const *copy_uddtPsOfLdm)
{
    for (uint8_t i = 0; i <= 7; i++) {
    	// Configure ROW pins as outputs
        MGPIO_setPinMode(copy_uddtPsOfLdm->copy_uddtLdmRowPort, copy_uddtPsOfLdm->copy_uddtLdmRowPins[i], MGPIO_MODE_OUTPUT);
        MGPIO_setOutputMode(copy_uddtPsOfLdm->copy_uddtLdmRowPort, copy_uddtPsOfLdm->copy_uddtLdmRowPins[i], MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
        MGPIO_setOutputSpeed(copy_uddtPsOfLdm->copy_uddtLdmRowPort, copy_uddtPsOfLdm->copy_uddtLdmRowPins[i], MGPIO_OUTPUT_SPEED_HIGH);
        // Configure COL pins as outputs
        MGPIO_setPinMode(copy_uddtPsOfLdm->copy_uddtLdmColPort,copy_uddtPsOfLdm->copy_uddtLdmColPins[i], MGPIO_MODE_OUTPUT);
        MGPIO_setOutputMode(copy_uddtPsOfLdm->copy_uddtLdmColPort,copy_uddtPsOfLdm->copy_uddtLdmColPins[i], MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
        MGPIO_setOutputSpeed(copy_uddtPsOfLdm->copy_uddtLdmColPort,copy_uddtPsOfLdm->copy_uddtLdmColPins[i], MGPIO_OUTPUT_SPEED_HIGH);
    }
}

EN_HLDM_systemState_t HLDM_enable(ST_HLDM_cfg_t const *copy_uddtPsOfLdm , uint16_t *copy_u8ArrOfMatrix)
{

    for (uint8_t col = 0; col <= 7; col++) {

        // Enable the current column (cathode) to activate LEDs
        MGPIO_setPinVal(copy_uddtPsOfLdm->copy_uddtLdmColPort, copy_uddtPsOfLdm->copy_uddtLdmColPins[col], MGPIO_LOGIC_LOW);

        // Set the row (anode) pins based on the matrix pattern
        MGPIO_setPortVal(copy_uddtPsOfLdm->copy_uddtLdmRowPort, copy_u8ArrOfMatrix[col]);

        // Delay to display for a short duration (adjust as needed)
        MSTK_setBusyWait(1000);

        // Disable the current column (cathode) to turn off LEDs
       MGPIO_setPinVal(copy_uddtPsOfLdm->copy_uddtLdmColPort,copy_uddtPsOfLdm->copy_uddtLdmColPins[col], MGPIO_LOGIC_HIGH);
       MGPIO_setPortVal(copy_uddtPsOfLdm->copy_uddtLdmRowPort, 0x0000);


    }
}

