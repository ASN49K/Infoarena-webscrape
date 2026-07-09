#!/usr/bin/env python3

import sys

sys.stdout = open('euclid2.out', 'w', buffering=1024)

def gcd(a, b):
    while b:
        a, b = b, a % b
    else:
        return a

fin = open('euclid2.in', 'r', buffering=1024)

for i in range(int(fin.readline())):
    print(gcd(*map(int, fin.readline().split())))

sys.stdout.close()
