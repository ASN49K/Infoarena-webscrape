#include <stdio.h>

long cmmdc(long a, long b)
{
	return (b == 0 ? a : cmmdc(b, a % b));
}

int main()
{
	int T;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	scanf("%d", &T);
	while (T--)
	{
		long a, b;
		scanf("%ld %ld", &a, &b);
		printf("%ld\n", cmmdc(a, b));
	}

	return 0;
}
