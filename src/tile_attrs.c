#include "tile_attrs.h"

void null_interaction(void)
{
    return;
}

const _rom overworldTile tilemap1[256] = {
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    
    {    false, true, true, door_interaction    },
    {    false, true, true, door_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    
    {    false, true, true, door_interaction    },
    {    false, true, true, door_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, door_interaction    },
    {    false, true, false, door_interaction    },
    {    false, false, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, true, false, door_interaction    },
    {    false, true, false, door_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, false, false, null_interaction    },
    {    false, true, false, null_interaction    },
    {    false, true, false, null_interaction    },
    
};


const _rom overworldTile * tile_attrs[2] = {
    tilemap1,
};