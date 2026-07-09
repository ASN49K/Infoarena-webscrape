#include <stdio.h>

int t,a,b,c;

int main () {
	FILE * in  = fopen("euclid2.in", "r");
	FILE * out = fopen("euclid2.out", "w");

	fscanf(in, "%d", &t);

	for (; t; t--) {
		fscanf(in, "%d %d", &a, &b);

		while (b) {
			c=b;
			b=a%b;
			a=c;
		}

		fprintf(out, "%d\n", a);
	}

	fclose(in);
	fclose(out);

	return 0;
}
