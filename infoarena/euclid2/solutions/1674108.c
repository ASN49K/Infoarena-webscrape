#include <stdio.h>

int main(void)
{
	int t, i, a, b, q, r, aux;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%i", &t);
	for (i = 0; i < t; ++i) {
		scanf("%i%i", &a, &b);
		if (a < b) {
			aux = a;
			a = b;
			b = aux;
		}
		do {
			q = a / b;
			r = a % b;
			a = b;
			b = r;
		} while (r);
		printf("%i\n", a);
	}
	return 0;
}
