#include <stdio.h>

int main()
{
	int a, b, r, T;

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &T); while (T--) {

	scanf("%d%d", &a, &b);

	while (b) { r = a % b, a = b, b = r; }

	printf("%d\n", a);             }

	return 0;
}
