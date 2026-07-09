def gcd (a, b):
    if b:
        return gcd (b, a % b)
    else:
        return a

output = []
with open('euclid2.in') as f:
    t = int(f.readline())
    while t:
        a, b = f.readline().split()
        a = int(a)
        b = int(b)
        output.append(str(gcd(a, b)) + '\n')
        t -= 1
    
with open('euclid2.out', 'w') as g:
    g.writelines(output)