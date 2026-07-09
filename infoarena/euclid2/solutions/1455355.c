#include <stdio.h>

//assume a < b
int euclid (int a, int b) {
	int r = b % a;
	return (r == 0) ? a : euclid(r, a);
}

int main (void) {
	FILE *in = fopen("euclid2.in", "r");
	FILE *out = fopen("euclid2.out", "w");
	
	int n;
	fscanf(in, "%d", &n);
	
	for (int i = 0; i < n; ++i) {
		int x, y;
		fscanf(in, "%d %d", &x, &y);
		
		int lcd = (x < y) ? euclid(x, y) : euclid(y, x);
		fprintf(out, "%d\n", lcd);
	}

	fclose(in);
	fclose(out);
	
	return 0;
}
		
