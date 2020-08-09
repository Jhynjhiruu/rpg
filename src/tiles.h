#ifndef _TILES_H
#define _TILES_H

#include "types.h"

#define NUM_TILESETS 1
#define NUM_TILES 1
#define TILE_SIZE 8

const _rom u8 tiles[NUM_TILESETS][2][NUM_TILES][TILE_SIZE] _at(0x2500) = {
	{
		{
			{	0x3C, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C	},
		},
		{
			{	0x18, 0x3C, 0x3C, 0xFF, 0xFF, 0x3C, 0x3C, 0x18	},
		},
	},	
};

#endif