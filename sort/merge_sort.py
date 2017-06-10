#!/usr/bin/env python

# Author:   Alexandre Tea <alexandre.qtea@gmail.com>
# File:     /Users/alexandretea/Work/concepts/sort/bubble_sort.py
# Purpose:  TODO (a one-line explanation)
# Created:  2017-06-10 18:49:20
# Modified: 2017-06-10 20:38:13

import sys


def merge_halves(a, b):
    sorted_array = []
    a_i = 0
    b_i = 0
    while a_i < len(a) and b_i < len(b):
        if a[a_i] < b[b_i]:
            sorted_array.append(a[a_i])
            a_i += 1
        else:
            sorted_array.append(b[b_i])
            b_i += 1

    # handle remainings
    if a_i < len(a):
        sorted_array.extend(a[a_i:])
    elif b_i < len(b):
        sorted_array.extend(b[b_i:])
    return sorted_array


def merge_sort(array):
    if len(array) == 1:
        return array
    split_idx = len(array) / 2

    sorted_half_a = merge_sort(array[0:split_idx])
    sorted_half_b = merge_sort(array[split_idx:])
    return merge_halves(sorted_half_a, sorted_half_b)


def main():
    if len(sys.argv) < 2:
        print("Usage: " + sys.argv[0] + "v1 v2... vn")
        return
    sorted_array = merge_sort(map(int, sys.argv[1:]))
    print(sorted_array)


if __name__ == "__main__":
    main()
