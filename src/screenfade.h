#ifndef _SCREENFADE_H
#define _SCREENFADE_H

#include "types.h"

#define CNT_OVERFLOW 20

typedef enum
{
    BLACK,
    WHITE
} COLOUR;

void fadeout(COLOUR fadeColour, u8 delay);

void fadein(COLOUR fadeColour, u8 delay);

#endif