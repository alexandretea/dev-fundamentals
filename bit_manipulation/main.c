// C/C++ File

// Author:   Alexandre Tea <alexandre.qtea@gmail.com>
// File:     /Users/alexandretea/Work/concepts/bit_manipulation/main.c
// Purpose:  TODO (a one-line explanation)
// Created:  2017-06-05 14:52:18
// Modified: 2017-06-05 16:25:47

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "bit.h"

static void
print_int_in_binary(int nb)
{
    for (unsigned int i = 0; i < sizeof(nb) * 8; ++i) {
        printf("%d", get_bit(nb, i));
    }
}

static void
debug_var(int nb)
{
    printf("debug: "); print_int_in_binary(nb); printf("\n");
}

int
main(int argc               __attribute__ ((unused)),
     char const* argv[]     __attribute__ ((unused)))
{
    int a;

    a = 0b101010;
    debug_var(a);
    printf("access bit 0: %d\n", get_bit(a, 0));
    a = set_bit(a, 0); printf("set bit 0\n");
    debug_var(a);
    printf("--\n");
    a = 0b111111;
    debug_var(a);
    a = clear_bit(a, 4); printf("clear bit 4\n");
    debug_var(a);
    a = clear_bits_from_end(a, 1); printf("clear bits from 1 to end\n");
    debug_var(a);

    printf("--\n");
    a = 0b111111;
    debug_var(a);
    a = clear_bits_from_zero(a, 2); printf("clear bits from 0 to 2\n");
    debug_var(a);
    a = update_bit(a, 3, false); printf("update bit 3 with value 0\n");
    debug_var(a);
    a = update_bit(a, 3, true); printf("update bit 3 with value 1\n");
    debug_var(a);

    printf("--\n");
    a = 0b10000000000;
    debug_var(a);
    a = copy_bits(a, 0b10011, 2, 6);
    printf("copy 0b10011 into var at index 2\n");
    debug_var(a);
    printf("\n");
    return EXIT_SUCCESS;
}
