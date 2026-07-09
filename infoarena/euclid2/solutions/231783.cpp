#include <stdio.h>

long cmmdc(long a, long b)
{
	long t;
	while (b)
	{
		t=a;
		a=b;
		b=t%b;
	}
	return a;
}

int main()
{
	long t, a, b;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%ld\n", &t);
	for (; t; t--)
	{
		scanf("%ld %ld\n", &a, &b);
		printf("%ld\n", cmmdc(a, b));
	}
	return 0;
}
