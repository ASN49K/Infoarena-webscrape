def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


with open("euclid2.in", "r") as f, open("euclid2.out", "w") as g:
    t = int(next(f))
    while t:
        t -= 1
        a, b = (int(x) for x in next(f).split())
        g.write("{}\n".format(gcd(a, b)))
