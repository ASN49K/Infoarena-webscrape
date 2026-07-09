#include <stdio.h>

int euclid(int a, int b)
{
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main(void)
{
	int T, i, a, b;

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		if (a > b)
			printf("%d\n", euclid(a, b));
		else
			printf("%d\n", euclid(b, a));
	}

	return 0;
}
	
