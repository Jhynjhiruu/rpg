#ifndef _OVERWORLD_H
#define _OVERWORLD_H

#include "types.h"

typedef struct
{
    s16 x;
    s16 y;
} Coords;

void overworld_frame_copy(void);

void draw_overworld_tile_data(void);

void draw_overworld_screen(void);

void overworld_init(void);

void overworld_load(u8 map, u8 num_players);

void overworld_mainloop(void);

#endif