#include "screenfade.h"

#include "types.h"
#include "interrupt.h"
#include "state.h"
#include "debug.h"

void fadeout(COLOUR fadeColour, u8 delay)
{
	u8 i, j;
	
	fadeColour ^= 1;
	
	for(i = 0; i < get_default_contrast(); i++)
	{
		for(j = 0; j < delay; j++)
		{
			while(PRC_CONT != CNT_OVERFLOW);
			while(PRC_CONT == CNT_OVERFLOW);
		}
		
		adjust_contrast(fadeColour);
	}
	set_contrast(fadeColour * 0x3F);
}

void fadein(COLOUR fadeColour, u8 delay)
{
	u8 i, j;
	
	for(i = 0; i < get_default_contrast(); i++)
	{
		for(j = 0; j < delay; j++)
		{
			while(PRC_CONT != CNT_OVERFLOW);
			while(PRC_CONT == CNT_OVERFLOW);
		}
		
		adjust_contrast(fadeColour);
	}
	apply_default_contrast();
}