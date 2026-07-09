#include <stdio.h>

int euclid(int a, int b) {
	int c;

	if (a == b)
		return a;

	if(a < b) {
		c = a;
		a = b;
		b = c;
	}

    while (b) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main() {
	int i, n, a, b, r;
	FILE *f = fopen("euclid2.in", "r");
	FILE *g = fopen("euclid2.out", "w");

	fscanf(f, "%d", &n);

	for(i = 0; i < n; i++) {
		fscanf(f, "%d %d", &a, &b);
		r = euclid(a, b);
		fprintf(g, "%d\n", r);
	}

	fclose(f);
	fclose(g);

	return 0;
}