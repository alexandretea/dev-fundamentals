#!/usr/bin/env python

# Author:   Alexandre Tea <alexandre.qtea@gmail.com>
# File:     /Users/alexandretea/Work/concepts/sort/radixsort.py
# Purpose:  TODO (a one-line explanation)
# Created:  2017-06-18 11:52:51
# Modified: 2017-06-18 13:49:45

import sys


def get_nb_digit(nb, idx):
    s = str(nb)
    s = s[::-1]     # to_string + reverse string
    if idx > len(s) - 1:
        return 0
    return int(s[idx])


def join_lists(lists):
    res = []
    for l in lists:
        res += l
    return res


def radixsort(values):
    if len(values) == 0:
        return values

    max_len = len(str(max(values)))

    for i in range(0, max_len):
        buckets = [[] for x in range(10)]

        for v in values:
            buckets[get_nb_digit(v, i)].append(v)
            values = join_lists(buckets)
    return values


def main():
    if len(sys.argv) < 2:
        print("Usage: " + sys.argv[0] + "v1 v2... vn")
        return
    sorted_list = radixsort(map(int, sys.argv[1:]))
    print(sorted_list)


if __name__ == "__main__":
    main()
