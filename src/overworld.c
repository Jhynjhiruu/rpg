#include "overworld.h"

#include <pm.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>

#include "maps.h"
#include "types.h"
#include "sprite_names.h"
#include "tiles.h"
#include "sprites.h"
#include "screenfade.h"
#include "state.h"
#include "tile_attrs.h"
#include "input.h"


Coords * player_coords;
Coords camera;

u8 overworld_tileset, anim_counter, frame_counter;

u8 level_width, level_height;

Object * objects;

u8 movement_direction;
u8 overworld_map;

Coords prev;

u8 _rom * map_ptr;

u8 movement_mode;
u8 movement_counter;

bool ena_obj_interactions;

#define PLAYER_1_SPRITE OAM[0]

#define CENTRE_X 0x28
#define CENTRE_Y 0x18

#define RESERVED_SPRITES 1

void overworld_frame_copy(void)
{
    overworld_tileset ^= _BV(0);
    PRC_MAP = tiles[(overworld_tileset >> 1) + anim_counter][overworld_tileset & 1];
    PRC_SPR = sprites[overworld_tileset & 1];
    
    return;
}

void overworld_8hz_timer(void)
{
    if(++frame_counter >= maps[overworld_map].frame_delay)
    {
        frame_counter = 0;
        if(++anim_counter >= maps[overworld_map].anim_frames)
        {
            anim_counter = 0;
        }
    }
}

void draw_overworld_tile_data(void)
{
    u8 i;
    u8 xoffs = camera.x >> 3, yoffs = camera.y >> 3;
    u16 mapindex;
    
    PRC_SCROLL_X = camera.x & 0x07;
    PRC_SCROLL_Y = camera.y & 0x07;
    
    if(xoffs != prev.x || yoffs != prev.y)
    {
        prev.x = xoffs;
        prev.y = yoffs;
        for(i = 0, mapindex = yoffs * level_width + xoffs; i < 9; i++, mapindex += level_width)
        {
            memcpy(TILEMAP + (i << 4), map_ptr + mapindex, 13);
        }
    }
    
    return;
}

void draw_overworld_screen(void)
{
    u8 i, used_sprites = 0;
    
    draw_overworld_tile_data();
    
    PLAYER_1_SPRITE.x = (player_coords[0].x + 0x10) - camera.x;
    PLAYER_1_SPRITE.y = (player_coords[0].y + 0x10) - camera.y;
    
    for(i = 0; i < maps[overworld_map].numObjects; i++)
    {
        Object cur_obj = objects[i];
        
        if(cur_obj.sprite_attrs)
        {
            OAM[23 - used_sprites].x = cur_obj.x - camera.x;
            OAM[23 - used_sprites].y = cur_obj.y - camera.y;
            
            used_sprites++;
        }
        
        if(cur_obj.x == player_coords[0].x + 0x10 && cur_obj.y == player_coords[0].y + 0x10 && ena_obj_interactions)
            cur_obj.interact();
        
        if(objects != null)
            objects[i].frame();
    }
    
    return;
}

void overworld_init(void)
{
    //printf("initialising overworld\n");
    
    PRC_MODE = MAP_ENABLE | MAP_16X12 | SPRITE_ENABLE | COPY_ENABLE;
    PRC_RATE = RATE_36FPS;
    
    IRQ_ENA1 |= IRQ1_PRC_COMPLETE;
    IRQ_PRI1 = PRI1_PRC(3);
    
    PLAYER_1_SPRITE.tile = IDLE;
    PLAYER_1_SPRITE.ctrl = OAM_ENABLE;
    
    player_coords = malloc(1 * sizeof(Coords));
    
    objects = malloc(sizeof(Object));
    
    player_coords[0].x = 0x00;
    player_coords[0].y = 0x30;
    
    camera.x = 0;
    camera.y = 0x18;
    
    prev.x = 1;
    prev.y = 1;
    
    movement_mode = 1;
    movement_direction = 0;
    
    //printf("overworld init complete\n");
    
    overworld_load(1, 1);
    
    game_state = OVERWORLD;
    
    return;
}

void overworld_load(u8 map, u8 num_players)
{
    u8 i;
    Map cur_map = maps[map];
    u8 used_sprites = 0;
    
    
    anim_counter = 0;
    ena_obj_interactions = true;
    
    player_coords = realloc(player_coords, num_players * sizeof(Coords));
    
    overworld_map = map;
    
    overworld_tileset = cur_map.tileset << 1;
    
    overworld_tileset &= ~1;
    
    map_ptr = cur_map.tileData;
    
    level_width = cur_map.xsize;
    level_height = cur_map.ysize;
    
    objects = realloc(objects, cur_map.numObjects * sizeof(Object));
    
    if(objects != null)
    {
        memcpy(objects, cur_map.objectData, cur_map.numObjects * sizeof(Object));
        
        for(i = 0; i < cur_map.numObjects; i++)
        {
            Object cur_obj = objects[i];
            
            if(cur_obj.sprite_attrs)
            {
                OAM[23 - used_sprites].tile = cur_obj.sprite;
                OAM[23 - used_sprites].ctrl = cur_obj.sprite_attrs;
                
                used_sprites++;
            }
        }
    }
    
    for(; used_sprites < 24 - RESERVED_SPRITES; used_sprites++)
    {
        OAM[23 - used_sprites].ctrl = 0;
    }
    
    if(cur_map.frame_delay)
    {
        IRQ_ENA2 = IRQ2_8HZ;
        TMR256_CTRL |= 1;
        IRQ_PRI2 = PRI2_TIM256(1);
    }
    else
    {
        IRQ_ENA2 = 0;
        TMR256_CTRL = 0;
    }
	
    draw_overworld_screen();
    
    LCD_CTRL = 0xA4;
    
    fadein(BLACK, 2);
    
    return;
}

void overworld_mainloop(void)
{
    u8 tilemap_index = ((player_coords[0].x - camera.x) >> 3) + ((player_coords[0].y - camera.y) << 1);
    
    overworldTile _rom * attrs = tile_attrs[overworld_tileset >> 1];
    
    //u16 count = 0;
    
    /**(u16 *)0x20D4 = count;
    *(char *)0x20D0 = '\n';*/
    
    if(get_key(KEY_RIGHT) && movement_mode)
    {
        PLAYER_1_SPRITE.tile &= ~DIRS;
        PLAYER_1_SPRITE.tile |= RIGHT;
        if(movement_mode == 1)
            movement_mode = 2;
        else if(movement_mode == 2)
            movement_mode = 3;
        else if(movement_mode == 3 && check_tile_attr(attrs, tilemap_index + 2, CanWalkOn) && check_tile_attr(attrs, tilemap_index + 18, CanWalkOn))
        {
            movement_mode = 0;
            movement_direction = KEY_RIGHT;
            PLAYER_1_SPRITE.tile &= ~IDLE;
        }
        else
        {
            movement_mode = 1;
            PLAYER_1_SPRITE.tile &= ~FRAME;
            PLAYER_1_SPRITE.tile |= IDLE;
        }
    }
    else if(get_key(KEY_LEFT) && movement_mode)
    {
        PLAYER_1_SPRITE.tile &= ~DIRS;
        PLAYER_1_SPRITE.tile |= LEFT;
        if(movement_mode == 1)
            movement_mode = 2;
        else if(movement_mode == 2)
            movement_mode = 3;
        else if(movement_mode == 3 && check_tile_attr(attrs, tilemap_index - 1, CanWalkOn) && check_tile_attr(attrs, tilemap_index + 15, CanWalkOn))
        {
            movement_mode = 0;
            movement_direction = KEY_LEFT;
            PLAYER_1_SPRITE.tile &= ~IDLE;
        }
        else
        {
            movement_mode = 1;
            PLAYER_1_SPRITE.tile &= ~FRAME;
            PLAYER_1_SPRITE.tile |= IDLE;
        }
    }
    
    if(get_key(KEY_UP) && movement_mode)
    {
        PLAYER_1_SPRITE.tile &= ~DIRS;
        PLAYER_1_SPRITE.tile |= UP;
        if(movement_mode == 1)
            movement_mode = 2;
        else if(movement_mode == 2)
            movement_mode = 3;
        else if(movement_mode == 3 && check_tile_attr(attrs, tilemap_index - 16, CanWalkOn) && check_tile_attr(attrs, tilemap_index - 15, CanWalkOn))
        {
            movement_mode = 0;
            movement_direction = KEY_UP;
            PLAYER_1_SPRITE.tile &= ~IDLE;
        }
        else
        {
            movement_mode = 1;
            PLAYER_1_SPRITE.tile &= ~FRAME;
            PLAYER_1_SPRITE.tile |= IDLE;
        }
    }
    else if(get_key(KEY_DOWN) && movement_mode)
    {
        PLAYER_1_SPRITE.tile &= ~DIRS;
        PLAYER_1_SPRITE.tile |= DOWN;
        if(movement_mode == 1)
            movement_mode = 2;
        else if(movement_mode == 2)
            movement_mode = 3;
        else if(movement_mode == 3 && check_tile_attr(attrs, tilemap_index + 32, CanWalkOn) && check_tile_attr(attrs, tilemap_index + 33, CanWalkOn))
        {
            movement_mode = 0;
            movement_direction = KEY_DOWN;
            PLAYER_1_SPRITE.tile &= ~IDLE;
        }
        else
        {
            movement_mode = 1;
            PLAYER_1_SPRITE.tile &= ~FRAME;
            PLAYER_1_SPRITE.tile |= IDLE;
        }
    }
    
    if(movement_mode && !get_key(KEY_RIGHT | KEY_LEFT | KEY_UP | KEY_DOWN))
    {
        movement_mode = 1;
        PLAYER_1_SPRITE.tile &= ~FRAME;
        PLAYER_1_SPRITE.tile |= IDLE;
    }
    
    if(!movement_mode)
    {
        if(movement_counter > 15)
        {
            movement_mode = 3;
            movement_counter = 0;
            
            if(check_tile_attr(attrs, tilemap_index, InteractOnTouch))
            {
                attrs[TILEMAP[tilemap_index]].interact();
            }
            else if(check_tile_attr(attrs, tilemap_index + 1, InteractOnTouch))
            {
                attrs[TILEMAP[tilemap_index + 1]].interact();
            }
            else if(check_tile_attr(attrs, tilemap_index + 16, InteractOnTouch))
            {
                attrs[TILEMAP[tilemap_index + 16]].interact();
            }
            else if(check_tile_attr(attrs, tilemap_index + 17, InteractOnTouch))
            {
                attrs[TILEMAP[tilemap_index + 17]].interact();
            }
        }
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
        if(!(movement_counter & 7))
        {
            PLAYER_1_SPRITE.tile = (PLAYER_1_SPRITE.tile & ~WALK3) | ((PLAYER_1_SPRITE.tile + WALK1) & WALK3);
        }
        movement_counter += 1;
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
    
    while(PRC_CONT != 19);// count++;
    
    return;
}