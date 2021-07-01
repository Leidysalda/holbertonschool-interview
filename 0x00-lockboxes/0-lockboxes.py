#!/usr/bin/python3


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
