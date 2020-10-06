TOOLCHAIN_DIR := ../..
TARGET = rpg

C_SOURCES = $(wildcard src/*.c)
ASM_SOURCES = $(wildcard src/*.asm)

CFLAGS += -DDEBUG

MEM = l

export C88LIB := $(TOOLCHAIN_DIR)/c88tools/lib/src;$(TOOLCHAIN_DIR)/c88tools/lib

include $(TOOLCHAIN_DIR)/pm.mk
