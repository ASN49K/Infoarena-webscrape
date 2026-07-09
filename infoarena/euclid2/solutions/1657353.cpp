#include<stdio.h>
#include<assert.h>

inline int gcd(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{

	int T, a, b;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	for (scanf("%d", &T), assert(T <= 100000); T; --T)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
	return 0;
}
