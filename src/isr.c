#include <pm.h>

#include "state.h"
#include "title_screen.h"
#include "overworld.h"

void _interrupt(6) prc_frame_copy_irq(void) {
    IRQ_ACT1 |= IRQ1_PRC_COMPLETE;
    switch(game_state)
    {
        case OVERWORLD_INIT:
        case OVERWORLD:
            overworld_frame_copy();
            break;
        
        default:
            break;        
    }
}
void _interrupt(0) prc_render_irq(void) {
    _slp();
}
void _interrupt(10) timer_2h_underflow_irq(void) {
    IRQ_ACT1 |= IRQ1_TIM2_HI_UF;
    switch(game_state)
    {
        case TITLE_SCREEN:
            title_screen_timer_2h();
            break;
        
        default:
            break;        
    }
}
void _interrupt(0) timer_2l_underflow_irq(void) {
    _slp();
}
void _interrupt(0) timer_1h_underflow_irq(void) {
    _slp();
}
void _interrupt(0) timer_1l_underflow_irq(void) {
    _slp();
}
void _interrupt(0) timer_3h_underflow_irq(void) {
    _slp();
}
void _interrupt(0) timer_3_cmp_irq(void) {
    _slp();
}
void _interrupt(0) timer_32hz_irq(void) {
    _slp();
}
void _interrupt(24) timer_8hz_irq(void) {
    IRQ_ACT2 |= IRQ2_8HZ;
    switch(game_state)
    {
        case OVERWORLD_INIT:
        case OVERWORLD:
            overworld_8hz_timer();
            break;
        
        default:
            break;        
    }
}
void _interrupt(0) timer_2hz_irq(void) {
    _slp();
}
void _interrupt(0) timer_1hz_irq(void) {
    _slp();
}
void _interrupt(0) ir_rx_irq(void) {
    _slp();
}
void _interrupt(0) shake_irq(void) {
    _slp();
}
void _interrupt(38) key_power_irq(void) {
    IRQ_ACT3 = IRQ3_KEYPOWER;
    if (KEY_PAD & KEY_POWER) return;
    _int(0x48);
}
void _interrupt(0) key_right_irq(void) {
    _slp();
}
void _interrupt(0) key_left_irq(void) {
    _slp();
}
void _interrupt(0) key_down_irq(void) {
    _slp();
}
void _interrupt(0) key_up_irq(void) {
    _slp();
}
void _interrupt(0) key_c_irq(void) {
    _slp();
}
void _interrupt(0) key_b_irq(void) {
    _slp();
}
void _interrupt(0) key_a_irq(void) {
    _slp();
}
void _interrupt(0) unknown_irq(void) {
    _slp();
}
void _interrupt(0) cartridge_irq(void) {
    _slp();
}

void _exit(void)
{
    _int(0x48);
}
