#!/usr/bin/env python

# Author:   Alexandre Tea <alexandre.qtea@gmail.com>
# File:     /Users/alexandretea/Work/concepts/sort/bubble_sort.py
# Purpose:  TODO (a one-line explanation)
# Created:  2017-06-10 18:49:20
# Modified: 2017-06-11 12:39:00

import sys


def selectionsort(array):
    for i in range(0, len(array)):
        idx_smallest = i
        for j in range(i, len(array)):
            if array[j] < array[idx_smallest]:
                idx_smallest = j
        array[i], array[idx_smallest] = array[idx_smallest], array[i]   # swap
    return array


def main():
    if len(sys.argv) < 2:
        print("Usage: " + sys.argv[0] + "v1 v2... vn")
        return
    sorted_array = selectionsort(map(int, sys.argv[1:]))
    print(sorted_array)


if __name__ == "__main__":
    main()
