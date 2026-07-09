
def cmmdc(a, b):
    while b != 0:
        a, b = b, a % b
    return a


if __name__ == "__main__":

    outputFile = open('euclid2.out', 'w')

    with open('euclid2.in', 'r') as fp:
        for i, line in enumerate(fp):
            if i > 0:
                a, b = line.split()
                outputFile.write("%d\n" % cmmdc(int(a), int(b)))


