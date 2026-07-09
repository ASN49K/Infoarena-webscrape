#!/usr/bin/env python3

import functools, sys
sys.stdout = open('nim.out', 'w')

with open('nim.in', 'r') as f:
    for _ in range(int(f.readline())):
        f.readline()
        s = functools.reduce(lambda x, y: x ^ y, map(int, f.readline().split()))
        print('DA' if s else 'NU')
