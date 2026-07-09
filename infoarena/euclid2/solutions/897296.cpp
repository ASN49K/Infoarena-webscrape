#include <cstdio>

int gcd(int a, int b) {
	while (a) {
		int c = a % b;
		a = b;
		b = c;
	}
	return(b);
}

int main() {
	FILE * in = fopen("euclid2.in", "rt");
	FILE * out = fopen("euclid2.out", "wt");
	int n;
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		fscanf(in, "%d%d", &x, &y);
		fprintf(out, "%d\n", gcd(x, y));

	}
	fclose(in);
	fclose(out);
}
