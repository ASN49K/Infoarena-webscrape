#!/usr/bin/env python3

import sys

#sys.stdout = open('cmlsc.out', 'w')

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

sol = []
i, j = len(a) - 1, len(b) - 1
print(lg[i][j])

while i:
    if a[i] == b[j]:
        sol.append(str(a[i]))
        i -= 1
        j -= 1
    elif lg[i-1][j] < lg[i][j-1]:
        j -= 1
    else:
        i -= 1

print(' '.join(reversed(sol)))
