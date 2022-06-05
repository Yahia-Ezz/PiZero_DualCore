SRC_DIR = 00_Sources
OUT_DIR = 01_Output
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OC = arm-none-eabi-objcopy

CFLAGS = -Wall
CFLAGS += -O0
CFLAGS += -mcpu=cortex-m0plus
CFLAGS += -mthumb

LFLAGS = --nostdlib

all: $(SRC_DIR)/StartUpCode.c $(SRC_DIR)/main.c
	@if [ ! -d $(OUT_DIR) ]; then mkdir $(OUT_DIR); fi
	$(CC) $(CFLAGS) -c $(SRC_DIR)/StartUpCode.c -o $(OUT_DIR)/StartUpCode.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o  $(OUT_DIR)/main.o
	$(LD) -Map  $(OUT_DIR)/MemoryMap.map $(LFLAGS) -T LinkerCommands.ld $(OUT_DIR)/StartUpCode.o $(OUT_DIR)/main.o -o $(OUT_DIR)/StartUpCode.elf
	$(OC) $(OUT_DIR)/StartUpCode.elf -O binary $(OUT_DIR)/Test.bin
	Tool/bin2uf2.exe -i $(OUT_DIR)/Test.bin -o $(OUT_DIR)/Test.uf2

clean :
	rm  -rf $(OUT_DIR)