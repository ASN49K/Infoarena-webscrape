#include <stdio.h>

int i, T;
long n1, n2;

long gcd(long a, long b)
{
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &T);
	for(i = 1; i <= T; i++)
	{
		scanf("%ld%ld", &n1, &n2);
		printf("%ld\n", gcd(n1, n2));
	}

	return 0;
}