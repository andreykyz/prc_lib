################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
prc_lib.lss \

FLASH_IMAGE += \
prc_lib.hex \

EEPROM_IMAGE += \
prc_lib.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: prc_lib.elf secondary-outputs

# Tool invocations
prc_lib.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,prc_lib.map -mmcu=atmega16 -o"prc_lib.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

prc_lib.lss: prc_lib.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S prc_lib.elf  >"prc_lib.lss"
	@echo 'Finished building: $@'
	@echo ' '

prc_lib.hex: prc_lib.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex prc_lib.elf  "prc_lib.hex"
	@echo 'Finished building: $@'
	@echo ' '

prc_lib.eep: prc_lib.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex prc_lib.elf  "prc_lib.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: prc_lib.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 prc_lib.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) prc_lib.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
