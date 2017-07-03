// C/C++ File

// Author:   Alexandre Tea <alexandre.qtea@gmail.com>
// File:     /Users/alexandretea/Work/concepts/numbers/swap_no_tmp.c
// Purpose:  TODO (a one-line explanation)
// Created:  2017-06-25 12:52:53
// Modified: 2017-06-25 13:05:24

#include <stdio.h>

void
swap(int* a, int* b)
{
    if (*a == *b)
        return ;
    else if (*a > *b) {
        *a = *a - *b;
        *b += *a;
        *a = *b - *a;
    } else {
        *b = *b - *a;
        *a += *b;
        *b = *a - *b;
    }
}

int
main()
{
    int b = 131;
    int a = 13;
    printf("%d %d\n", a, b);
    swap(&a, &b);
    printf("%d %d\n", a, b);
    swap(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}

