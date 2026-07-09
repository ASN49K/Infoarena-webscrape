#!/usr/bin/env python3

import sys

sys.stdout = open('euclid2.out', 'w', buffering=512)

def gcd(a, b):
    while b:
        a, b = b, a % b
    else:
        return a

fin = open('euclid2.in', 'r', buffering=1024)

for i in range(int(fin.readline())):
    line = fin.readline()
    splitIdx = line.index(' ')

    a = int(line[:splitIdx])
    b = int(line[splitIdx+1:])
    print(gcd(a, b))

sys.stdout.close()
