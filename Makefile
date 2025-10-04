# Makefile for AUTOSAR BSW Layer for Infineon TC377 Motor Control Application

# Compiler and tools
CC = tc377-gcc
AS = tc377-as
LD = tc377-ld
OBJCOPY = tc377-objcopy
OBJDUMP = tc377-objdump
SIZE = tc377-size

# Project name
TARGET = MotorControlDemo

# Directories
BSW_DIR = BSW
MCAL_DIR = $(BSW_DIR)/MCAL
SS_DIR = $(BSW_DIR)/SS
EAL_DIR = $(BSW_DIR)/EAL

# MCAL modules
MCAL_MODULES = Dio Pwm Adc Gpt

# SS modules
SS_MODULES = Det

# Source files
SRC_FILES = MotorControlDemo.c

# Add BSW source files
SRC_FILES += $(BSW_DIR)/Std_Types.h $(BSW_DIR)/Platform_Types.h

# Add MCAL source files
foreach mod in $(MCAL_MODULES)
SRC_FILES += $(MCAL_DIR)/$(mod)/$(mod).c $(MCAL_DIR)/$(mod)/$(mod)_Cfg.c
endfor

# Add SS source files
foreach mod in $(SS_MODULES)
SRC_FILES += $(SS_DIR)/$(mod)/$(mod).c
endfor

# Include directories
INC_DIRS = -I$(BSW_DIR) \
           $(foreach mod,$(MCAL_MODULES),-I$(MCAL_DIR)/$(mod)) \
           $(foreach mod,$(SS_MODULES),-I$(SS_DIR)/$(mod))

# Compiler flags
CFLAGS = -mcpu=tc377 -mthumb -O2 -Wall -Wextra -Werror \
         -fmessage-length=0 -ffunction-sections -fdata-sections \
         $(INC_DIRS)

# Linker flags
LDFLAGS = -mcpu=tc377 -mthumb -Wl,--gc-sections -T tc377_linker.ld

# Object files
OBJ_FILES = $(patsubst %.c,%.o,$(filter %.c,$(SRC_FILES)))

# Build targets
all: $(TARGET).elf $(TARGET).hex $(TARGET).bin size

$(TARGET).elf: $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

size:
	$(SIZE) $(TARGET).elf

# Clean target
clean:
	rm -f $(OBJ_FILES) $(TARGET).elf $(TARGET).hex $(TARGET).bin

# Rebuild target
rebuild: clean all

# Phony targets
.PHONY: all clean rebuild size

# Help target
help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all        - Build all (default)"
	@echo "  clean      - Remove all build files"
	@echo "  rebuild    - Clean and build all"
	@echo "  size       - Display size information"
	@echo "  help       - Display this help message"