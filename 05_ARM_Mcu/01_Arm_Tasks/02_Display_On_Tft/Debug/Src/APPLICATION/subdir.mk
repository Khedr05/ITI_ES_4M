################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/APPLICATION/app.c 

OBJS += \
./Src/APPLICATION/app.o 

C_DEPS += \
./Src/APPLICATION/app.d 


# Each subdirectory must supply rules for building sources it contributes
Src/APPLICATION/%.o Src/APPLICATION/%.su Src/APPLICATION/%.cyclo: ../Src/APPLICATION/%.c Src/APPLICATION/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-APPLICATION

clean-Src-2f-APPLICATION:
	-$(RM) ./Src/APPLICATION/app.cyclo ./Src/APPLICATION/app.d ./Src/APPLICATION/app.o ./Src/APPLICATION/app.su

.PHONY: clean-Src-2f-APPLICATION

