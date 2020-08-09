TOOLCHAIN_DIR := ../..
TARGET = rpg

C_SOURCES = $(wildcard src/*.c)
ASM_SOURCES = $(wildcard src/*.asm)

include $(TOOLCHAIN_DIR)/pm.mk

CFLAGS += -DDEBUG
