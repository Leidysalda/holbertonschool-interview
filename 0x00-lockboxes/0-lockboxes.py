#!/usr/bin/python3


def canUnlockAll(boxes):
    """ Locked boxes """
    keys = [0]

    if boxes is None or boxes == []:
        return False
    for k in keys:
        for i in boxes[k]:
            if i not in keys:
                if i < len(boxes):
                    keys.append(i)
    if len(keys) != len(boxes):
        return False
    return True
