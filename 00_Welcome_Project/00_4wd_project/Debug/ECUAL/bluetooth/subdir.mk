################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/bluetooth/bluetooth_prog.c 

OBJS += \
./ECUAL/bluetooth/bluetooth_prog.o 

C_DEPS += \
./ECUAL/bluetooth/bluetooth_prog.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/bluetooth/%.o: ../ECUAL/bluetooth/%.c ECUAL/bluetooth/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


