#!/usr/bin/env python3

import sys

sys.stdout = open('euclid2.out', 'w')

def gcd(a, b):
    return a if not b else gcd(b, a % b)

fin = open('euclid2.in', 'r')

for i in range(int(fin.readline())):
    print(gcd(*map(int, fin.readline().split())))
    sys.stdout.flush()
