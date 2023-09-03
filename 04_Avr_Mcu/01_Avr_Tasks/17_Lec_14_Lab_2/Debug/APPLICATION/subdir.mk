################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APPLICATION/Mapp.c \
../APPLICATION/Sapp.c \
../APPLICATION/device_cfg.c 

OBJS += \
./APPLICATION/Mapp.o \
./APPLICATION/Sapp.o \
./APPLICATION/device_cfg.o 

C_DEPS += \
./APPLICATION/Mapp.d \
./APPLICATION/Sapp.d \
./APPLICATION/device_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
APPLICATION/%.o: ../APPLICATION/%.c APPLICATION/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


