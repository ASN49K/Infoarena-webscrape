#!/usr/bin/env python3

def gcd(a, b):
    return a if not b else gcd(b, a % b)

fout = open('euclid2.out', 'w')

with open('euclid2.in', 'r') as fin:
    for _ in range(int(fin.readline())):
        fout.write(str(gcd(*map(int, fin.readline().split()))) + '\n')

fout.close()
