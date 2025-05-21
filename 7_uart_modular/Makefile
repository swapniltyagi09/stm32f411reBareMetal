#Defining the toolchain and build settings for STM32F411RE
#This Makefile is used to compile and link a bare-metal program for the STM32F411RE microcontroller using the ARM GCC toolchain.
#It includes rules for building the project, cleaning up build artifacts, and flashing the program to the microcontroller using OpenOCD.
#Makefile for STM32F411RE Baremetal
TARGET = 7_uart_modular
CC = arm-none-eabi-gcc #Compiler for ARM Cortex-M
OBJCOPY = arm-none-eabi-objcopy #Convert ELF to binary
GDB = gdb-multiarch #Debugger for embedded systems
OPENOCD = openocd #Interface to flash and debug STM32
INCLUDE_FLAGS = -I./ -I../F4_chip_headers/CMSIS/Device/ST/STM32F4xx/Include/ \
	-I../F4_chip_headers/CMSIS/Include/ #Include directories for CMSIS headers

#Microcontroller and Compilation Flags
MCU = cortex-m4 #Target MCU , specifies the target processor architecture
CFLAGS = $(INCLUDE_FLAGS) -DSTM32F411xE -mcpu=$(MCU) -mthumb -nostdlib -Wall -specs=nano.specs -u _printf_float
#-mcpu=$(MCU) Compile for Cortex-M4 (your STM32F411RE's core)
#-mthumb Use the Thumb instruction set (optimised for ARM Cortex-M)
#-nostdlib Do not link against the standard library (we are using our own startup code) , as it is baremetal programming
#-Wall Enable all compiler warnings to help catch potential issues in the code

#Linker Scripts
LDFLAGS_FLASH = -T../linkerScripts/STM32F411RETX_FLASH.ld #Linker script for flash memory

#Source Files and output Names
SRCS = main.c uart.c syscalls.c sysmem.c#The main c program file
SATARTUP = ../startupScripts/startup_stm32f411retx.s #Startup code for STM32F411RE
#The startup code is responsible for setting up the microcontroller's stack pointer and initializing the data and bss sections before calling the main function.
#The startup code is usually written in assembly language and is specific to the microcontroller being used.
#The linker script defines the memory layout of the microcontroller and specifies where the code and data sections should be placed in memory.
#The linker script is also specific to the microcontroller and is used by the linker to create the final binary file.
#The startup code and linker script are essential for bare-metal programming, as they ensure that the program is loaded into the correct memory locations and that the microcontroller is properly initialized before executing the main function.
#The startup code and linker script are usually provided by the microcontroller manufacturer or can be found in open-source projects.		
ELF_FLASH = $(TARGET)_flash.elf #Output ELF file for flash memory , compiled output files
BIN_FLASH = $(TARGET)_flash.bin #Output binary file for flash memory , Converted binaries for flashing

#Default target(Compile for flash memory)
all: flash

#Compile and link for flash execution
flash:
	$(CC) $(CFLAGS) $(LDFLAGS_FLASH) -o $(ELF_FLASH) $(SATARTUP) $(SRCS) 
	$(OBJCOPY) -O binary $(ELF_FLASH) $(BIN_FLASH)
	@echo "Flash binary created: $(BIN_FLASH)"

#Flash the binary to the STM32F411RE using OpenOCD
upload:
	$(OPENOCD) -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program $(BIN_FLASH) 0X08000000 verify reset exit"
	@echo "Binary fashed"

#Debugging with GDB
debug:
	$(OPENOCD) -f interface/stlink.cfg -f target/stm32f4x.cfg -c "init" -c "reset init" &
	$(GDB) $(ELF_FLASH) -ex "target remote localhost:3333" -ex "monitor reset halt" -ex "load"
	@echo "Debugging with GDB started"

#Clean up build artifacts
clean:
	rm -f $(ELF_FLASH) $(BIN_FLASH) 
	@echo "Cleaned up build artifacts"