def gcd (a, b):
    if b:
        return gcd (b, a % b)
    else:
        return a

with open('euclid2.out', 'a') as g:
    with open('in.txt') as f:
        t = int(f.readline())
        while t:
            a, b = [int(x) for x in f.readline().split()]
            g.write(str(gcd(a, b)) + '\n')
            t -= 1
    