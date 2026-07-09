def my_func():
    a = 0
    b = 0
    with open('euclid2.out', 'a') as g:
        with open('euclid2.in') as f:
            t = int(f.readline())
            while t:
                a, b = [int(x) for x in f.readline().split()]
                while b != 0:
                    a, b = b, (a % b)
                g.write(str(a) + '\n')
                t -= 1


if __name__ == '__main__':
    my_func()
