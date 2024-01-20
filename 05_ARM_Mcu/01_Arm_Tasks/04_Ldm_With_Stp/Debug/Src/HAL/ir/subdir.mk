################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/ir/ir_prog.c 

OBJS += \
./Src/HAL/ir/ir_prog.o 

C_DEPS += \
./Src/HAL/ir/ir_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/ir/%.o Src/HAL/ir/%.su Src/HAL/ir/%.cyclo: ../Src/HAL/ir/%.c Src/HAL/ir/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-ir

clean-Src-2f-HAL-2f-ir:
	-$(RM) ./Src/HAL/ir/ir_prog.cyclo ./Src/HAL/ir/ir_prog.d ./Src/HAL/ir/ir_prog.o ./Src/HAL/ir/ir_prog.su

.PHONY: clean-Src-2f-HAL-2f-ir

