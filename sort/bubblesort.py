#!/usr/bin/env python

# Author:   Alexandre Tea <alexandre.qtea@gmail.com>
# File:     /Users/alexandretea/Work/concepts/sort/bubble_sort.py
# Purpose:  TODO (a one-line explanation)
# Created:  2017-06-10 18:49:20
# Modified: 2017-06-17 13:22:44

import sys


def bubblesort(array):
    done = False

    while not done:
        done = True
        for i, v in enumerate(array):
            if i + 1 < len(array) and v > array[i + 1]:
                array[i], array[i + 1] = array[i + 1], array[i]     # swap
                done = False
    return array


def main():
    if len(sys.argv) < 2:
        print("Usage: " + sys.argv[0] + "v1 v2... vn")
        return
    sorted_array = bubblesort(map(int, sys.argv[1:]))
    print(sorted_array)


if __name__ == "__main__":
    main()
