################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/Display_st7789/UGUI/ugui.c \
../Libs/Display_st7789/UGUI/ugui_button.c \
../Libs/Display_st7789/UGUI/ugui_checkbox.c \
../Libs/Display_st7789/UGUI/ugui_image.c \
../Libs/Display_st7789/UGUI/ugui_progress.c \
../Libs/Display_st7789/UGUI/ugui_sim.c \
../Libs/Display_st7789/UGUI/ugui_sim_x11.c \
../Libs/Display_st7789/UGUI/ugui_textbox.c 

OBJS += \
./Libs/Display_st7789/UGUI/ugui.o \
./Libs/Display_st7789/UGUI/ugui_button.o \
./Libs/Display_st7789/UGUI/ugui_checkbox.o \
./Libs/Display_st7789/UGUI/ugui_image.o \
./Libs/Display_st7789/UGUI/ugui_progress.o \
./Libs/Display_st7789/UGUI/ugui_sim.o \
./Libs/Display_st7789/UGUI/ugui_sim_x11.o \
./Libs/Display_st7789/UGUI/ugui_textbox.o 

C_DEPS += \
./Libs/Display_st7789/UGUI/ugui.d \
./Libs/Display_st7789/UGUI/ugui_button.d \
./Libs/Display_st7789/UGUI/ugui_checkbox.d \
./Libs/Display_st7789/UGUI/ugui_image.d \
./Libs/Display_st7789/UGUI/ugui_progress.d \
./Libs/Display_st7789/UGUI/ugui_sim.d \
./Libs/Display_st7789/UGUI/ugui_sim_x11.d \
./Libs/Display_st7789/UGUI/ugui_textbox.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/Display_st7789/UGUI/%.o Libs/Display_st7789/UGUI/%.su Libs/Display_st7789/UGUI/%.cyclo: ../Libs/Display_st7789/UGUI/%.c Libs/Display_st7789/UGUI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"D:/Projects/CO2 project_/CO_Detetcor_DMA/Libs" -I"D:/Projects/CO2 project_/CO_Detetcor_DMA/Libs/Display_st7789/UGUI" -I"D:/Projects/CO2 project_/CO_Detetcor_DMA/Libs/Display_st7789/LCD" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs-2f-Display_st7789-2f-UGUI

clean-Libs-2f-Display_st7789-2f-UGUI:
	-$(RM) ./Libs/Display_st7789/UGUI/ugui.cyclo ./Libs/Display_st7789/UGUI/ugui.d ./Libs/Display_st7789/UGUI/ugui.o ./Libs/Display_st7789/UGUI/ugui.su ./Libs/Display_st7789/UGUI/ugui_button.cyclo ./Libs/Display_st7789/UGUI/ugui_button.d ./Libs/Display_st7789/UGUI/ugui_button.o ./Libs/Display_st7789/UGUI/ugui_button.su ./Libs/Display_st7789/UGUI/ugui_checkbox.cyclo ./Libs/Display_st7789/UGUI/ugui_checkbox.d ./Libs/Display_st7789/UGUI/ugui_checkbox.o ./Libs/Display_st7789/UGUI/ugui_checkbox.su ./Libs/Display_st7789/UGUI/ugui_image.cyclo ./Libs/Display_st7789/UGUI/ugui_image.d ./Libs/Display_st7789/UGUI/ugui_image.o ./Libs/Display_st7789/UGUI/ugui_image.su ./Libs/Display_st7789/UGUI/ugui_progress.cyclo ./Libs/Display_st7789/UGUI/ugui_progress.d ./Libs/Display_st7789/UGUI/ugui_progress.o ./Libs/Display_st7789/UGUI/ugui_progress.su ./Libs/Display_st7789/UGUI/ugui_sim.cyclo ./Libs/Display_st7789/UGUI/ugui_sim.d ./Libs/Display_st7789/UGUI/ugui_sim.o ./Libs/Display_st7789/UGUI/ugui_sim.su ./Libs/Display_st7789/UGUI/ugui_sim_x11.cyclo ./Libs/Display_st7789/UGUI/ugui_sim_x11.d ./Libs/Display_st7789/UGUI/ugui_sim_x11.o ./Libs/Display_st7789/UGUI/ugui_sim_x11.su ./Libs/Display_st7789/UGUI/ugui_textbox.cyclo ./Libs/Display_st7789/UGUI/ugui_textbox.d ./Libs/Display_st7789/UGUI/ugui_textbox.o ./Libs/Display_st7789/UGUI/ugui_textbox.su

.PHONY: clean-Libs-2f-Display_st7789-2f-UGUI

