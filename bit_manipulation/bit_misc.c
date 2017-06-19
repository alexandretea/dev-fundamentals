// C/C++ File

// Author:   Alexandre Tea <alexandre.qtea@gmail.com>
// File:     /Users/alexandretea/Work/concepts/bit_manipulation/bit_misc.c
// Purpose:  TODO (a one-line explanation)
// Created:  2017-06-05 15:09:18
// Modified: 2017-06-19 14:40:35

#include <stddef.h>
#include "bit.h"

static void // debug
print_int_in_binary(int nb)
{
    for (unsigned int i = 0; i < sizeof(nb) * 8; ++i) {
        printf("%d", get_bit(nb, i));
    }
    printf("\n");
}


int
copy_bits(int dest, int src, int idx_start, int idx_end)
{
    int mask = ~0;

    // clear range of bits from dest
    mask <<= (idx_end + 1); // + 1 bc inclusive copy
    mask |= (~(~0 << (idx_start)));

    // copy src bits through mask
    src <<= idx_start;
    return (dest & mask) | src;
}

unsigned int
count_set_bits(int nb)
{
    unsigned int count = 0;

    while (nb) {
        nb = nb & (nb - 1); // clear LSB
        ++count;
    }
    return count;
}
