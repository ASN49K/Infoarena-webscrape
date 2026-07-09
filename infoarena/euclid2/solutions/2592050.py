fo = open("euclid2.in", "r")
next(fo)
fr = open("euclid2.out","w+")
def calc_euclid(a,b):
    if b == 0:
        return a
    return calc_euclid(b, a%b)   

for line in fo:
    a,b = [int(s) for s in line.split()]
    fr.write(str(calc_euclid(a,b)) +"\n")

fo.close()
fr.close()