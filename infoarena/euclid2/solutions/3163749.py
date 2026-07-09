import math
open("euclid2.out","w").write('\n'.join(str(math.gcd(*map(int,L.split())))for L in open("euclid2.in").read().split('\n')[1:]))