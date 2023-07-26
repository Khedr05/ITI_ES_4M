################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ROBOT_MODES/line_follower/lineFollower_prog.c 

OBJS += \
./ROBOT_MODES/line_follower/lineFollower_prog.o 

C_DEPS += \
./ROBOT_MODES/line_follower/lineFollower_prog.d 


# Each subdirectory must supply rules for building sources it contributes
ROBOT_MODES/line_follower/%.o: ../ROBOT_MODES/line_follower/%.c ROBOT_MODES/line_follower/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


