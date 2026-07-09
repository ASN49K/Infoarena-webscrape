mod = 9973
N = 1000005


def cmmdc(a, b):
    if b == 0:
        return a
    return cmmdc(b, a % b)


def main():
    out = open("euclid2.out", "w")
    try:
        _in = open("euclid2.in", "r")
    except IOError:
        print("File reading error!")
    line = _in.readline().strip()
    n = int(line)
    for i in range(0, n):
        line = _in.readline().strip()
        nrs = line.split(" ")
        out.write(str(cmmdc(int(nrs[0]), int(nrs[1]))) + "\n")


if __name__ == '__main__':
    main()