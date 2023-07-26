################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ROBOT_MODES/avoiding_obstacles/avoid_obstacles_prog.c 

OBJS += \
./ROBOT_MODES/avoiding_obstacles/avoid_obstacles_prog.o 

C_DEPS += \
./ROBOT_MODES/avoiding_obstacles/avoid_obstacles_prog.d 


# Each subdirectory must supply rules for building sources it contributes
ROBOT_MODES/avoiding_obstacles/%.o: ../ROBOT_MODES/avoiding_obstacles/%.c ROBOT_MODES/avoiding_obstacles/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


