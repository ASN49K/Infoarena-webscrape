#include <stdio.h>

int gcd(int, int);

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out" ,"w", stdout);

	int n, a, b, c, i;

	scanf("%d", &n);

	for(i = 1; i <= n; ++i)
	{
		scanf("%d %d", &a, &b);
		c = gcd(a, b);
		printf("%d\n", c);
	}

	return 0;
}

int gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}