#include <stdio.h>

int euclid(int a, int b)
{
	int r;
	while ((r = a % b)) {
		a = b;
		b = r;
	}
	return b;
}

int main()
{
	int N, i, a, b;

	freopen("euclid2.in", "rt", stdin);
//	freopen("euclid2.out", "wt", stdout);

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", euclid(a, b));
	}

	return 0;
}
