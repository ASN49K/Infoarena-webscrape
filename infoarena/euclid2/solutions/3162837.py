#import math
with open("euclid2.in","r") as file:
    k = 0
    ls = []
    for line in file:
        if k == 0:
            n = int(line)
        if k > 0:
            a, b = line.split()
            a, b = int(a), int(b)
            #ls.append(math.gcd(a,b))
            ls.append(k)
with open("euclid2.out", "w") as file:
    for item in ls:
        file.write(str(item) + "\n")

        
        
