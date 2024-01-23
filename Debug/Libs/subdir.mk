################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/AHT20.c \
../Libs/USB_driver.c \
../Libs/button.c \
../Libs/buzzer.c \
../Libs/internal_adc.c 

OBJS += \
./Libs/AHT20.o \
./Libs/USB_driver.o \
./Libs/button.o \
./Libs/buzzer.o \
./Libs/internal_adc.o 

C_DEPS += \
./Libs/AHT20.d \
./Libs/USB_driver.d \
./Libs/button.d \
./Libs/buzzer.d \
./Libs/internal_adc.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/%.o Libs/%.su Libs/%.cyclo: ../Libs/%.c Libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"D:/Projects/CO2 project_/CO_Detetcor_DMA/Libs" -I"D:/Projects/CO2 project_/CO_Detetcor_DMA/Libs/Display_st7789/UGUI" -I"D:/Projects/CO2 project_/CO_Detetcor_DMA/Libs/Display_st7789/LCD" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs

clean-Libs:
	-$(RM) ./Libs/AHT20.cyclo ./Libs/AHT20.d ./Libs/AHT20.o ./Libs/AHT20.su ./Libs/USB_driver.cyclo ./Libs/USB_driver.d ./Libs/USB_driver.o ./Libs/USB_driver.su ./Libs/button.cyclo ./Libs/button.d ./Libs/button.o ./Libs/button.su ./Libs/buzzer.cyclo ./Libs/buzzer.d ./Libs/buzzer.o ./Libs/buzzer.su ./Libs/internal_adc.cyclo ./Libs/internal_adc.d ./Libs/internal_adc.o ./Libs/internal_adc.su

.PHONY: clean-Libs

