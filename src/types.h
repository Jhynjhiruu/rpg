#ifndef _TYPES_H
#define _TYPES_H

#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

typedef enum _Bool
{
	false,
	true
} bool;

#define null (void *)0x0000

#endif