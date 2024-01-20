################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/tft/font.c \
../Src/HAL/tft/tft_prog.c 

OBJS += \
./Src/HAL/tft/font.o \
./Src/HAL/tft/tft_prog.o 

C_DEPS += \
./Src/HAL/tft/font.d \
./Src/HAL/tft/tft_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/tft/%.o Src/HAL/tft/%.su Src/HAL/tft/%.cyclo: ../Src/HAL/tft/%.c Src/HAL/tft/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-tft

clean-Src-2f-HAL-2f-tft:
	-$(RM) ./Src/HAL/tft/font.cyclo ./Src/HAL/tft/font.d ./Src/HAL/tft/font.o ./Src/HAL/tft/font.su ./Src/HAL/tft/tft_prog.cyclo ./Src/HAL/tft/tft_prog.d ./Src/HAL/tft/tft_prog.o ./Src/HAL/tft/tft_prog.su

.PHONY: clean-Src-2f-HAL-2f-tft

