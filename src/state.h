#ifndef _STATE_H
#define _STATE_H

typedef enum
{
	STARTUP,
	TITLE_SCREEN_INIT,
	TITLE_SCREEN,
	
	
	OVERWORLD_INIT,
	OVERWORLD
} STATE;

extern STATE game_state;

#define STARTUP_GAME_STATE STARTUP

#endif