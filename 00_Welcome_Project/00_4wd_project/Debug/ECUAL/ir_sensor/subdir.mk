################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/ir_sensor/irSensor_cfg.c \
../ECUAL/ir_sensor/irSensor_prog.c 

OBJS += \
./ECUAL/ir_sensor/irSensor_cfg.o \
./ECUAL/ir_sensor/irSensor_prog.o 

C_DEPS += \
./ECUAL/ir_sensor/irSensor_cfg.d \
./ECUAL/ir_sensor/irSensor_prog.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/ir_sensor/%.o: ../ECUAL/ir_sensor/%.c ECUAL/ir_sensor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


