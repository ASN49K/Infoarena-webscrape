#!/usr/bin/env python3

import sys

sys.stdout = open('euclid2.out', 'w', buffering=2048)

def gcd(a, b):
    return a if not b else gcd(b, a % b)

fin = open('euclid2.in', 'r', buffering=2048)

for i in range(int(fin.readline())):
    print(gcd(*map(int, fin.readline().split())))

sys.stdout.close()
