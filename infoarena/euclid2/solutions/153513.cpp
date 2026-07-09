#include <stdio.h>
#include <assert.h>

inline int gcd( int A, int B )
{
	if (B == 0)
		return A;
	return gcd( B, A % B );
}

int main()
{
	freopen("euclid2.in", "rt", stdin);
	freopen("euclid2.out", "wt", stdout);

	int T;
	for (scanf("%d", &T); T; T--)
	{
		int A, B;
		scanf("%d %d", &A, &B);

		printf("%d\n", gcd( A, B ));
	}

	return 0;
}
