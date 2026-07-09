#include <stdio.h>
int T,A,B;
int gcd(int a, int b)
{
	int c = 0;
	while (a)
		c = a; a = b % a; b = c;
	return (b);

}
int main(void)
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &T);
	while (--T)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", gcd(A, B));
	}
	return (0);
}