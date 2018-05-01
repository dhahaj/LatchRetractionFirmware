
SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../door.cpp \
../main.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
door.o \
main.o

OBJS_AS_ARGS +=  \
door.o \
main.o

C_DEPS +=  \
door.d \
main.d

C_DEPS_AS_ARGS +=  \
door.d \
main.d

OUTPUT_FILE_PATH +=LatchRetractionFirmware.elf

OUTPUT_FILE_PATH_AS_ARGS +=LatchRetractionFirmware.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler

./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=8000000  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.3.147\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=attiny88 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.3.147\gcc\dev\attiny88" -c -v -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

# AVR32/GNU Preprocessing Assembler

# AVR32/GNU Assembler

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="LatchRetractionFirmware.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=attiny88 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.3.147\gcc\dev\attiny88"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "LatchRetractionFirmware.elf" "LatchRetractionFirmware.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "LatchRetractionFirmware.elf" "LatchRetractionFirmware.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "LatchRetractionFirmware.elf" > "LatchRetractionFirmware.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "LatchRetractionFirmware.elf"
	

# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES) $(C_DEPS_AS_ARGS) "LatchRetractionFirmware.elf" "LatchRetractionFirmware.a" "LatchRetractionFirmware.hex" "LatchRetractionFirmware.lss" "LatchRetractionFirmware.eep" "LatchRetractionFirmware.map" "LatchRetractionFirmware.srec" "LatchRetractionFirmware.usersignatures"
	# -$(RM) $(C_DEPS_AS_ARGS) 
	# -$(RM) "LatchRetractionFirmware.elf" "LatchRetractionFirmware.a" "LatchRetractionFirmware.hex" "LatchRetractionFirmware.lss" "LatchRetractionFirmware.eep" "LatchRetractionFirmware.map" "LatchRetractionFirmware.srec" "LatchRetractionFirmware.usersignatures"
	







###################################################
#####    AVR Project Makefile Template       ######
###################################################


#### This Makefile will make compiling Atmel AVR 
#### micro controller projects simple with Linux 
#### or other Unix workstations and the AVR-GCC 
#### tools.
####
#### It supports C, C++ and Assembly source files.
####
#### Customize the values as indicated below and :
#### make
#### make hex
#### or make clean


####         Target Specific Details          #####
####     Customize these for your project     #####

# Name of target controller 
# MCU=attiny88

# id to use with programmer
# default: PROGRAMMER_MCU=$(MCU)
# In case the programer used, e.g avrdude, doesn't
# accept the same MCU name as avr-gcc (for example
# for ATmega8s, avr-gcc expects 'atmega8' and 
# avrdude requires 'm8')
# PROGRAMMER_MCU=t88

# Name of our project
# (use a single word, e.g. 'myproject')
# PROJECTNAME=main

# Source files
# List C/C++/Assembly source files:
# (list all files to compile, e.g. 'a.c b.cpp as.S'):
# Use .cc, .cpp or .C suffix for C++ files, use .S 
# (NOT .s !!!) for assembly source code files.
# PRJSRC=main.c myclass.cpp lowlevelstuff.S
# PRJSRC=$(PROJECTNAME).cpp

# additional includes (e.g. -I/path/to/mydir)
# INC=-I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.3.147\include"

# Dependencies
# DEPS=-DF_CPU=8000000 -DDEBUG 

# libraries to link in (e.g. -lmylib)
# LIBS=

# Optimization level, 
# use s (size opt), 1, 2, 3 or 0 (off)
# OPTLEVEL=s

####      AVR Dude 'writeflash' options       #####
####  If you are using the avrdude program
####  (http://www.bsdhome.com/avrdude/) to write
####  to the MCU, you can set the following config
####  options and use 'make writeflash' to program
####  the device.

# programmer id--check the avrdude for complete list
# of available opts.  These should include stk500,
# avr910, avrisp, bsd, pony and more.  Set this to
# one of the valid "-c PROGRAMMER-ID" values 
# described in the avrdude info page.
# AVRDUDE_PROGRAMMERID=usbasp

# port--serial or parallel port to which your 
# hardware programmer is attached
# AVRDUDE_PORT=

###################################################
####                Config Done               #####
####                                          #####
#### You shouldn't need to edit anything      #####
#### below to use the makefile but may wish   #####
#### to override a few of the flags           #####
#### nonetheless                              #####
####                                          #####
###################################################

##### Flags #####

# -x c -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.3.147\include" -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.3.147\gcc\dev\attiny88" -c -std=gnu99 -v -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" 


# -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.3.147\include" -g2 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.3.147\gcc\dev\attiny88" -c -v -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" 

# HEXFORMAT -- format for .hex file output
# HEXFORMAT=ihex

# compiler
# xCFLAGS=-I. $(INC) -g2 -mmcu=$(MCU) -O$(OPTLEVEL) $(DEPS) -c -std=gnu99 -v  \
	# -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char    \
	# -Wall -Wstrict-prototypes -Wa,-ahlms=$(firstword $(filter %.lst, $(<:.c=.lst)))
  
# CFLAGS=-I. $(INC) -g2 -mmcu=$(MCU) -O$(OPTLEVEL) -DDEBUG -W -pedantic -Wundef -Werror	\
	# -funsigned-char -funsigned-bitfields -ffunction-sections -fpack-struct -fshort-enums	\
	# -fdata-sections -ffreestanding -Os -gdwarf-2	-fwhole-program	\
	# -fno-inline-small-functions -fno-split-wide-types -fno-tree-scev-cprop -v -c

  # --combine -Wall,--relax,--gc-sections -std=gnu99 -Wstrict-prototypes 


# c++ specific flags
# CPPFLAGS=-fno-exceptions         \
	# -Wa,-ahlms=$(firstword         \
	# $(filter %.lst, $(<:.cpp=.lst))\
	# $(filter %.lst, $(<:.cc=.lst)) \
	# $(filter %.lst, $(<:.C=.lst)))

# assembler
# ASMFLAGS =-I. $(INC) -mmcu=$(MCU) -x assembler-with-cpp -Wa,-gstabs,-ahlms=$(firstword $(<:.S=.lst) $(<.s=.lst))

# linker
# LDFLAGS=-Wl,-Map,$(TRG).map -mmcu=$(MCU) -lm $(LIBS)

#### executables ####
# CC=avr-gcc
# OBJCOPY=avr-objcopy
# OBJDUMP=avr-objdump
# SIZE=avr-size
# AVRDUDE=avrdude
# REMOVE=rm -f

#### automatic target names ####
# TRG=$(PROJECTNAME).out
# DUMPTRG=$(PROJECTNAME).s

# HEXROMTRG=$(PROJECTNAME).hex 
# HEXTRG=$(HEXROMTRG) $(PROJECTNAME).ee.hex
# GDBINITFILE=gdbinit-$(PROJECTNAME)

# Define all object files.

# Start by splitting source files by type
 # C++
# CPPFILES=$(filter %.cpp, $(PRJSRC))
# CCFILES=$(filter %.cc, $(PRJSRC))
# BIGCFILES=$(filter %.C, $(PRJSRC))
 # C
# CFILES=$(filter %.c, $(PRJSRC))
 # Assembly
# ASMFILES=$(filter %.S, $(PRJSRC))


# List all object files we need to create
# OBJDEPS=$(CFILES:.c=.o)    \
	# $(CPPFILES:.cpp=.o)\
	# $(BIGCFILES:.C=.o) \
	# $(CCFILES:.cc=.o)  \
	# $(ASMFILES:.S=.o)

# Define all lst files.
# LST=$(filter %.lst, $(OBJDEPS:.o=.lst))

# All the possible generated assembly 
# files (.s files)
# GENASMFILES=$(filter %.s, $(OBJDEPS:.o=.s)) 


# .SUFFIXES : .c .cc .cpp .C .o .out .s .S \
	# .hex .ee.hex .h .hh .hpp


# .PHONY: writeflash clean stats gdbinit stats

# Make targets:
# all, disasm, stats, hex, writeflash/install, clean
# all: $(HEXTRG)

# disasm: $(DUMPTRG) stats

# stats: $(TRG)
	# $(OBJDUMP) -h $(TRG)
	# $(SIZE) $(TRG) 

# hex: $(HEXTRG)


# writeflash: hex
	# $(AVRDUDE) -c $(AVRDUDE_PROGRAMMERID) -B 10  \
	 # -p $(PROGRAMMER_MCU) -P $(AVRDUDE_PORT) -e        \
	 # -V -U flash:w:$(HEXROMTRG) -U eeprom:w:$(PROJECTNAME).ee.hex 

# install: writeflash

# $(DUMPTRG): $(TRG) 
	# $(OBJDUMP) -S  $< > $@

# $(TRG): $(OBJDEPS) 
	# $(CC) $(LDFLAGS) -o $(TRG) $(OBJDEPS)

### Generating assembly ####
# asm from C
# %.s: %.c
	# $(CC) -S $(CFLAGS) $< -o $@

# asm from (hand coded) asm
# %.s: %.S
	# $(CC) -S $(ASMFLAGS) $< > $@


# asm from C++
# .cpp.s .cc.s .C.s :
	# $(CC) -S $(CFLAGS) $(CPPFLAGS) $< -o $@


### Generating object files ####
# object from C
# .c.o: 
	# $(CC) $(CFLAGS) -c $< -o $@

# object from C++ (.cc, .cpp, .C files)
# .cc.o .cpp.o .C.o :
	# $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# object from asm
# .S.o :
	# $(CC) $(ASMFLAGS) -c $< -o $@


### Generating hex files ####
# hex files from elf
####  Generating a gdb initialisation file    #####
# .out.hex:
	# $(OBJCOPY) -j .text                    \
		# -j .data                       \
		# -O $(HEXFORMAT) $< $@

# .out.ee.hex:
	# $(OBJCOPY) -j .eeprom                  \
		# --change-section-lma .eeprom=0 \
		# -O $(HEXFORMAT) $< $@


####  Generating a gdb initialisation file    #####
#### Use by launching simulavr and avr-gdb:   #####
####   avr-gdb -x gdbinit-myproject           #####
# gdbinit: $(GDBINITFILE)

# $(GDBINITFILE): $(TRG)
	# @echo "file $(TRG)" > $(GDBINITFILE)
	
	# @echo "target remote localhost:1212" \
		                # >> $(GDBINITFILE)
	
	# @echo "load"        >> $(GDBINITFILE) 
	# @echo "break main"  >> $(GDBINITFILE)
	# @echo "continue"    >> $(GDBINITFILE)
	# @echo
	# @echo "Use 'avr-gdb -x $(GDBINITFILE)'"

### Cleanup ####
# clean:
	# $(REMOVE) $(TRG) $(TRG).map $(DUMPTRG)
	# $(REMOVE) $(OBJDEPS)
	# $(REMOVE) $(LST) $(GDBINITFILE)
	# $(REMOVE) $(GENASMFILES)
	# $(REMOVE) $(HEXTRG)

####                    EOF                   #####

