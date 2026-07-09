#include <cstdio>

int main() {
	auto fin = fopen("euclid2.in", "r");
	auto fout = fopen("euclid2.out", "w");

	int n;
	fscanf(fin, "%d", &n);

	while (n--) {
		int a, b;
		fscanf(fin, "%d %d", &a, &b);

		int t;
		while (b) {
			t = b;
			b = a % b;
			a = t;
		}

		fprintf(fout, "%d\n", a);
	}
	return 0;
}
