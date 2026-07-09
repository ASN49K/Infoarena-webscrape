#include <stdio.h>

int euclid (int a, int b) {
	int aux;
	while (b) {
		aux = a % b;
		a = b;
		b = aux;
	}
	return a;
}

int main () {
	FILE *f_in, *f_out;
	int t, a, b;

	f_in = fopen ("euclid2.in", "r");
	f_out = fopen ("euclid2.out", "w");

	fscanf (f_in, "%d", &t);
	for (; t > 0; --t) {
		fscanf (f_in, "%d %d", &a, &b);
		fprintf(f_out, "%d\n", euclid(a, b));	
	}

	fclose(f_in);
  	fclose(f_out);
	
	return 0;
}
