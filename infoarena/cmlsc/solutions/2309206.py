def read():
    with open('cmlsc.in') as fin:
        n, m = fin.readline().split(' ')
        n = int(n)
        m = int(m)
        x = None
        y = None

        i = 0
        for line in fin:
            if i == 0:
                x = ([int(a) for a in line.split()])
                x = [0] + x
            elif i == 1:
                y = ([int(a) for a in line.split()])
                y = [0] + y
            i += 1

    return n, m, x, y


def main():
    n, m, x, y = read()
    # print(n, m, x, y)
    d = [[0] * (m + 1) for i in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if x[i] == y[j]:
                d[i][j] = d[i - 1][j - 1] + 1
            else:
                d[i][j] = max(d[i - 1][j], d[i][j - 1])

    # Solutiile se afla in n si m

    i = n
    j = m
    sol = []
    while i != 0:
        if x[i] == y[j]:
            sol.append(x[i])
            i = i - 1
            j = j - 1
        elif d[i - 1][j] < d[i][j - 1]:
            j -= 1
        else:
            i -= 1

    sol.reverse()
    with open('cmlsc.out', 'w') as fout:
        fout.write(str(d[n][m]) + '\n')
        for a in sol:
            fout.write(str(a) + ' ')


if __name__ == '__main__':
    main()