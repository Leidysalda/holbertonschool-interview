#!/usr/bin/python3
"""
method that determines if a given data set represents a valid UTF-8 encoding.
"""


def validation(data, number, bytes):
    """
    Validation list
    """

    list_tmp = []
    try:
        for x in range(bytes):
            list_tmp.append(
                int("{0:b}".format((data[number + (x + 1)] & 255) >> 6)))

        for val in list_tmp:
            if val != 10:
                return(0)
        return(bytes)
    except IndexError:
        return(-1)


def validUTF8(data):
    """
    Validate UTF - 8
    """

    step = 0

    for num in range(len(data)):
        if step:
            step -= 1
            continue

        tmp_num = data[num] & 255
        tmp = tmp_num >> 7

        if (int("{0:b}".format(tmp)) == 0):
            continue

        tmp = tmp_num >> 5
        if (int("{0:b}".format(tmp)) == 110):
            step = validation(data, num, 1)
            if step == -1 or step == 0:
                return("False")
            continue

        tmp = tmp_num >> 4
        if (int("{0:b}".format(tmp)) == 1110):
            step = validation(data, num, 2)
            if step == -1 or step == 0:
                return("False")
            continue

        tmp = tmp_num >> 3
        if (int("{0:b}".format(tmp)) == 11110):
            step = validation(data, num, 3)
            if step == -1 or step == 0:
                return("False")
            continue
        return("False")
    return("True")
