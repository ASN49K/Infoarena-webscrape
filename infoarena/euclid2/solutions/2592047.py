fo = open("euclid2.in", "r")
next(fo)
fr = open("euclid2.out","w+")
def calc_euclid(m,n):
    if m< n: 
        (m,n) = (n,m)
    if (m%n) == 0:
        return n 
    else:
        return (calc_euclid(n, m % n)) # recursion taking place


for line in fo:
    a,b = [int(s) for s in line.split()]
    fr.write(str(calc_euclid(a,b)) +"\n")

fo.close()
fr.close()