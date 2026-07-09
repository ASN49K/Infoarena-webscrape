#include <stdio.h>

long int euclid(long int a, long int b) {
	long int r;
	long int max, min;
	long int prev;

	do {
		if (a > b) {
			max = a;
			min = b;
		} else {
			max = b;
			min = a;
		}

		prev = min;
		r = max % min;

		if (r)
			prev = r;

		a = min;
		b = r;
	} while(r);

	return prev;
}

int main() {
	long int a, b;
	long int T;
	long int i;
	FILE *fin, *fout;

	fin = fopen("euclid2.in", "r");
	fout = fopen("euclid2.out", "w");

	if (fin == NULL || fout == NULL)
		return -1;

	fscanf(fin, "%ld", &T);

	for (i = 0; i < T; i++) {
		a = b = 1;
		fscanf(fin, "%ld %ld", &a, &b);
		fprintf(fout, "%ld\n", euclid(a, b));
	}

	return 0;
}
