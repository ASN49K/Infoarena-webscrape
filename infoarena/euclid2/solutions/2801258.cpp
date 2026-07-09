#include <stdio.h>

#define minim(a, b) ((a < b) ? a : b)

int T, A, B;

int main(void)
{
	int i;

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	for (scanf("%d", &T); T; --T)
	{
		scanf("%d %d", &A, &B);
		for (i = minim(A, B); i; --i)
			if (A % i == 0 && B % i == 0)
			{
				printf("%d\n", i);
				break;
			}
	}

	return 0;
}
