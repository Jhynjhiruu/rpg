#ifndef _TILE_ATTRS_H
#define _TILE_ATTRS_H

#include "types.h"
#include "door.h"

void null_interaction(void);

typedef struct
{
	// properties
	unsigned int canInteract: 1;
	unsigned int canWalkOn: 1;
	unsigned int interactOnTouch: 1;
	// ...
	
	// callback function for interaction
	void (*interact)(void);
} overworldTile;

static const _rom overworldTile tile_attrs[][256] = {
	{
		{	false, true, false, null_interaction	},
		{	false, true, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, true, false, null_interaction	},
		{	false, true, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, true, false, null_interaction	},
		{	false, true, false, null_interaction	},
		{	false, true, true, door_interaction		},
		{	false, true, true, door_interaction		},
		{	false, true, false, null_interaction	},
		{	false, true, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, true, true, door_interaction		},
		{	false, true, true, door_interaction		},
		{	false, true, false, null_interaction	},
		{	false, true, false, null_interaction	},
		{	false, false, false, null_interaction	},
		{	false, false, false, null_interaction	},
	},	
};

#endif