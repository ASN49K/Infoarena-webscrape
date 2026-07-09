fo = open("euclid2.in", "r")
next(fo)
fr = open("euclid2.out","w+")
def calc_euclid(a,b):
    if a == 0:
        return b
    elif b== 0:
        return a
    elif a == b:
        return a
    else:
        return calc_euclid(min(a,b),max(a,b)%min(a,b))

for line in fo:
    a,b = [int(s) for s in line.split()]
    fr.write(str(calc_euclid(a,b)) +"\n")

fo.close()
fr.close()