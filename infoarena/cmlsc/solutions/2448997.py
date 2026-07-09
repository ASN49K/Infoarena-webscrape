#!/usr/bin/env python3

import sys

sys.stdout = open('cmlsc.out', 'w')

a, b = [], []

with open('cmlsc.in', 'r') as fin:
    fin.readline()
    a = list(map(int, fin.readline().split()))
    b = list(map(int, fin.readline().split()))

lg = [[0] * len(b) for _ in range(len(a))]

for i in range(len(a)):
    for j in range(len(b)):
        if a[i] == b[j]:
            lg[i][j] = 1 if a == 0 or b == 0 else 1 + lg[i-1][j-1]
        else:
            if i > 0:
                lg[i][j] = lg[i-1][j]
            if j > 0 and lg[i][j-1] > lg[i][j]:
                lg[i][j] = lg[i][j-1]

print(lg[len(a) - 1][len(b) - 1])

def nextSolElement(i, j):
    if i < 0 or j < 0 or lg[i][j] == 0:
        return
    for ii in range(i + 1):
        if a[ii] == b[j] and lg[ii][j] == lg[i][j]:
            nextSolElement(ii - 1, j - 1)
            print((' ' if lg[i][j] > 1 else '') + str(a[ii]), end='')
            return
    for jj in range(j):
        if a[i] == b[jj] and lg[i][jj] == lg[i][j]:
            nextSolElement(i, jj - 1)
            print((' ' if lg[i][j] > 1 else '') + str(a[i]), end='')
            return
    nextSolElement(i - 1, j - 1)

nextSolElement(len(a) - 1, len(b) - 1)
print()
