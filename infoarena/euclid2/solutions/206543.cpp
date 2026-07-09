#include <stdio.h>

int cmmdc(int a, int b)
{
	if (b == 0) return a;
	else return cmmdc(b, a % b);
}

int main()
{
	freopen("euclid2.in", "r", stdin);
#ifndef _SCREEN_
	freopen("euclid2.out", "w", stdout);
#endif

	int T, a, b;
	for (scanf("%d\n", &T); T; T --) {
		scanf("%d %d\n", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}

	return 0;
}
