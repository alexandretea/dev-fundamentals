#!/usr/bin/env python

# Author:   Alexandre Tea <alexandre.qtea@gmail.com>
# File:     /Users/alexandretea/Work/concepts/sort/bubble_sort.py
# Purpose:  TODO (a one-line explanation)
# Created:  2017-06-10 18:49:20
# Modified: 2017-06-11 12:21:32

import sys


def partition(array, start, end):
    pivot = array[(start + end) / 2]

    while True:
        i = start
        j = end

        while array[i] < pivot:
            i += 1
        while array[j] > pivot:
            j -= 1

        if j <= i:
            return j
        else:
            array[i], array[j] = array[j], array[i]  # swap


def rec_quicksort(array, start, end):
    if end - start > 1:
        pivot_i = partition(array, start, end)

        rec_quicksort(array, start, pivot_i)
        rec_quicksort(array, pivot_i, end)


def quicksort(array):
    rec_quicksort(array, 0, len(array) - 1)
    return array


def main():
    if len(sys.argv) < 2:
        print("Usage: " + sys.argv[0] + "v1 v2... vn")
        return
    sorted_array = quicksort(map(int, sys.argv[1:]))
    print(sorted_array)


if __name__ == "__main__":
    main()
