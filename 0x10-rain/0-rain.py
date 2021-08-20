#!/usr/bin/python3
""" Rain
"""


def rain(walls):
    """ Calculate how many square units of water will be retained after
    it rains.
    """
    l = len(walls)
    water = 0

    for i in range(1, l - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]

        for j in range(i + 1, l):
            right = max(right, walls[j])

        water = water + (min(left, right) - walls[i])
    return water
