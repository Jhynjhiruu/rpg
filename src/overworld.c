#include "overworld.h"

#include <pm.h>

#include "types.h"
#include "tiles.h"
#include "debug.h"
#include "screenfade.h"
#include "state.h"

void overworld_frame_copy(void)
{
	overworld_tileset ^= _BV(0);
	PRC_MAP = tiles[overworld_tileset >> 1][overworld_tileset & 1];
	return;
}

void overworld_init(void)
{
	u8 i;
	&i; // stuff breaks if this is missing for some reason
	
	PRC_MODE = MAP_ENABLE | MAP_16X12 | SPRITE_ENABLE | COPY_ENABLE;
	PRC_RATE = RATE_36FPS;
	
	IRQ_ENA1 |= IRQ1_PRC_COMPLETE;
    IRQ_PRI1 = PRI1_PRC(1);
	
	overworld_tileset &= ~1;
	
	PRC_SCROLL_X = 0x10;
	PRC_SCROLL_Y = 0x10;
	
	for(i = 0; i < 0xC0; i++)
		TILEMAP[i] = 0;
	
	player_x = 0x80;
	player_y = 0x80;
	
	LCD_CTRL = 0xA4;
	
	fadein(BLACK, 2);
	
	game_state = OVERWORLD;
	return;
}

void overworld_mainloop(void)
{
	wait_vsync();
	return;
}