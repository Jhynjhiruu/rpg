#include "overworld.h"

#include <pm.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>

#include "maps.h"
#include "types.h"
#include "tiles.h"
#include "sprites.h"
#include "screenfade.h"
#include "state.h"
#include "tile_attrs.h"
#include "input.h"


Coords * player_coords;
Coords camera;

u8 overworld_tileset, frame_counter;

u8 level_width, level_height;

u8 movement_direction;
u8 overworld_map;

Coords prev;

u8 _rom * map_ptr;

u8 movement_mode;
u8 movement_counter;

#define PLAYER_1_SPRITE OAM[0]

#define CENTRE_X 0x28
#define CENTRE_Y 0x18

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
	u8 xoffs = camera.x >> 3, yoffs = camera.y >> 3;
	u16 mapindex;
	
	if(xoffs != prev.x || yoffs != prev.y)
	{
		prev.x = xoffs;
		prev.y = yoffs;
		for(i = 0, mapindex = yoffs * level_width + xoffs; i < 9; i++, mapindex += level_width)
		{
			memcpy(TILEMAP + (i << 4), map_ptr + mapindex, 13);
		}
	}
	
	PRC_SCROLL_X = camera.x & 0x07;
	PRC_SCROLL_Y = camera.y & 0x07;
	
	return;
}

void draw_overworld_screen(void)
{
	u8 i;
	
	PLAYER_1_SPRITE.x = (player_coords[0].x + 0x10) - camera.x;
	PLAYER_1_SPRITE.y = (player_coords[0].y + 0x10) - camera.y;
	
	draw_overworld_tile_data();
	
	for(i = 0; i < maps[overworld_map].numObjects; i++)
	{
		Object cur_obj = maps[overworld_map].objectData[i];
		
		OAM[23 - i].x = cur_obj.x - camera.x;
		OAM[23 - i].y = cur_obj.y - camera.y;
		
		if(cur_obj.x == player_coords[0].x + 0x10 && cur_obj.y == player_coords[0].y + 0x10)
			cur_obj.interact();
		
		if(maps[overworld_map].objectData != null)
			maps[overworld_map].objectData[i].frame();
	}
	
	return;
}

void overworld_init(void)
{
	printf("initialising overworld\n");
	
	PRC_MODE = MAP_ENABLE | MAP_16X12 | SPRITE_ENABLE | COPY_ENABLE;
	PRC_RATE = RATE_36FPS;
	
	IRQ_ENA1 |= IRQ1_PRC_COMPLETE;
    IRQ_PRI1 = PRI1_PRC(1);
	
	PLAYER_1_SPRITE.tile = 4;
	PLAYER_1_SPRITE.ctrl = OAM_ENABLE;
	
	player_coords = malloc(1 * sizeof(Coords));
	
	player_coords[0].x = 0x00;
	player_coords[0].y = 0x30;
	
	camera.x = 0;
	camera.y = 0x18;
	
	prev.x = 1;
	prev.y = 1;
	
	movement_mode = 1;
	movement_direction = 0;
	
	printf("overworld init complete\n");
	
	overworld_load(1, 1);
	
	game_state = OVERWORLD;
	
	return;
}

void overworld_load(u8 map, u8 num_players)
{
	u8 i;
	Map cur_map = maps[map];
	
	
	player_coords = realloc(player_coords, num_players * sizeof(Coords));
	
	overworld_map = map;
	
	overworld_tileset = cur_map.tileset << 1;
	
	overworld_tileset &= ~1;
	
	map_ptr = cur_map.tileData;
	
	level_width = cur_map.xsize;
	level_height = cur_map.ysize;
	
	for(i = 0; i < cur_map.numObjects; i++)
	{
		Object cur_obj = cur_map.objectData[i];
		
		OAM[23 - i].tile = cur_obj.sprite;
		OAM[23 - i].ctrl = cur_obj.sprite_attrs;
	}
	for(; i < 23; i++)
	{
		OAM[23 - i].ctrl = 0;
	}
	
	draw_overworld_screen();
	
	LCD_CTRL = 0xA4;
	
	fadein(BLACK, 2);
	
	return;
}

void overworld_mainloop(void)
{
	u8 tilemap_index = ((player_coords[0].x - camera.x) >> 3) + ((player_coords[0].y - camera.y) << 1);
	
	_rom overworldTile * attrs = tile_attrs[overworld_tileset >> 1];
	
	while(PRC_CONT != 19);
	
	if(get_key(KEY_RIGHT) && movement_mode)// && attrs[TILEMAP[tilemap_index + 2]].canWalkOn && attrs[TILEMAP[tilemap_index + 18]].canWalkOn)
	{
		movement_mode = 0;
		movement_direction = KEY_RIGHT;
	}
	
	if(get_key(KEY_LEFT) && movement_mode)// && attrs[TILEMAP[tilemap_index - 1]].canWalkOn && attrs[TILEMAP[tilemap_index + 15]].canWalkOn)
	{
		movement_mode = 0;
		movement_direction = KEY_LEFT;
	}
	
	if(get_key(KEY_UP) && movement_mode)// && attrs[TILEMAP[tilemap_index - 16]].canWalkOn && attrs[TILEMAP[tilemap_index - 15]].canWalkOn)
	{
		movement_mode = 0;
		movement_direction = KEY_UP;
	}
	
	if(get_key(KEY_DOWN) && movement_mode)// && attrs[TILEMAP[tilemap_index + 32]].canWalkOn && attrs[TILEMAP[tilemap_index + 33]].canWalkOn)
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
			
			/*if(attrs[TILEMAP[tilemap_index]].interactOnTouch)
			{
				attrs[TILEMAP[tilemap_index]].interact();
			}
			else if(attrs[TILEMAP[tilemap_index + 1]].interactOnTouch)
			{
				attrs[TILEMAP[tilemap_index + 1]].interact();
			}
			else if(attrs[TILEMAP[tilemap_index + 16]].interactOnTouch)
			{
				attrs[TILEMAP[tilemap_index + 16]].interact();
			}
			else if(attrs[TILEMAP[tilemap_index + 17]].interactOnTouch)
			{
				attrs[TILEMAP[tilemap_index + 17]].interact();
			}*/
		}
		else
		{
			if(movement_counter & 1)
			{
				switch(movement_direction)
				{
					case KEY_RIGHT:
						player_coords[0].x += 1;
						break;
					
					case KEY_LEFT:
						player_coords[0].x -= 1;
						break;
					
					case KEY_UP:
						player_coords[0].y -= 1;
						break;
					
					case KEY_DOWN:
						player_coords[0].y += 1;
						break;
				}
			}
			movement_counter += 1;
		}
	}
	
	if(player_coords[0].x - camera.x != CENTRE_X)
	{
		s16 cam_mov = player_coords[0].x - CENTRE_X;
		if(cam_mov >= 0 && cam_mov <= (level_width - 12) << 3)
			camera.x = cam_mov;
	}
	
	if(player_coords[0].y - camera.y != CENTRE_Y)
	{
		s16 cam_mov = player_coords[0].y - CENTRE_Y;
		if(cam_mov >= 0 && cam_mov <= (level_height - 8) << 3)
			camera.y = cam_mov;
	}

	draw_overworld_screen();
	
	return;
}