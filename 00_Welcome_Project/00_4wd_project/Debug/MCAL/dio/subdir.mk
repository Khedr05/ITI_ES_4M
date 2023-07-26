################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/dio/DIO_prog.c \
../MCAL/dio/dio_cfg.c 

OBJS += \
./MCAL/dio/DIO_prog.o \
./MCAL/dio/dio_cfg.o 

C_DEPS += \
./MCAL/dio/DIO_prog.d \
./MCAL/dio/dio_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/dio/%.o: ../MCAL/dio/%.c MCAL/dio/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


