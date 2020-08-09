#ifndef _TILE_ATTRS_H
#define _TILE_ATTRS_H

#include "types.h"

void null_interaction(u8 ignored);

typedef struct
{
	// properties
	unsigned int canInteract: 1;
	unsigned int canWalkOn: 1;
	// ...
	
	// callback function for interaction
	void (*interact)(u8 direction);
} overworldTile;

const _rom overworldTile tile_attrs[][] = {
	{
		{	false, true, null_interaction	},
	},	
};


#endif