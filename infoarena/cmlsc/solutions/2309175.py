def read():
    with open('cmlsc.in') as fin:
        n, m = fin.readline().split(' ')
        n = int(n)
        m = int(m)
        x = []
        y = []

        for a in fin.readline().strip(' \n'):
            try:
                x.append(int(a))
            except:
                pass

        for a in fin.readline().strip(' \n'):
            try:
                y.append(int(a))
            except:
                pass

    return n, m, x, y


def main():
    n, m, x, y = read()
    # print(n, m, x, y)
    d = [[0] * (m + 1) for i in range(n + 1)]
    for i in range(n + 1):
        for j in range(m + 1):
            if i == 0 or j == 0:
                d[i][j] = 0
            elif x[i - 1] == y[j - 1]:
                d[i][j] = d[i - 1][j - 1] + 1
            else:
                d[i][j] = max(d[i - 1][j], d[i][j - 1])

    # Solutiile se afla in n si m
    i = n
    j = m
    sol = []
    while i != 0 and j != 0:
        if x[i - 1] == y[j - 1]:
            sol.append(x[i - 1])
            i = i - 1
            j = j - 1
        elif d[i][j] == d[i - 1][j]:
            i = i - 1
        elif d[i][j] == d[i][j - 1]:
            j = j - 1

    sol.reverse()
    print(d[n][m])
    for a in sol:
        print(a, end=" ")

if __name__ == '__main__':
    main()