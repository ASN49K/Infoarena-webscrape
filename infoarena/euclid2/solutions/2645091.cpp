#include <cstdio>

using namespace std;

int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	int n, a, b, aux;
	scanf("%d", &n);

	for(int i=0; i<n; ++i) {
		scanf("%d%d", &a, &b);

		while (b) {
			aux = a%b;
			a = b;
			b = aux;
		}

		printf("%d\n", a);
	}


	return 0;
}
