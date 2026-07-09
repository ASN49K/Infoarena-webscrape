#include <stdio.h>
int g_n;
int g_a;
int g_b;
int gcd(int a, int b)
{
	int c;
	while (a)
		c = a; a = b % a; b = c;
	return (b);

}
int main()
{
	freopen("euclid2.in", "w", stdin)
	freopen("euclid2.out", "r", stdout)
	int n = 0;
	scanf("%d", &n);
	while (g_n)
	{
		scanf("%d %d", &g_a, &g_b);
		printf("%d\n", gcd(g_a, g_b));
		g_n--;
	}
	return (0);
}