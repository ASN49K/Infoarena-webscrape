#!/usr/bin/env python3

def gcd(a, b):
    return a if not b else gcd(b, a % b)

with open('euclid2.out', 'w') as fout:
    fin = open('euclid2.in', 'r')
    
    for i in range(int(fin.readline())):
        fin.readline()
        #gcd(*map(int, fin.readline().split()))
        fout.write(str(0) + '\n')

    fin.close()
