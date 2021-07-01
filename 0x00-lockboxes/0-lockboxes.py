#!/usr/bin/python3
"""
You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """ Lockboxes """

    k = [0]

    if boxes is None or boxes == []:
        return False

    for v in k:
        for w in boxes[v]:
            if w not in k:
                if w < len(boxes):
                    k.append(w)

    if len(k) != len(boxes):
        return False
    return True
