#include <stdio.h>

int gcd(int a, int b)
{
	int c;
	while (a % b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return b;
}
 
int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int t, a, b, c;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
	return 0;
}
