#ifndef INPUT_H
#define INPUT_H

#include "types.h"

u8 read_keys(void);

bool get_key(u8 mask);

void wait_key(u8 mask);

void wait_release(u8 mask);

void wait_press(u8 mask);

#endif