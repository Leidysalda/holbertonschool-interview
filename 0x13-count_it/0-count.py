#!/usr/bin/python3
""" recursive function that queries the Reddit API
"""
import requests
import sys


def count_words(subreddit, word_list, kw_count={}, next_pg=None, reap_kw={}):
    """ Count words
    """
    headers = {"User-Agent": "Leidysalda"}

    if next_pg:
        subRhot = requests.get('https://reddit.com/r/' + subreddit +
                               '/hot.json?after=' + next_pg,
                               headers=headers)
    else:
        subRhot = requests.get('https://reddit.com/r/' + subreddit +
                               '/hot.json', headers=headers)

    if subRhot.status_code == 404:
        return

    if kw_count == {}:
        for word in word_list:
            kw_count[word] = 0
            reap_kw[word] = word_list.count(word)

    subRhot_dict = subRhot.json()
    subRhot_data = subRhot_dict['data']
    next_pg = subRhot_data['after']
    subRhot_posts = subRhot_data['children']

    for post in subRhot_posts:
        post_data = post['data']
        post_title = post_data['title']
        title_words = post_title.split()
        for w in title_words:
            for key in kw_count:
                if w.lower() == key.lower():
                    kw_count[key] += 1

    if next_pg:
        count_words(subreddit, word_list, kw_count, next_pg, reap_kw)

    else:
        for k, v in reap_kw.items():
            if v > 1:
                kw_count[key] *= v

        sorted_abc = sorted(kw_count.items(), key=lambda x: x[0])
        sorted_res = sorted(sorted_abc, key=lambda x: (-x[1], x[0]))

        for res in sorted_res:
            if res[1] > 0:
                print(f"{res[0]}: {res[1]}")
