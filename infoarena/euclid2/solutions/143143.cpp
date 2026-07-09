#include <stdio.h>

inline int gcd( int a, int b )
{
	if (b == 0)
		return a;
	return gcd( b, a % b );
}

int main()
{
	freopen("euclid2.in", "rt", stdin);
	freopen("euclid2.out", "wt", stdout);

	int A, B;
	scanf("%d %d", &A, &B);
	printf("%d\n", gcd(A, B));
	return 0;
}
