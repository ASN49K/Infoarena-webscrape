#include <stdio.h>

long a, b, o, t;

long cmmdc(long a, long b)
{
	long r;
	while (b)
		r = a % b, a = b, b = r;
	return a;
}

int main()
{
	freopen ("euclid2.in", "rt", stdin);
	freopen ("euclid2.out", "wt", stdout);

	scanf("%ld", &t);

	for (o = 1; o <= t; ++o)
	{
		scanf("%ld %ld", &a, &b);
		printf("%ld\n", cmmdc(a, b));
	}

	return 0;
}