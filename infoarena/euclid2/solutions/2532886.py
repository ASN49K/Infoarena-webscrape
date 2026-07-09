
def inp_gen(fname):
    with open(fname, 'rt') as fin:
        for line in fin:
            for val in line.split():
                yield int(val)

def euclid(x, y):
    return x if y == 0 else euclid(y, x % y)

if __name__ == "__main__":
    in_gen = inp_gen("euclid2.in")
    with open("euclid2.out", "wt") as fout:
        n = next(in_gen)
        for _ in range(n):
            x = next(in_gen)
            y = next(in_gen)
            fout.write(f'{}\n'.format(euclid(x, y)))
    
        