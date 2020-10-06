#include "title_screen.h"

#include <pm.h>
#include <stdio.h>

#include "types.h"
#include "state.h"
#include "7colour_screens.h"
#include "screenfade.h"
#include "input.h"

volatile uint8_t _rom * screen_ptr;

volatile uint16_t index = 0;

void copy_image_gddram(int ptr);

void title_screen_timer_2h(void)
{
	TMR2_CTRL_L &= ~(TMR_RESET | TMR_ENABLE);
	copy_image_gddram(*((u8 *)(&screen_ptr) + 1)); // godawful hack to get the upper 2 bytes of the pointer into BA
	TMR2_CTRL_L |= (TMR_RESET | TMR_ENABLE);
	
	screen_ptr = screens[0] + index;
	if((index += 0x300) >= SCREENS_LEN * 0x300) index = 0;
	
	return;
}

void init_title_screen(void)
{
	printf("initialising title screen\n");
	
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
	
	printf("starting title screen\n");
	
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
		
		printf("exiting title screen\n");
		
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