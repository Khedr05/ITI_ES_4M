/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : hexParsing_prog.c                                  	     
// Date          : Sep 28, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/HAL/hex parsing/hexParsing_interface.h"

#define FLASH_ADDR  0x08000000


uint8_t HEX_parsAsciiToHex(uint8_t ascii)
{
	uint8_t hex_val = 0;

	if(ascii >= '0' && ascii<= '9')
	{
		hex_val = ascii - '0';
	}
	else if(ascii >= 'A' && ascii<= 'F')
	{
		hex_val = ascii - 55;
	}

	return hex_val;
}

void HEX_parsData(uint8_t *data)
{
	uint8_t ccHigh,ccLow, cc;
	uint8_t digit0 ,digit1 ,digit2 ,digit3;
	uint32_t address;
	uint16_t dataVal[100];

	ccHigh = HEX_parsAsciiToHex(data[1]);
	ccLow = HEX_parsAsciiToHex(data[2]);

	cc = (ccHigh << 4) | ccLow;

	digit0 = HEX_parsAsciiToHex(data[3]);
	digit1 = HEX_parsAsciiToHex(data[4]);
	digit2 = HEX_parsAsciiToHex(data[5]);
	digit3 = HEX_parsAsciiToHex(data[6]);

	address = ((FLASH_ADDR) | (digit0 << 12) | (digit1 << 8) |(digit2 << 4) | (digit3 << 0));

	for(uint8_t i=0;i< cc/2;i++)
	{
		digit0 = HEX_parsAsciiToHex(data[(4*i) + 9]);
		digit1 = HEX_parsAsciiToHex(data[(4*i) + 10]);
		digit2 = HEX_parsAsciiToHex(data[(4*i) + 11]);
		digit3 = HEX_parsAsciiToHex(data[(4*i) + 12]);

		dataVal[i]  = ((digit2 << 12) | (digit3 << 8) | (digit0 << 4) | (digit1));
	}

	MFDI_uddtFlashWrite(address,dataVal,cc/2);

}


void APARSER_voidParseRecord(uint8_t *BufRecord)
{
	switch(BufRecord[8])
	{
		case '0' : HEX_parsData(BufRecord); break;
		case '4' : /* set high addr */ break;
		case '1' : /* end of file */ break;
	}
}








