#ifndef _OVERWORLD_H
#define _OVERWORLD_H

#include "memory.h"

void overworld_frame_copy(void);

void overworld_init(void);

void advance_grey_cycle(void);

void overworld_mainloop(void);

#define player_x RAM_U8(0)
#define player_y RAM_U8(1)

#define overworld_tileset RAM_U8(2) // unsigned int overworld_tileset: 7; unsigned int grey_cycle: 1;

#endif