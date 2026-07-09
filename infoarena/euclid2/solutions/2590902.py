def input_gen_int(fname):
    with open(fname, 'rt') as fin:
        for line in fin:
            for val in line.split():
                yield int(val)


def euclid(a, b):
    while b != 0:
        m = b
        b = a % b
        a = m
    return a


if __name__ == "__main__":
    ig = input_gen_int("euclid2.in")
    with open("euclid2.out", "wt") as fout:
        n = next(ig)
        for _ in range(n):
            x = next(ig)
            y = next(ig)
            fout.write('{}\n'.format(euclid(x, y)))
