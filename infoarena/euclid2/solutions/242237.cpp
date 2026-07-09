#include <stdio.h>
#include <math.h>

long a, b, t, i;

inline long long cmmdc(long long a, long long b) {
    long long r;
    while (b) {
		r = a % b;
		a = b;
		b = r; 
    }
    return a;
}

int main() {
    freopen("ejoc.in", "r", stdin);
    freopen("ejoc.out", "w", stdout);
	for (scanf("%ld", &t); t--; ) {
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", cmmdc(a, b));
	}
    return 0;
}  
