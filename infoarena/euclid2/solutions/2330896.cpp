#include <stdio.h>

int T, A, B;

int gcd(int A, int B)
{
	if (!B) return A;
	if (A > B) return gcd(A - B, B);
	return gcd(A, B - A);
}

int main(void)
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	for (scanf("%d", &T); T; --T)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", gcd(A, B));
	}

	return 0;
}