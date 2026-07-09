from __future__ import (division, print_function,
                        unicode_literals, absolute_import)

def read_gen(filename):
    with open(filename, 'rt') as fin:
        for line in fin:
            for x in line.split():
                yield int(x)

def gcd(x, y):
    return y if x == 0 else gcd(y % x, x)

if __name__ == '__main__':
    with open('euclid2.out', 'wt') as fout:
        it = read_gen('euclid2.in')
        m = next(it)
        for _ in range(m):
            x, y = next(it), next(it)
            d = gcd(x, y)
            fout.write('{0}\n'.format(d))