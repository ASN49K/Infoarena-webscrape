
import sys

def solve(n, m, a, b):
    d = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i] == b[j]:
                d[i][j] = d[i - 1][j - 1] + 1
            d[i][j] = max(d[i - 1][j], d[i][j])
            d[i][j] = max(d[i][j - 1], d[i][j])
    return d

def printr(fout, d, x, y, a, b):

    if x > 0 and y > 0:
        if d[x][y] == d[x - 1][y]:
            printr(fout, d, x - 1, y, a, b)
        elif d[x][y] == d[x][y - 1]:
            printr(fout, d, x, y - 1, a, b)
        else:
            printr(fout, d, x - 1, y - 1, a, b)
            fout.write('{} '.format(a[x]))

if __name__ == "__main__":
    sys.setrecursionlimit(2000)

    with open("grader_test9.in", 'rt') as fin:
        n, m = map(int, next(fin).split())
        a = [0] + [val for val in next(fin).split()]
        b = [0] + [val for val in next(fin).split()]

    d = solve(n, m, a, b)
    with open("cmlsc.out", 'wt') as fout:
        fout.write('{}\n'.format(d[n][m]))
        printr(fout, d, n, m, a, b)
    return 0