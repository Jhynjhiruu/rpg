#include "door.h"

#include <pm.h>
#include <stdio.h>

#include "screenfade.h"
#include "overworld.h"

extern u8 overworld_map;
extern Coords * player_coords;
extern Coords camera;
extern Coords prev;

void door_interaction(void)
{
    printf("door interact\n");
    
    fadeout(BLACK, 2);

    LCD_CTRL = 0xA5;
    
    switch(overworld_map)
    {
        case 0:
            player_coords[0].x = 0x60;
            player_coords[0].y = 0x30;
            
            camera.x = 0x38;
            camera.y = 0x18;
            
            prev.x = 0xFF;
            prev.y = 0xFF;
            
            overworld_load(1, 1);
            break;
        
        case 1:
            player_coords[0].x = 0x60;
            player_coords[0].y = 0x70;
            
            camera.x = 0x38;
            camera.y = 0x58;
            
            player_coords[0].x = 0xFF;
            player_coords[0].y = 0xFF;
            
            overworld_load(0, 1);
            break;
    }
    
    return;
}