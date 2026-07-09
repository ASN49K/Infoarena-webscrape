fo = open("euclid2.in", "r")
next(fo)
fr = open("euclid2.out","w+")
for line in fo:
    A,B = [int(s) for s in line.split()]
    for i in range(min(A,B),0,-1):
        if (A % i == 0 and B % i == 0):
            fr.write(str(i)+"\n")
            break
        