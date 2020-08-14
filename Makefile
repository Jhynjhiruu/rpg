TOOLCHAIN_DIR := ../..
TARGET = rpg

C_SOURCES = $(wildcard src/*.c)
ASM_SOURCES = $(wildcard src/*.asm)

CFLAGS += -DDEBUG

include $(TOOLCHAIN_DIR)/pm.mk
