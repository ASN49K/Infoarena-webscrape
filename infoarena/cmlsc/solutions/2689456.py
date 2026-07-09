"""longest common subsequence from 2 vectors
subsequence = not necessarily consecutives
subarray = consecutives
"""
from __future__ import (division, print_function,
                        absolute_import, unicode_literals)
import sys 

def read_gen(filename):
    with open(filename, 'rt') as fin:
        for line in fin:
            for x in line.split():
                yield int(x)

def solve(m, n, a, b):
    # d[i, j] = longest subsequence using a[1..i] and b[1..j]
    d = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if a[i] == b[j]:
                d[i][j] = d[i - 1][j - 1] + 1
            elif d[i - 1][j] > d[i][j - 1]:
                d[i][j] = d[i - 1][j]
            else:
                d[i][j] = d[i][j - 1]
    return d

def printr(d, a, b, index_a, index_b, fout):

    if index_a > 0 and index_b > 0:
        if a[index_a] == b[index_b]:
            printr(d, a, b, index_a - 1, index_b - 1, fout)
            fout.write('{0} '.format(a[index_a]))
        elif d[index_a][index_b] == d[index_a][index_b - 1]:
            printr(d, a, b, index_a, index_b - 1, fout)
        else:
            printr(d, a, b, index_a - 1, index_b, fout)

if __name__ == '__main__':
    sys.setrecursionlimit(2000)
    
    it = read_gen('cmlsc.in')
    m, n = next(it), next(it)
    a = [0] * (m + 1)
    b = [0] * (n + 1)
    for i in range(1, m + 1):
        x = next(it)
        a[i] = x
    for i in range(1, n + 1):
        x = next(it)
        b[i] = x
    
    d = solve(m, n, a, b)
    with open('cmlsc.out', 'wt') as fout:
        fout.write('{0}\n'.format(d[m][n]))
        printr(d, a, b, m, n, fout)

