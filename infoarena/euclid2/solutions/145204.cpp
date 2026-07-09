#include <cstdio>

long gcd(long x, long y) {
	if ( y==0 )
		return x;
	return gcd(y, x%y);
}


int main() {
	long x,y;

	fscanf(fopen("euclid2.in", "r"), "%ld %ld", &x, &y);
	fprintf(fopen("euclid2.out","w"), "%ld\n", gcd(x,y));
	return 0;
}
