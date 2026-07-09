#!/usr/bin/env python3

def gcd(a, b):
    return a if not b else gcd(b, a % b)

with open('euclid2.out', 'w') as fout:
    fin = open('euclid2.in', 'r')
    lines = fin.read().split('\n')
    fin.close()
    
    for i in range(int(lines[0])):
        fout.write(str(gcd(*map(int, lines[i + 1].split()))) + '\n')
