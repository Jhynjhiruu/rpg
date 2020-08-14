#ifndef _SPRITES_H
#define _SPRITES_H

#include "types.h"

const _rom u8 sprites[2][] _at(0x10000) = {
	{
		0xFF, 0xFF, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF9, 0xF0, 0x30, 0x00, 0x00, 0x00, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x6F, 0x0F,
		0xFF, 0xFF, 0xF9, 0xFA, 0xFF, 0xFB, 0xFB, 0xFB,
		0x01, 0x00, 0x00, 0x00, 0x00, 0xC5, 0xFF, 0xFF,
		0xE0, 0x80, 0x80, 0x80, 0x90, 0xF0, 0xF9, 0xFF,
		0x0F, 0x6F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFB, 0xFB, 0xFB, 0xFF, 0xFA, 0xF9, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x01, 0x03,
		0xFF, 0xFF, 0xFF, 0xF1, 0xC0, 0x80, 0x80, 0x80,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xDF, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xF7, 0xFA, 0xFA,
		0x03, 0x01, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0xE0, 0x00, 0x00, 0x00, 0x90, 0xF8, 0xFF, 0xFF,
		0x1F, 0xDF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFA, 0xFA, 0xFB, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF9, 0xF0, 0x90, 0x80, 0x80, 0x80, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x6F, 0x0F,
		0xFF, 0xFF, 0xF9, 0xFA, 0xFF, 0xFB, 0xFB, 0xFB,
		0x01, 0x00, 0x00, 0x00, 0x00, 0xC5, 0xFF, 0xFF,
		0xE0, 0x00, 0x00, 0x00, 0x30, 0xF0, 0xF9, 0xFF,
		0x0F, 0x6F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFB, 0xFB, 0xFB, 0xFF, 0xFA, 0xF9, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x01, 0x03,
		0xFF, 0xFF, 0xF8, 0x90, 0x00, 0x00, 0x00, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xDF, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0xFB, 0xFA, 0xFA,
		0x03, 0x01, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0x80, 0x80, 0x80, 0xC0, 0xF1, 0xFF, 0xFF, 0xFF,
		0x1F, 0xDF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFA, 0xFA, 0xF7, 0xF3, 0xFF, 0xFF, 0xFF, 0xFF,
	},
	{
		0xFF, 0xFF, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF9, 0xF0, 0x30, 0x00, 0x00, 0x00, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x6F, 0x0F,
		0xFF, 0xFF, 0xF9, 0xFA, 0xBC, 0xB0, 0xF1, 0xF1,
		0x01, 0x00, 0x00, 0x00, 0x00, 0xC5, 0xFF, 0xFF,
		0xE0, 0x80, 0x80, 0x80, 0x90, 0xF0, 0xF9, 0xFF,
		0x0F, 0x6F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF1, 0xF9, 0xD8, 0xDC, 0xFA, 0xF9, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x01, 0x03,
		0xFF, 0xFF, 0xFF, 0xF1, 0xC0, 0x80, 0x80, 0x80,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xDF, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0xF5, 0xFA, 0xF2,
		0x03, 0x01, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0xE0, 0x00, 0x00, 0x00, 0x90, 0xF8, 0xFF, 0xFF,
		0x1F, 0xDF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF2, 0xF2, 0xB1, 0x9D, 0xFA, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x01,
		0xFF, 0xF9, 0xF0, 0x90, 0x80, 0x80, 0x80, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x6F, 0x0F,
		0xFF, 0xFF, 0xF9, 0xFA, 0xDC, 0xD8, 0xF9, 0xF1,
		0x01, 0x00, 0x00, 0x00, 0x00, 0xC5, 0xFF, 0xFF,
		0xE0, 0x00, 0x00, 0x00, 0x30, 0xF0, 0xF9, 0xFF,
		0x0F, 0x6F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF1, 0xF1, 0xB0, 0xBC, 0xFA, 0xF9, 0xFF, 0xFF,
		0xFF, 0xFF, 0x8B, 0x01, 0x01, 0x01, 0x01, 0x03,
		0xFF, 0xFF, 0xF8, 0x90, 0x00, 0x00, 0x00, 0xE0,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xDF, 0x1F,
		0xFF, 0xFF, 0xFF, 0xFA, 0x9D, 0xB1, 0xF2, 0xF2,
		0x03, 0x01, 0x01, 0x01, 0x01, 0x8B, 0xFF, 0xFF,
		0x80, 0x80, 0x80, 0xC0, 0xF1, 0xFF, 0xFF, 0xFF,
		0x1F, 0xDF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF2, 0xFA, 0xF5, 0xF1, 0xFF, 0xFF, 0xFF, 0xFF,

	}
};

#endif