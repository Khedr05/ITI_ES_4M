################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/gpio/gpio_prog.c 

OBJS += \
./Src/MCAL/gpio/gpio_prog.o 

C_DEPS += \
./Src/MCAL/gpio/gpio_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/gpio/%.o Src/MCAL/gpio/%.su Src/MCAL/gpio/%.cyclo: ../Src/MCAL/gpio/%.c Src/MCAL/gpio/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-gpio

clean-Src-2f-MCAL-2f-gpio:
	-$(RM) ./Src/MCAL/gpio/gpio_prog.cyclo ./Src/MCAL/gpio/gpio_prog.d ./Src/MCAL/gpio/gpio_prog.o ./Src/MCAL/gpio/gpio_prog.su

.PHONY: clean-Src-2f-MCAL-2f-gpio

