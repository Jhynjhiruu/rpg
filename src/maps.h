#ifndef _MAPS_H
#define _MAPS_H

#include <pm.h>

#include "types.h"
#include "door.h"
#include "tile_attrs.h"

typedef struct
{
	u8 sprite;
	u8 sprite_attrs;
	
	u16 x;
	u16 y;
	
	void (*interact)(void);
	void (*frame)(void);
} Object;

typedef struct 
{
  u8 tileset;
  
  u8 xsize;
  u8 ysize;
  
  u8 numObjects;
  
  u8 _rom * tileData;
  Object _rom * objectData;
} Map;





#define NUM_MAPS 2

const _rom u8 map_data_0[] = 
{
    0x02, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
    0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
    0x17, 0x17, 0x17, 0x03, 0x10, 0x2f, 0x16, 0x16, 
    0x16, 0x16, 0x16, 0x16, 0x2e, 0x2f, 0x16, 0x16, 
    0x16, 0x16, 0x16, 0x16, 0x2e, 0x04, 0x04, 0x11, 
    0x10, 0x11, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x10, 0x11, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x12, 0x16, 0x2e, 0x11, 0x10, 0x11, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x10, 0x11, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1a, 0x0a, 0x10, 0x11, 
    0x10, 0x11, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x10, 0x11, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x1a, 0x0a, 0x10, 0x11, 0x10, 0x11, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x08, 0x09, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1a, 0x0a, 0x10, 0x11, 
    0x10, 0x11, 0x23, 0x22, 0x23, 0x22, 0x23, 0x22, 
    0x0a, 0x0b, 0x23, 0x22, 0x23, 0x22, 0x23, 0x22, 
    0x20, 0x0a, 0x10, 0x11, 0x10, 0x11, 0x23, 0x22, 
    0x23, 0x22, 0x23, 0x22, 0x0a, 0x0b, 0x23, 0x22, 
    0x23, 0x22, 0x23, 0x22, 0x23, 0x22, 0x10, 0x11, 
    0x10, 0x29, 0x17, 0x17, 0x17, 0x03, 0x23, 0x22, 
    0x0a, 0x0b, 0x23, 0x22, 0x02, 0x03, 0x23, 0x22, 
    0x23, 0x22, 0x10, 0x11, 0x10, 0x2f, 0x16, 0x16, 
    0x16, 0x09, 0x23, 0x22, 0x0a, 0x0b, 0x23, 0x22, 
    0x08, 0x09, 0x23, 0x22, 0x23, 0x22, 0x10, 0x11, 
    0x10, 0x11, 0x1c, 0x1d, 0x1c, 0x0b, 0x23, 0x22, 
    0x23, 0x22, 0x23, 0x22, 0x0a, 0x0b, 0x23, 0x22, 
    0x23, 0x22, 0x10, 0x11, 0x10, 0x11, 0x1c, 0x1d, 
    0x1c, 0x0b, 0x23, 0x22, 0x23, 0x22, 0x23, 0x22, 
    0x0a, 0x0b, 0x23, 0x22, 0x23, 0x22, 0x10, 0x11, 
    0x10, 0x11, 0x1c, 0x1d, 0x1c, 0x0b, 0x23, 0x22, 
    0x23, 0x22, 0x23, 0x22, 0x0a, 0x0b, 0x23, 0x22, 
    0x23, 0x22, 0x10, 0x11, 0x10, 0x11, 0x1c, 0x1d, 
    0x1c, 0x0b, 0x23, 0x22, 0x23, 0x22, 0x23, 0x22, 
    0x0a, 0x0b, 0x23, 0x22, 0x23, 0x22, 0x10, 0x11, 
    0x10, 0x11, 0x23, 0x22, 0x23, 0x22, 0x23, 0x22, 
    0x23, 0x22, 0x23, 0x22, 0x23, 0x22, 0x23, 0x22, 
    0x23, 0x22, 0x10, 0x11, 0x10, 0x04, 0x0f, 0x22, 
    0x23, 0x22, 0x23, 0x22, 0x23, 0x22, 0x23, 0x22, 
    0x23, 0x22, 0x23, 0x22, 0x23, 0x22, 0x10, 0x11, 
    0x10, 0x04, 0x05, 0x17, 0x17, 0x17, 0x17, 0x17, 
    0x17, 0x17, 0x17, 0x03, 0x23, 0x22, 0x02, 0x17, 
    0x17, 0x17, 0x28, 0x11, 0x08, 0x16, 0x16, 0x16, 
    0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x09, 
    0x23, 0x22, 0x08, 0x16, 0x16, 0x16, 0x16, 0x09, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x0b, 0x23, 0x22, 0x0a, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x0b, 
    0x23, 0x22, 0x0a, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x0b, 0x23, 0x22, 0x0a, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x0b, 
    0x23, 0x22, 0x0a, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
};

const _rom u8 map_data_1[] =
{
    0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
    0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
    0x17, 0x17, 0x17, 0x17, 0x16, 0x16, 0x16, 0x16, 
    0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 
    0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x24, 0x25, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x2a, 0x2b, 0x1c, 0x1d, 0x1c, 0x1d, 0x1c, 0x1d, 
    0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x26, 0x27, 0x26, 0x02, 0x03, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x2c, 0x2d, 0x2c, 0x08, 
    0x09, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x26, 0x27, 0x26, 0x0a, 0x0b, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x2c, 0x2d, 0x2c, 0x0a, 
    0x0b, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x02, 0x03, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x08, 0x09, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x0a, 0x0b, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x0a, 0x0b, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 0x26, 0x27, 
    0x26, 0x27, 0x26, 0x27, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
    0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 0x2c, 0x2d, 
};

const _rom Object obj_data_0[] = 
{
	{	5, OAM_ENABLE, 0x70, 0x90, door_interaction, null_interaction	},	
};

const _rom Map maps[NUM_MAPS] = 
{
	{	0, 20, 22, 1, map_data_0, obj_data_0	},
	{	0, 20, 22, 0, map_data_1, null			},
};

#endif