#!/usr/bin/env python

# Author:   Alexandre Tea <alexandre.qtea@gmail.com>
# File:     /Users/alexandretea/Work/concepts/dynamic_programming/powerset.py
# Purpose:  TODO (a one-line explanation)
# Created:  2017-06-06 22:53:38
# Modified: 2017-06-07 12:19:27

import sys

__doc__ = """
Recursive Multiply
--
Write a recursive function to multiply two positive integers without using
the * operator. You can use addition, subtraction, bit shifting, but you should
minimise the number of those operations."""


# Time complexity: O(log(n))
def recursive_multiply(a, b):
    multiplier = min(a, b)
    nb = max(a, b)
    if multiplier == 1:
        return nb
    elif multiplier % 2 != 0:
        res = recursive_multiply(nb, multiplier >> 1)
        return res + res + nb
    res = recursive_multiply(nb, multiplier >> 1)
    return res + res


def main():
    if len(sys.argv) < 3:
        print("Usage: " + sys.argv[0] + " nb1 nb2")
        print(__doc__)
        return
    print(recursive_multiply(int(sys.argv[1]), int(sys.argv[2])))

if __name__ == "__main__":
    main()
