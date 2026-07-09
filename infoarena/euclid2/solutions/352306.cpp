#include <stdio.h>


int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	int t, a, b, c;
	
	for(scanf("%d", &t); t; --t)
	{
		scanf("%d %d", &a, &b);
		c = gcd(a, b);
		printf("%d\n", c);
	}

	return 0;
}
