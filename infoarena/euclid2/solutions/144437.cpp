#include <math.h>
#include <stdio.h>

long a, b, r;

int main() { 
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%ld%ld", &a, &b);
	r = a % b;
	while (r != 0) {
		a = b;  
		b = r;  
		r = a % b; 
	}
	printf("%ld\n", b);
	return 0;
}
