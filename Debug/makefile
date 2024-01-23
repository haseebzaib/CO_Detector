################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Libs/Display_st7789/UGUI/Fonts/subdir.mk
-include Libs/Display_st7789/UGUI/subdir.mk
-include Libs/Display_st7789/LCD/subdir.mk
-include Libs/subdir.mk
-include Drivers/STM32G0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := CO_Detetcor_DMA
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
CO_Detetcor_DMA.elf \

MAP_FILES += \
CO_Detetcor_DMA.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CO_Detetcor_DMA.list \

OBJCOPY_HEX += \
CO_Detetcor_DMA.hex \

OBJCOPY_BIN += \
CO_Detetcor_DMA.bin \


# All Target
all: main-build

# Main-build Target
main-build: CO_Detetcor_DMA.elf secondary-outputs

# Tool invocations
CO_Detetcor_DMA.elf CO_Detetcor_DMA.map: $(OBJS) $(USER_OBJS) D:\Projects\CO2\ project_\CO_Detetcor_DMA\STM32G030C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "CO_Detetcor_DMA.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"D:\Projects\CO2 project_\CO_Detetcor_DMA\STM32G030C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CO_Detetcor_DMA.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CO_Detetcor_DMA.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CO_Detetcor_DMA.list"
	@echo 'Finished building: $@'
	@echo ' '

CO_Detetcor_DMA.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "CO_Detetcor_DMA.hex"
	@echo 'Finished building: $@'
	@echo ' '

CO_Detetcor_DMA.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "CO_Detetcor_DMA.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) CO_Detetcor_DMA.bin CO_Detetcor_DMA.elf CO_Detetcor_DMA.hex CO_Detetcor_DMA.list CO_Detetcor_DMA.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
