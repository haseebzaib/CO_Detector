################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/Display_st7789/LCD/images.c \
../Libs/Display_st7789/LCD/lcd.c 

OBJS += \
./Libs/Display_st7789/LCD/images.o \
./Libs/Display_st7789/LCD/lcd.o 

C_DEPS += \
./Libs/Display_st7789/LCD/images.d \
./Libs/Display_st7789/LCD/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/Display_st7789/LCD/%.o Libs/Display_st7789/LCD/%.su Libs/Display_st7789/LCD/%.cyclo: ../Libs/Display_st7789/LCD/%.c Libs/Display_st7789/LCD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"D:/Projects/CO2 project_/CO_Detetcor_DMA/Libs" -I"D:/Projects/CO2 project_/CO_Detetcor_DMA/Libs/Display_st7789/UGUI" -I"D:/Projects/CO2 project_/CO_Detetcor_DMA/Libs/Display_st7789/LCD" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs-2f-Display_st7789-2f-LCD

clean-Libs-2f-Display_st7789-2f-LCD:
	-$(RM) ./Libs/Display_st7789/LCD/images.cyclo ./Libs/Display_st7789/LCD/images.d ./Libs/Display_st7789/LCD/images.o ./Libs/Display_st7789/LCD/images.su ./Libs/Display_st7789/LCD/lcd.cyclo ./Libs/Display_st7789/LCD/lcd.d ./Libs/Display_st7789/LCD/lcd.o ./Libs/Display_st7789/LCD/lcd.su

.PHONY: clean-Libs-2f-Display_st7789-2f-LCD

