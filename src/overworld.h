#ifndef _OVERWORLD_H
#define _OVERWORLD_H

#include "memory.h"

void overworld_frame_copy(void);

void draw_overworld_tile_data(void);

void draw_overworld_screen(void);

void overworld_init(void);

void advance_grey_cycle(void);

void overworld_mainloop(void);

#define player_1_x RAM_S16(0)
#define player_1_y RAM_S16(2)
#define camera_x RAM_S16(4)
#define camera_y RAM_S16(6)

#define overworld_tileset RAM_U8(8) // unsigned int overworld_tileset: 7; unsigned int grey_cycle: 1;
#define frame_counter RAM_U8(9)

#define level_width RAM_U8(10)
#define level_height RAM_U8(11)

#define movement_direction RAM_U8(12)
#define overworld_map RAM_U8(13)

#define prev_x RAM_S16(14)
#define prev_y RAM_S16(16)

#define map_ptr RAM_PTR(18)

#define movement_mode RAM_U8(21)
#define movement_counter RAM_U8(22)

#define PLAYER_1_SPRITE OAM[0]

#define CENTRE_X 0x28
#define CENTRE_Y 0x18

#endif