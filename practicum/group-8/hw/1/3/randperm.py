#!/usr/bin/python3
import random

wordlist = []
line = input()

while line:
    wordlist.append(line)
    line = input()

random.shuffle(wordlist)
print(' '.join(wordlist)),
