#include <stdio.h>

#define minim(a, b) ((a < b) ? a : b)

int A, B;

int main(void)
{
	int i;

	freopen("euclid.in", "r", stdin);
	freopen("euclid.out", "w", stdout);
	
	scanf("%d %d", &A, &B);
	for (i = minim(A, B); i; --i)
		if (A % i == 0 && B % i == 0)
		{
			printf("%d\n", i);
			break;
		}

	return 0;
}
