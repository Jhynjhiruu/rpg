#include "title_screen.h"

#include <pm.h>

#include "types.h"
#include "state.h"
#include "7colour_screens.h"
#include "debug.h"
#include "screenfade.h"
#include "input.h"

volatile uint8_t * screen_ptr _at(0x14E4);

void title_screen_timer_2h(void) {
	
#pragma asm
	PUSH ALE
	
	EXTERN _copy_image_gddram	; copy_image.asm
	
	AND [BR:38h], #~6
	
	LD BA, [_screen_ptr + 1]
    CARL _copy_image_gddram
	
	OR [BR:38h], #6
#pragma endasm

	screen_ptr = screens[0] + index;
	if((index += 0x300) >= SCREENS_LEN * 0x300) index = 0;
	
#pragma asm
	POP ALE
#pragma endasm
	
	return;
}

void init_title_screen(void)
{
	dprintf("initialising title screen");
	
	PRC_MODE = 0;
	
	// enable power button
	IRQ_ENA3 = IRQ3_KEYPOWER;
	IRQ_PRI2 = PRI2_KEY(3);
	
	// configure timer 2
	TMR1_OSC = 0x20; // enable osc1
	TMR2_SCALE = 0x8 | CLK_CPU_2MHZ;
	TMR2_OSC = 0x00;
	// (free_time / total_time) * 2000000 / 72; currently arount 70%
	TMR2_PRE = 19400;
	TMR2_CTRL_L = 0x86;
	
	// enable timer 2
	IRQ_ENA1 = IRQ1_TIM2_HI_UF;
	IRQ_PRI1 = PRI1_TIM2(2);
	//flag = 0;
	
	dprintf("starting title screen");
	
	game_state = TITLE_SCREEN;
}

void end_title_screen(void)
{
	IRQ_ENA1 = 0;
	IRQ_PRI1 = 0;
}

void display_title_screen(void)
{
	if(get_key(KEY_A) && get_key(KEY_A))
	{
		u8 i;
		
		dprintf("exiting title screen");
		
		while(get_key(KEY_A));
		fadeout(BLACK, 2);
		end_title_screen();
		
		LCD_CTRL = 0xA5;
		
		for(i = 0; i < 144; i++)
			while(PRC_CONT != CNT_OVERFLOW);
		
		game_state = OVERWORLD_INIT;
	}
	
	return;
}