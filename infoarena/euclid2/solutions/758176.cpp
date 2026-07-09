#include<stdio.h>

int cmmdc(int a, int b) {
	 int r = b % a;
	 while(r != 0) {
	 	a = b;
	 	b = r;
	 	r = b % a;
	 }
	 return b;
}

int main() {
	FILE *f = fopen("euclid2.in", "r"), *g = fopen("euclid2.out", "w");

	int n;
	fscanf(f, "%d", &n);

	for(int i = 0; i < n; i++) {
		int a, b;
		fscanf(f, "%d %d\n", &a, &b);
		fprintf(g, "%d\n", cmmdc(a, b));
	}
	fclose(f);
	fclose(g);

	return 0;
}