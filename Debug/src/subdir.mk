################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/stm32f4xx_gpio.c \
../src/stm32f4xx_rcc.c \
../src/system_stm32f4xx.c \
../src/tm_stm32f4_delay.c \
../src/tm_stm32f4_disco.c \
../src/tm_stm32f4_ds18b20.c \
../src/tm_stm32f4_gpio.c \
../src/tm_stm32f4_onewire.c 

OBJS += \
./src/main.o \
./src/stm32f4xx_gpio.o \
./src/stm32f4xx_rcc.o \
./src/system_stm32f4xx.o \
./src/tm_stm32f4_delay.o \
./src/tm_stm32f4_disco.o \
./src/tm_stm32f4_ds18b20.o \
./src/tm_stm32f4_gpio.o \
./src/tm_stm32f4_onewire.o 

C_DEPS += \
./src/main.d \
./src/stm32f4xx_gpio.d \
./src/stm32f4xx_rcc.d \
./src/system_stm32f4xx.d \
./src/tm_stm32f4_delay.d \
./src/tm_stm32f4_disco.d \
./src/tm_stm32f4_ds18b20.d \
./src/tm_stm32f4_gpio.d \
./src/tm_stm32f4_onewire.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F4 -DSTM32 -DNUCLEO_F411RE -DSTM32F411RETx -DDEBUG -DSTM32F411xE -I"C:/Users/user/workspace/NewTempSen/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


