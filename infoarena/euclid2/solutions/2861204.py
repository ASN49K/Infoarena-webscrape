def gcd (a, b):
    if b:
        return gcd (b, a % b)
    else:
        return a

with open('euclid2.out', 'a') as g:
    with open('in.txt') as f:
        t = int(f.readline())
        while t:
            a, b = f.readline().split()
            a = int(a)
            b = int(b)
            g.write(str(gcd(a, b)) + '\n')
            t -= 1
    