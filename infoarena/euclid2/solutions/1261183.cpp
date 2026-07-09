#include <stdio.h>


int gcd (int a , int b) {
	if (b != 0) {
		return gcd(b, a % b);
	}
	return a;
}
  
int main() 
{
	int n = 0, i = 0, a = 0, b = 0;
	FILE * in_file = fopen("euclid2.in", "r");
	FILE * out_file = fopen("euclid2.out", "w");

	fscanf(in_file, "%d", &n);
	for (i = 0; i < n ; i ++) {
		fscanf(in_file, "%d", &a);
		fscanf(in_file, "%d", &b);
		fprintf(out_file, "%d\n", gcd(a, b));
	}

	fclose(in_file);
	fclose(out_file);
	return 0;
}
