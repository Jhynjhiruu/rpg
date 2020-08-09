#ifndef _MEMORY_H
#define _MEMORY_H

#include "types.h"

#define MEMORY_START 0x14E2

#define RAM_U8(x) *(u8 *)(MEMORY_START + x)

#define RAM_U16(x) *(u16 *)(MEMORY_START + x)

#endif