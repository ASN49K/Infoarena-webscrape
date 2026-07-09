#include <stdio.h>

#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a > b) ? a : b

int gcd (int a, int b) {
	int r = b % a;
	
	if (r == 0) {
		return a;
	} else {
		return gcd (r, a);
	}
}


int main(void) {
	int n, a, b;
	
	FILE *in = fopen("euclid2.in", "r");
	FILE *out = fopen("euclid2.out", "w");
	
	fscanf(in, "%d\n", &n);
	
	for (int i = 0; i < n; i++) {
		fscanf(in, "%d %d\n", &a, &b);
		printf("%d %d ", a, b);
		int min = MIN(a, b);
		int max = MAX(a, b);
		fprintf(out, "%d\n", gcd(min, max));
	}
	
	fclose(in);
	fclose(out);
	
	return 0;
}
	
