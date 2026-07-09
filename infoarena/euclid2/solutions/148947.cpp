#include <stdio.h>

long a, b;

long gcd(long a, long b)
{
	if(!b) return a;
	return gcd(b, a%b);
}


int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%ld %ld", &a, &b);

	printf("%ld\n", gcd(a, b));

	return 0;
}