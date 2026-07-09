with open('euclid2.in', 'r') as f:
     n = int(f.readline())
     g = open('euclid2.out', 'w')
     for i in range(n):
         a, b = f.readline().split()
         a = int(a); b = int(b)
         while b > 0:
             a, b = b, a%b
         g.write(str(a) + "\n")
     g.close()