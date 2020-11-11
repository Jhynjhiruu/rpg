#ifndef _OVERWORLD_H
#define _OVERWORLD_H

#include "types.h"

#include "tile_attrs.h"

typedef struct
{
    s16 x;
    s16 y;
} Coords;

void overworld_frame_copy(void);

void overworld_8hz_timer(void);

void draw_overworld_tile_data(void);

void draw_overworld_screen(void);

void overworld_init(void);

void overworld_load(u8 map, u8 num_players);

u8 check_tile_attr(overworldTile _rom * tiles, u8 index, u8 mask);

void overworld_mainloop(void);

extern bool ena_obj_interactions;

#endif