#include <cstdio>

FILE * f1 = fopen("euclid2.in", "rt");
FILE * f2 = fopen("euclid2.out", "wt");

int n, a, b, r;

int main() {
	fscanf(f1, "%d", &n);
	while (n--) {
		fscanf(f1, "%d%d", &a, &b);
		while (b) {
			r = a % b;
			a = b;
			b = r;
		}
		fprintf(f2, "%d\n", a);
	}
	fclose(f1);
	fclose(f2);
}
