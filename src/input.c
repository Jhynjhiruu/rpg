#include "input.h"

#include <pm.h>

#include "types.h"

u8 read_keys(void)
{
    u8 read1, read2;
    
    while(true)
    {
        read1 = KEY_PAD;
        read2 = KEY_PAD;
        if(!(read1 ^ read2)) break;
    }
    return read1 ^ 0xFF;
}

bool get_key(u8 mask)
{
    return (read_keys() & mask) ? true : false;
}

void wait_key(u8 mask)
{
    while(!get_key(mask));
}

void wait_release(u8 mask)
{
    while(get_key(mask));
}

void wait_press(u8 mask)
{
    wait_key(mask);
    wait_release(mask);
}