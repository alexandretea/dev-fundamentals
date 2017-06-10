// C/C++ File

// Author:   Alexandre Tea <alexandre.qtea@gmail.com>
// File:     /Users/alexandretea/Work/concepts/bit_tasks.c
// Purpose:  TODO (a one-line explanation)
// Created:  2017-06-05 12:48:37
// Modified: 2017-06-05 15:52:25

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "bit.h"

/*
** Bit basic operations
** - Get
** - Set
** - Clear (one bit, range of bits)
** - Update
*/
bool
get_bit(int nb, unsigned int idx)
{
    return (nb & (1 << idx)) != 0;
}

int
set_bit(int nb, unsigned int idx)
{
    return nb | (1 << idx);
}

int
clear_bit(int nb, unsigned int idx)
{
    return nb & ~(1 << idx);
}

int
clear_bits_from_end(int nb, unsigned int idx)
{
    // cast into unsigned int to force logical shift instead of arithmetic
    return nb & ((unsigned int)(~0) >> (BIT_SIZEOF(nb) - idx));
}

int
clear_bits_from_zero(int nb, unsigned int idx)
{
    // cast into unsigned int to force logical shift instead of arithmetic
    return nb & (~0 << idx);
}

int
update_bit(int nb, unsigned int idx, bool value)
{
    int mask = ~(1 << idx);

    //      clear bit    set bit (if 0, no changes, if 1, set bit)
    return (nb & mask) | (value << idx);
}
