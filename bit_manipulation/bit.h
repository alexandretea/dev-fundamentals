// C/C++ File

// Author:   Alexandre Tea <alexandre.qtea@gmail.com>
// File:     /Users/alexandretea/Work/concepts/bit_manipulation/bit.h
// Purpose:  TODO (a one-line explanation)
// Created:  2017-06-05 14:52:59
// Modified: 2017-06-19 13:28:25

#ifndef BIT_H
#define BIT_H

#include <stdbool.h>

#define BIT_SIZEOF(x)   (sizeof(x) * 8)

// basic operations
bool    get_bit(int nb, unsigned int idx);
int     set_bit(int nb, unsigned int idx);
int     clear_bit(int nb, unsigned int idx);
int     clear_bits_from_end(int nb, unsigned int idx);
int     clear_bits_from_zero(int nb, unsigned int idx);
int     update_bit(int nb, unsigned int idx, bool value);

// utils
int             copy_bits(int dest, int src, int idx_start, int idx_end);
unsigned int    count_set_bits(int nb);

#endif /* end of include guard: BIT_H */
