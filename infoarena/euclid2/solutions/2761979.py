def gcd(a , b):
	while b > 0:
		r = a % b
		a = b
		b = r 
	return a 
fin = open('euclid2.in' , mode = 'r')
fout = open('euclid2.out' , mode = 'w')
t = int(fin.readline())
for i in range(0 , t):
	(a , b) = fin.readline().split()
	a = int(a)
	b = int(b)
	fout.write(f'{gcd(a , b)}\n')
fin.close()
fout.close()
