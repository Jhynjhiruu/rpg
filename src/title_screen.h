#ifndef _TITLE_SCREEN_H
#define _TITLE_SCREEN_H

#include "memory.h"

void title_screen_timer_2h(void);

void init_title_screen(void);

void end_title_screen(void);

void display_title_screen(void);

#define index RAM_U16(0)

#endif