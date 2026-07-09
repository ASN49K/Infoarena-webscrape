#include <stdio.h>

int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int T, a, b;
	scanf("%d", &T);

	for (int i = 0; i < T; i ++) {
		scanf("%d %d", &a, &b);
		
		while (b != 0) {
			int aux = b;
			b = a % b;
			a = aux;
		}
		printf("%d\n", a);
	}
	return 0;
}
