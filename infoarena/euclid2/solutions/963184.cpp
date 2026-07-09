#include <stdio.h>

FILE *fin, *fout;
int t, a, b;

int euclid (int a, int b) {
	if (!b) return a;
	return euclid (b, a % b);
}

int main (void) {
	fin = fopen ("euclid.in", "r");
	fout = fopen ("euclid.out", "w");

	fscanf (fin, "%d", &t);
	
	for (; t; t--) {
		fscanf (fin, "%d %d", &a, &b);
		fprintf (fout, "%d\n", euclid (a, b));
	}

	fclose (fin);
	fclose (fout);
	
	return 0;

}


