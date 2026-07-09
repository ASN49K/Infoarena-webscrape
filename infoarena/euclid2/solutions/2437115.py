from contextlib import redirect_stdout


def cmmdc(a, b):
    while b != 0:
        a, b = b, a % b
    return a


if __name__ == "__main__":
    lineList = [line.rstrip('\n') for line in open('euclid2.in')]
    with open('euclid2.out', 'w') as outputFile:
        with redirect_stdout(outputFile):
            for i, v in enumerate(lineList):
                if i > 0:
                    a, b = v.split()
                    print(cmmdc(int(a), int(b)))

