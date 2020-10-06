#include <pm.h>
#include <stdio.h>

const _rom char game_code[4] _at(0x21AC) = "RPG!";
const _rom char game_title[12] _at(0x21B0) = "Jynji & Nan!";

#include "state.h"
#include "interrupt.h"
#include "types.h"
#include "startup_anim.h"
#include "title_screen.h"
#include "overworld.h"

int main(void)
{
    game_state = STARTUP_GAME_STATE;
    
    LCD_CTRL = 0;
    
    set_default_contrast(0x1F);
    apply_default_contrast();
    
    printf("init complete\n");
    
    while(true)
    {
        switch(game_state)
        {
            
            case STARTUP:
                play_startup_anim();
                break;
                
            case TITLE_SCREEN_INIT:
                init_title_screen();
                break;
                
            case TITLE_SCREEN:
                display_title_screen();
                break;
                
            case OVERWORLD_INIT:
                overworld_init();
                break;
                
            case OVERWORLD:
                overworld_mainloop();
                break;
            
        }
        
        
    }
}
