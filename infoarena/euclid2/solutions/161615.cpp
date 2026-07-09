#include <math.h>
#include <stdio.h>

long a, b, r, t, i;

int main() { 
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%ld", &t);
	for (i = 1; i <= t; ++i) {
		scanf("%ld%ld", &a, &b);
		r = a % b;
		while (r != 0) {
			a = b;  
			b = r;  
			r = a % b; 
		}
		printf("%ld\n", b);
	}
	return 0;
}
