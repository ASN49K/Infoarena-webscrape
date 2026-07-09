def input_gen_int(fname):
    with open(fname, 'rt') as fin:
        for line in fin:
            for val in line.split():
                yield int(val)


def LonComSubStr(a, b):
    x = [[0 for _ in range(len(a))] for _ in range(len(b))]
    for i in range(1, len(b)):
        for j in range(1, len(a)):
            if b[i] == a[j]:
                x[i][j] = x[i - 1][j - 1] + 1
            else:
                x[i][j] = max(x[i - 1][j], x[i][j - 1])

    sol = []
    i = len(b) - 1
    j = len(a) - 1
    while x[i][j]:
        if b[i] != a[j]:
            if x[i][j] == x[i - 1][j]:
                i -= 1
            else:
                j -= 1
        else:
            sol.append(b[i])
            i -= 1
            j -= 1
    sol.reverse()
    return sol


if __name__ == "__main__":
    ig = input_gen_int("cmlsc.in")
    na, nb = next(ig), next(ig)
    a = [0]
    b = [0]
    for _ in range(na):
        a.append(next(ig))
    for _ in range(nb):
        b.append(next(ig))

    res = LonComSubStr(a, b)
    with open("cmlsc.out", 'wt') as fout:
        fout.write('{}\n'.format(len(res)))
        for f in res:
            fout.write('{} '.format(f))
