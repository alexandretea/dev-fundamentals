#!/usr/bin/env python

# Author:   Alexandre Tea <alexandre.qtea@gmail.com>
# File:     /Users/alexandretea/Work/concepts/dynamic_programming/staircase.py
# Purpose:  TODO (a one-line explanation)
# Created:  2017-06-06 17:17:11
# Modified: 2017-06-06 17:51:16

import sys

__doc__ = """
Triple step
--
A child is running up a staircase with n steps and can hop either 1 step,
2 steps or 3 steps at a time. Implement a method to count how many possible
ways the child can run up the stairs."""

cache = {
    1: 1,
    2: 2,
    3: 3
}


def triple_step(nb_steps):
    if nb_steps not in cache:
        print("[debug] call: triple_step(" + str(nb_steps) + ")")
        cache[nb_steps] = (triple_step(nb_steps - 1) +
                           triple_step(nb_steps - 2) +
                           triple_step(nb_steps - 3))
    return cache[nb_steps]


def main():
    nb_steps = 0

    if len(sys.argv) < 2:
        print("Usage: " + sys.argv[0] + " nb_steps")
        print(__doc__)
        return
    nb_steps = int(sys.argv[1])
    if nb_steps < 1:
        print("Argument 'nb_steps' cannot be inferor to 1")
        return

    print(triple_step(nb_steps))


if __name__ == "__main__":
    main()
