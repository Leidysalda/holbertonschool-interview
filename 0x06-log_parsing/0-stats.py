#!/usr/bin/python3
"""
script that reads stdin line by line and computes metrics
"""
import sys

status = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0,
          "404": 0, "405": 0, "500": 0}

total = 0


def print_stat():
    """
    Print stats
    """

    global total

    print('File size: {}'.format(total))
    stcdor = sorted(status.keys())

    for each in stcdor:
        if status[each] > 0:
            print('{}: {}'.format(each, status[each]))


if __name__ == '__main__':
    count = 0
    try:
        for data in sys.stdin:
            try:
                fact = data.split(' ')
                if fact[-2] in status:
                    status[fact[-2]] += 1
                total += int(fact[-1])
            except:
                pass
            count += 1
            if count == 10:
                print_stat()
                count = 0
    except keyboardInterrupt:
        print_stat()
        raise
    else:
        print_stat()
