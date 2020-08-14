#include "overworld.h"

#include <pm.h>
#include <string.h>

#include "maps.h"
#include "types.h"
#include "tiles.h"
#include "sprites.h"
#include "debug.h"
#include "screenfade.h"
#include "state.h"
#include "tile_attrs.h"
#include "input.h"

void overworld_frame_copy(void)
{
	overworld_tileset ^= _BV(0);
	PRC_MAP = tiles[overworld_tileset >> 1][overworld_tileset & 1];
	PRC_SPR = sprites[overworld_tileset & 1];
	return;
}

void draw_overworld_tile_data(void)
{
	u8 i;
	u8 xoffs = camera_x >> 3, yoffs = camera_y >> 3;
	u16 mapindex;
	&i;
	&xoffs;
	&yoffs;
	&mapindex;
	
	if(xoffs != prev_x || yoffs != prev_y)
	{
		prev_x = xoffs;
		prev_y = yoffs;
		for(i = 0, mapindex = yoffs * level_width + xoffs; i < 9; i++, mapindex += level_width)
		{
			memcpy(TILEMAP + (i << 4), map_ptr + mapindex, 13);
		}
	}
	
	PRC_SCROLL_X = camera_x & 0x07;
	PRC_SCROLL_Y = camera_y & 0x07;
}

void draw_overworld_screen(void)
{
	PLAYER_1_SPRITE.x = (player_1_x + 0x10) - camera_x;
	PLAYER_1_SPRITE.y = (player_1_y + 0x10) - camera_y;
	
	draw_overworld_tile_data();
}

void overworld_init(void)
{
	u8 i;
	&i; // stuff breaks if this is missing for some reason
	
	dprintf("initialising overworld");
	
	PRC_MODE = MAP_ENABLE | MAP_16X12 | SPRITE_ENABLE | COPY_ENABLE;
	PRC_RATE = RATE_36FPS;
	
	IRQ_ENA1 |= IRQ1_PRC_COMPLETE;
    IRQ_PRI1 = PRI1_PRC(1);
	
	overworld_tileset &= ~1;
	
	overworld_map = 0;
	
	map_ptr = maps[overworld_map].tileData;
	
	level_width = maps[0].xsize;
	level_height = maps[0].ysize;
	
	dprintf("%d", level_width);	
	
	PLAYER_1_SPRITE.tile = 0;
	PLAYER_1_SPRITE.ctrl = OAM_ENABLE;
	
	player_1_x = 0x10;
	player_1_y = 0x30;
	
	camera_x = 0;
	camera_y = 0;
	
	prev_x = 1;
	prev_y = 1;
	
	movement_mode = 0;
	movement_direction = 0;
	
	LCD_CTRL = 0xA4;
	
	dprintf("overworld init complete");
	
	fadein(BLACK, 2);
	
	game_state = OVERWORLD;
	return;
}

void overworld_mainloop(void)
{
	u8 tilemap_index = ((player_1_x - camera_x) >> 3) + ((player_1_y - camera_y) << 1);
	
	overworldTile * attrs = tile_attrs[overworld_tileset >> 1];
	
	while(PRC_CONT != 19);
	
	
	
	
	if(get_key(KEY_RIGHT) && movement_mode && attrs[TILEMAP[tilemap_index + 2]].canWalkOn && attrs[TILEMAP[tilemap_index + 18]].canWalkOn)
	{
		movement_mode = 0;
		movement_direction = KEY_RIGHT;
	}
	
	if(get_key(KEY_LEFT) && movement_mode && attrs[TILEMAP[tilemap_index - 1]].canWalkOn && attrs[TILEMAP[tilemap_index + 15]].canWalkOn)
	{
		movement_mode = 0;
		movement_direction = KEY_LEFT;
	}
	
	if(get_key(KEY_UP) && movement_mode && attrs[TILEMAP[tilemap_index - 16]].canWalkOn && attrs[TILEMAP[tilemap_index - 15]].canWalkOn)
	{
		movement_mode = 0;
		movement_direction = KEY_UP;
	}
	
	if(get_key(KEY_DOWN) && movement_mode && attrs[TILEMAP[tilemap_index + 32]].canWalkOn && attrs[TILEMAP[tilemap_index + 33]].canWalkOn)
	{
		movement_mode = 0;
		movement_direction = KEY_DOWN;
	}
	
	if(!movement_mode)
	{
		if(movement_counter > 15)
		{
			movement_mode = 1;
			movement_counter = 0;
		}
		else
		{
			if(movement_counter & 1)
			{
				switch(movement_direction)
				{
					case KEY_RIGHT:
						player_1_x += 1;
						break;
					
					case KEY_LEFT:
						player_1_x -= 1;
						break;
					
					case KEY_UP:
						player_1_y -= 1;
						break;
					
					case KEY_DOWN:
						player_1_y += 1;
						break;
				}
			}
			movement_counter += 1;
		}
	}
	
	if(player_1_x - camera_x != CENTRE_X)
	{
		s16 cam_mov = player_1_x - CENTRE_X;
		if(cam_mov >= 0 && cam_mov <= (level_width - 12) << 3)
			camera_x = cam_mov;
	}
	
	if(player_1_y - camera_y != CENTRE_Y)
	{
		s16 cam_mov = player_1_y - CENTRE_Y;
		if(cam_mov >= 0 && cam_mov <= (level_height - 8) << 3)
			camera_y = cam_mov;
	}



	draw_overworld_screen();
	




	
	return;
}