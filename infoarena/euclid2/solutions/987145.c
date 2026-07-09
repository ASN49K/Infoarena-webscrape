#include <stdio.h>

int main(void)
{
	int i;
	int T, a, b, aux;

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &T);
	for (; T; T--) {
		scanf("%d %d", &a, &b);
		while (b) {
			aux = a;
			a = b;
			b = aux % a;
		}
		printf("%d\n", a);
	}

	return 0;
}
