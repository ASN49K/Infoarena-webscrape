#include <stdio.h>
#include <math.h>

long long a, b, t, i;

long long cmmdc(long long a, long long b) {
    long long r;
    while (b) {
		r = a % b;
		a = b;
		b = r; 
    }
    return a;
}

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
	for (scanf("%lld", &t); t--; ) {
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", cmmdc(a, b));
	}
    return 0;
}  
