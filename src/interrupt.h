#ifndef _INTERRUPT_H
#define _INTERRUPT_H

#include "types.h"

void set_default_contrast(u8 contrast);

s8 adjust_contrast(bool decrease);

void apply_default_contrast(void);

u8 get_default_contrast(void);

void set_contrast(u8 contrast);

#endif