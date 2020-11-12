#ifndef _TILE_ATTRS_H
#define _TILE_ATTRS_H

#include <pm.h>

#include "types.h"
#include "door.h"

void null_interaction(void);

#define CanInteract _BV(0)
#define CanWalkOn _BV(1)
#define InteractOnTouch _BV(2)

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

extern const _rom overworldTile * tile_attrs[2];

extern const _rom overworldTile tilemap1[256];

#endif