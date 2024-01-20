################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/MCAL/usart/subdir.mk
-include Src/MCAL/systick/subdir.mk
-include Src/MCAL/spi/subdir.mk
-include Src/MCAL/rcc/subdir.mk
-include Src/MCAL/nvic/subdir.mk
-include Src/MCAL/gpio/subdir.mk
-include Src/MCAL/exti/subdir.mk
-include Src/MCAL/dma/subdir.mk
-include Src/HAL/tft/subdir.mk
-include Src/HAL/ssd/subdir.mk
-include Src/HAL/ledMatrix/subdir.mk
-include Src/HAL/ir/subdir.mk
-include Src/HAL/dac/subdir.mk
-include Src/APPLICATION/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := 02_Display_On_Tft
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
02_Display_On_Tft.elf \

MAP_FILES += \
02_Display_On_Tft.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
02_Display_On_Tft.list \


# All Target
all: main-build

# Main-build Target
main-build: 02_Display_On_Tft.elf secondary-outputs

# Tool invocations
02_Display_On_Tft.elf 02_Display_On_Tft.map: $(OBJS) $(USER_OBJS) D:\Programing\Embedded\ System\ Diploma\ITI\ITI_Stmcube_Workspace\02_Display_On_Tft\STM32F401CCUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "02_Display_On_Tft.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\Programing\Embedded System Diploma\ITI\ITI_Stmcube_Workspace\02_Display_On_Tft\STM32F401CCUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="02_Display_On_Tft.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

02_Display_On_Tft.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "02_Display_On_Tft.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) 02_Display_On_Tft.elf 02_Display_On_Tft.list 02_Display_On_Tft.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
