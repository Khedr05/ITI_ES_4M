/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : tft_prog.c                                  	     
// Date          : Sep 20, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/HAL/tft/tft_interface.h"


EN_HTFT_systeamState_t HTFT_uddtInit(ST_HTFT_cfg_t const *PS_uddtTftCfg)
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{
		ST_MSPI_cfg_t spi =
		{
				.cphaSelect = MSPI_CLK_TO_ONE,
				.cpolSelect = MSPI_SECOND_CLK_FIRST_DATA_EDGE,
				.deviceRole = MSPI_DEVICE_ROLE_MASTER,
				.buadRate = MSPI_CLK_DIVSION_2,
				.statusOfSpi = MSPI_ENABLE,
				.frameFormatSelection = MSPI_FRAME_MSB,
				.ssmSelect = MSPI_SSM_ENABLED,
				.ssiSelect = MSPI_SSI_IS_SET,
				.dataFrameFormatSelection = MSPI_DFF_8_BIT
		};

		MSPI_uddtInit(&spi);
		MGPIO_setPinMode(PS_uddtTftCfg->a0Port, PS_uddtTftCfg->a0Pin, MGPIO_MODE_OUTPUT);
		MGPIO_setOutputMode(PS_uddtTftCfg->a0Port, PS_uddtTftCfg->a0Pin, MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
		MGPIO_setOutputSpeed(PS_uddtTftCfg->a0Port, PS_uddtTftCfg->a0Pin, MGPIO_OUTPUT_SPEED_HIGH);

		MGPIO_setPinMode(PS_uddtTftCfg->rstPort, PS_uddtTftCfg->rstPin, MGPIO_MODE_OUTPUT);
		MGPIO_setOutputMode(PS_uddtTftCfg->rstPort, PS_uddtTftCfg->rstPin, MGPIO_OUTPUT_RESISTOR_PUSH_PULL);
		MGPIO_setOutputSpeed(PS_uddtTftCfg->rstPort, PS_uddtTftCfg->rstPin, MGPIO_OUTPUT_SPEED_HIGH);

		HTFT_uddtReset(PS_uddtTftCfg);
		HTFT_uddtWriteCommand(PS_uddtTftCfg , HTFT_COMMAND_SLEEP_OUT);
		MSTK_setBusyWait(1);
		HTFT_uddtWriteCommand(PS_uddtTftCfg , HTFT_COMMAND_COLOR_MODE);
		HTFT_uddtWriteData(PS_uddtTftCfg, HTFT_COMMAND_PARAMTER_RGB_565);
		HTFT_uddtWriteCommand(PS_uddtTftCfg , HTFT_COMMAND_DISPLAY_ON);


		ret = HTFT_OK;
	}
	else
	{
		ret = HTFT_PTR_NULL;
	}
	return ret;
}

EN_HTFT_systeamState_t HTFT_uddtWriteCommand(ST_HTFT_cfg_t const *PS_uddtTftCfg ,uint8_t copy_u8CommandToSend)
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{
		MGPIO_setPinVal(PS_uddtTftCfg->a0Port,PS_uddtTftCfg->a0Pin,MGPIO_LOGIC_LOW);
		MSPI_uddtSendBlocking(copy_u8CommandToSend);
		ret = HTFT_OK;
	}
	else
	{
		ret = HTFT_PTR_NULL;
	}
	return ret;
}

EN_HTFT_systeamState_t HTFT_uddtWriteData(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint8_t copy_u8DataToSend)
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{
		MGPIO_setPinVal(PS_uddtTftCfg->a0Port,PS_uddtTftCfg->a0Pin,MGPIO_LOGIC_HIGH);
		MSPI_uddtSendBlocking(copy_u8DataToSend);
		ret = HTFT_OK;
	}
	else
	{
		ret = HTFT_PTR_NULL;
	}
	return ret;
}

EN_HTFT_systeamState_t HTFT_uddtReset(ST_HTFT_cfg_t const *PS_uddtTftCfg)
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{
		MGPIO_setPinVal(PS_uddtTftCfg->rstPort,PS_uddtTftCfg->rstPin,MGPIO_LOGIC_HIGH);
		MSTK_setBusyWait(100);
		MGPIO_setPinVal(PS_uddtTftCfg->rstPort,PS_uddtTftCfg->rstPin,MGPIO_LOGIC_LOW);
		MSTK_setBusyWait(1);
		MGPIO_setPinVal(PS_uddtTftCfg->rstPort,PS_uddtTftCfg->rstPin,MGPIO_LOGIC_HIGH);
		MSTK_setBusyWait(100);
		MGPIO_setPinVal(PS_uddtTftCfg->rstPort,PS_uddtTftCfg->rstPin,MGPIO_LOGIC_LOW);
		MSTK_setBusyWait(100);
		MGPIO_setPinVal(PS_uddtTftCfg->rstPort,PS_uddtTftCfg->rstPin,MGPIO_LOGIC_HIGH);
		MSTK_setBusyWait(1200);

		ret = HTFT_OK;

	}
	else
	{
		ret = HTFT_PTR_NULL;
	}
	return ret;
}

EN_HTFT_systeamState_t HTFT_uddtDisplayImage(ST_HTFT_cfg_t const *PS_uddtTftCfg, uint16_t const *copy_u16ArrayOfImage)
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{
		for(uint16_t i = 0; i < 20480 ; i++)
		{
			uint8_t loc_u8LowData = (uint8_t)copy_u16ArrayOfImage[i];
			uint8_t loc_u8HighData = (uint8_t)(copy_u16ArrayOfImage[i]>>8);
			HTFT_uddtWriteData(PS_uddtTftCfg, loc_u8HighData);
			HTFT_uddtWriteData(PS_uddtTftCfg, loc_u8LowData);

		}
	}
	else
	{
		ret = HTFT_PTR_NULL;
	}
	return ret;
}

EN_HTFT_systeamState_t HTFT_uddtFillBackgroundColor(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint16_t copy_u16Color)
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{
			for(uint16_t i = 0; i < 20480 ; i++)
			{
				uint8_t loc_u8LowData = (uint8_t)copy_u16Color;
				uint8_t loc_u8HighData = (uint8_t)(copy_u16Color>>8);
				HTFT_uddtWriteData(PS_uddtTftCfg, loc_u8HighData);
				HTFT_uddtWriteData(PS_uddtTftCfg, loc_u8LowData);

			}
	}
	else
	{
		ret = HTFT_PTR_NULL;
	}

	return ret;
}

EN_HTFT_systeamState_t HTFT_uddtSetXYAxis(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint8_t copy_u8XAxisStart , uint8_t copy_u8XAxisEnd , uint8_t copy_u8YAxisStart , uint8_t copy_u8YAxisEnd)
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{
			HTFT_uddtWriteCommand(PS_uddtTftCfg , HTFT_COMMAND_X_AXIS);
			HTFT_uddtWriteData(PS_uddtTftCfg, copy_u8XAxisStart);
			HTFT_uddtWriteData(PS_uddtTftCfg, copy_u8XAxisStart);
			HTFT_uddtWriteData(PS_uddtTftCfg, copy_u8XAxisStart);
			HTFT_uddtWriteData(PS_uddtTftCfg, copy_u8XAxisEnd);

			HTFT_uddtWriteCommand(PS_uddtTftCfg , HTFT_COMMAND_Y_AXIS);
			HTFT_uddtWriteData(PS_uddtTftCfg, copy_u8YAxisStart);
			HTFT_uddtWriteData(PS_uddtTftCfg, copy_u8YAxisStart);
			HTFT_uddtWriteData(PS_uddtTftCfg, copy_u8YAxisStart);
			HTFT_uddtWriteData(PS_uddtTftCfg, copy_u8YAxisEnd);

			HTFT_uddtWriteCommand(PS_uddtTftCfg , HTFT_COMMAND_RAM_WRITE);
	}
	else
	{
		ret = HTFT_PTR_NULL;
	}

	return ret;
}

EN_HTFT_systeamState_t HTFT_uddtFillRetangle(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint16_t copy_u16Color , uint8_t copy_u8XAxisStart , uint8_t copy_u8XAxisEnd , uint8_t copy_u8YAxisStart , uint8_t copy_u8YAxisEnd)
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{

		HTFT_uddtSetXYAxis(PS_uddtTftCfg ,copy_u8XAxisStart , copy_u8XAxisEnd , copy_u8YAxisStart , copy_u8YAxisEnd);
		uint16_t loc_u16NumberOfPixels = copy_u8XAxisEnd * copy_u8YAxisEnd;
		for(uint16_t i = 0; i < loc_u16NumberOfPixels ; i++)
		{
			uint8_t loc_u8LowData = (uint8_t)copy_u16Color;
			uint8_t loc_u8HighData = (uint8_t)(copy_u16Color>>8);
			HTFT_uddtWriteData(PS_uddtTftCfg, loc_u8HighData);
			HTFT_uddtWriteData(PS_uddtTftCfg, loc_u8LowData);
		}
	}
	else
	{
		ret = HTFT_PTR_NULL;
	}

	return ret;
}

EN_HTFT_systeamState_t HTFT_uddtDrawHorizontalLine(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint16_t copy_u16Color ,  uint8_t copy_u8XAxisStart , uint8_t copy_u8XAxisEnd , uint8_t copy_u8YAxisStart)
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{

		HTFT_uddtSetXYAxis(PS_uddtTftCfg ,copy_u8XAxisStart , copy_u8XAxisEnd , copy_u8YAxisStart , copy_u8YAxisStart);
		uint16_t loc_u16NumberOfPixels = copy_u8XAxisEnd * copy_u8YAxisStart;
		for(uint16_t i = 0; i < loc_u16NumberOfPixels ; i++)
		{
			uint8_t loc_u8LowData = (uint8_t)copy_u16Color;
			uint8_t loc_u8HighData = (uint8_t)(copy_u16Color>>8);
			HTFT_uddtWriteData(PS_uddtTftCfg, loc_u8HighData);
			HTFT_uddtWriteData(PS_uddtTftCfg, loc_u8LowData);
		}
	}
	else
	{
		ret = HTFT_PTR_NULL;
	}

	return ret;
}

EN_HTFT_systeamState_t HTFT_uddtDrawVerticalLine(ST_HTFT_cfg_t const *PS_uddtTftCfg ,  uint16_t copy_u16Color , uint8_t copy_u8XAxisStart , uint8_t copy_u8YAxisStart , uint8_t copy_u8YAxisEnd)
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{

		HTFT_uddtSetXYAxis(PS_uddtTftCfg ,copy_u8XAxisStart , copy_u8XAxisStart , copy_u8YAxisStart , copy_u8YAxisEnd);
		uint16_t loc_u16NumberOfPixels = copy_u8XAxisStart * copy_u8YAxisEnd;
		for(uint16_t i = 0; i < loc_u16NumberOfPixels ; i++)
		{
			uint8_t loc_u8LowData = (uint8_t)copy_u16Color;
			uint8_t loc_u8HighData = (uint8_t)(copy_u16Color>>8);
			HTFT_uddtWriteData(PS_uddtTftCfg, loc_u8HighData);
			HTFT_uddtWriteData(PS_uddtTftCfg, loc_u8LowData);
		}
	}
	else
	{
		ret = HTFT_PTR_NULL;
	}

	return ret;
}


EN_HTFT_systeamState_t HTFT_uddtDrawTriangle(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint16_t copy_u16Color , uint8_t copy_u8XAxisStart , uint8_t copy_u8XAxisEnd , uint8_t copy_u8YAxisStart , uint8_t copy_u8YAxisEnd)
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{

		HTFT_uddtSetXYAxis(PS_uddtTftCfg ,copy_u8XAxisStart , copy_u8XAxisEnd , copy_u8YAxisStart , copy_u8YAxisStart);
		uint16_t loc_u16NumberOfPixels = copy_u8YAxisEnd * copy_u8YAxisStart;
		for(uint16_t i = 0; i < loc_u16NumberOfPixels ; i++)
		{
			HTFT_uddtDrawHorizontalLine(PS_uddtTftCfg, copy_u16Color, copy_u8XAxisStart, copy_u8XAxisEnd, copy_u8YAxisEnd);
			copy_u8XAxisStart--;
			copy_u8XAxisEnd--;
			HTFT_uddtSetXYAxis(PS_uddtTftCfg ,copy_u8XAxisStart , copy_u8XAxisEnd , copy_u8YAxisStart , copy_u8YAxisStart);
		}
	}
	else
	{
		ret = HTFT_PTR_NULL;
	}

	return ret;
}


EN_HTFT_systeamState_t HTFT_uddtClrDisplay(ST_HTFT_cfg_t const *PS_uddtTftCfg)
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{
		HTFT_uddtSetXYAxis(PS_uddtTftCfg ,HTFT_COMMAND_PARAMTER_X_AXIS_START , HTFT_COMMAND_PARAMTER_X_AXIS_END , HTFT_COMMAND_PARAMTER_Y_AXIS_START , HTFT_COMMAND_PARAMTER_Y_AXIS_END );

		for(uint16_t i = 0; i < 20480 ; i++)
		{
			uint8_t loc_u8LowData = (uint8_t)HTFT_WHITE_COLOR;
			uint8_t loc_u8HighData = (uint8_t)(HTFT_WHITE_COLOR>>8);
			HTFT_uddtWriteData(PS_uddtTftCfg, loc_u8HighData);
			HTFT_uddtWriteData(PS_uddtTftCfg, loc_u8LowData);
		}
	}
	else
	{
		ret = HTFT_PTR_NULL;
	}

	return ret;
}


EN_HTFT_systeamState_t HTFT_uddtDrawChar(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint8_t copy_u8XAxis, uint8_t copy_u8YAxis , uint8_t Copy_u8Character,
						FontDef copy_uddtFontSize, uint16_t copy_u16Color, uint16_t copy_u16BgColor )
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{
		uint32_t l_u32Data;
		uint8_t l_u8Counter1,l_u8Counter2;

		HTFT_uddtWriteCommand(PS_uddtTftCfg , 0x2A);
		HTFT_uddtWriteData(PS_uddtTftCfg, 0);
		HTFT_uddtWriteData(PS_uddtTftCfg, copy_u8XAxis);
		HTFT_uddtWriteData(PS_uddtTftCfg, 0);
		HTFT_uddtWriteData(PS_uddtTftCfg, copy_u8XAxis+copy_uddtFontSize.width-1);

		HTFT_uddtWriteCommand(PS_uddtTftCfg , 0x2B);
		HTFT_uddtWriteData(PS_uddtTftCfg, 0);
		HTFT_uddtWriteData(PS_uddtTftCfg, copy_u8YAxis);
		HTFT_uddtWriteData(PS_uddtTftCfg, 0);
		HTFT_uddtWriteData(PS_uddtTftCfg, copy_u8YAxis+copy_uddtFontSize.height-1);

		HTFT_uddtWriteCommand(PS_uddtTftCfg , 0x2C);

		   for(l_u8Counter1 = 0; l_u8Counter1 < copy_uddtFontSize.height; l_u8Counter1++)
		   {
			   l_u32Data = copy_uddtFontSize.data[(Copy_u8Character - 32) * copy_uddtFontSize.height + l_u8Counter1];
		        for(l_u8Counter2 = 0; l_u8Counter2 < copy_uddtFontSize.width; l_u8Counter2++)
		        {
		            if((l_u32Data << l_u8Counter2) & 0x8000)
		            {
		            	HTFT_uddtWriteData(PS_uddtTftCfg, copy_u16Color >> 8);
		            	HTFT_uddtWriteData(PS_uddtTftCfg, (uint8_t)copy_u16Color  );

		            }
		            else
		            {
		            	HTFT_uddtWriteData(PS_uddtTftCfg, copy_u16BgColor >> 8   );
		            	HTFT_uddtWriteData(PS_uddtTftCfg, (uint8_t)copy_u16BgColor  );
		            }
		        }
		    }
		   ret = HTFT_OK;
	}
	else
	{
		ret = HTFT_PTR_NULL;
	}

	return ret;
}

EN_HTFT_systeamState_t HTFT_uddtDrawString(ST_HTFT_cfg_t const *PS_uddtTftCfg , uint16_t copy_u8XAxis , uint16_t copy_u8YAxis ,  char* copy_PtrStr,
						  FontDef copy_uddtFontSize, uint16_t copy_u16Color, uint16_t copy_u16BgColor)
{
	EN_HTFT_systeamState_t ret = HTFT_NOK;

	if(PTR_NULL != PS_uddtTftCfg)
	{
	    while(*copy_PtrStr != STR_NULL)
	    {
	        if(copy_u8XAxis + copy_uddtFontSize.width >= 128)
	        {
	        	copy_u8XAxis = 0;
	        	copy_u8YAxis += copy_uddtFontSize.height;
	            if(copy_u8YAxis + copy_uddtFontSize.height >= 160)
	            {
	                break;
	            }

	            if(*copy_PtrStr == ' ')
	            {
	            	copy_PtrStr++;
	                continue;
	            }
	        }

	        HTFT_uddtDrawChar(PS_uddtTftCfg ,copy_u8XAxis,copy_u8YAxis,(uint8_t)copy_PtrStr,copy_uddtFontSize,copy_u16Color,copy_u16BgColor);

	        copy_u8XAxis += copy_uddtFontSize.width;
	        copy_PtrStr++;

	        ret = HTFT_OK;
	    }
	}
	else
	{
		ret = HTFT_PTR_NULL;
	}

	return ret;
}











