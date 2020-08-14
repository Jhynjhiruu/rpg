#ifndef _MEMORY_H
#define _MEMORY_H

#include "types.h"

#define MEMORY_START 0x14E2

#define RAM_U8(x) *(u8 *)(MEMORY_START + x)
#define RAM_S8(x) *(s8 *)(MEMORY_START + x)

#define RAM_U16(x) *(u16 *)(MEMORY_START + x)
#define RAM_S16(x) *(s16 *)(MEMORY_START + x)

#define RAM_PTR(x) *(u8 **)(MEMORY_START + x)
#define RAM_PTR_RAW(x) (MEMORY_START + x)

#define RAM_U32(x) *(u32 *)(MEMORY_START + x)
#define RAM_S32(x) *(s32 *)(MEMORY_START + x)

#endif