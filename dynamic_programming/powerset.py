#!/usr/bin/env python

# Author:   Alexandre Tea <alexandre.qtea@gmail.com>
# File:     /Users/alexandretea/Work/concepts/dynamic_programming/powerset.py
# Purpose:  TODO (a one-line explanation)
# Created:  2017-06-06 22:53:38
# Modified: 2017-06-06 23:39:23

from sets import Set
import sys

__doc__ = """
Power set
--
Write a method to return all subsets of a set."""


# Time complexity: O(n2^n)
def powerset(s):
    if len(s) == 1:
        return [set(s)]
    elem = set([s.pop()])
    subsets = powerset(s)
    tmp = [subset | elem for subset in subsets]
    return subsets + tmp + [elem]


def main():
    if len(sys.argv) < 2:
        print("Usage: " + sys.argv[0] + " v2 v3... vn")
        print(__doc__)
        return
    subsets = powerset(Set(map(int, sys.argv[1:])))
    for s in subsets:
        print(s)

if __name__ == "__main__":
    main()
