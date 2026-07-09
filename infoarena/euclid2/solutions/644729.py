
def cmmdc( a, b):
	while a * b != 0:
		if  a > b:
			a = a % b;
		else: 
			b = b % a;
	return a + b

if __name__ == "__main__":
	g = open('cmmdc.in', 'r')
	f = open('cmmdc.out', 'w')
	N = g.readline()
	N = int(N)

	for i in range( 0, N) :
		A,B = g.readline().split()
		A = int(A)
		B = int(B)
		f.write( str(cmmdc( A, B))+'\n' )
		