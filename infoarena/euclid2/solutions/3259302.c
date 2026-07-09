#include <stdio.h>

int gcd(int a, int b) {
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;}
	return a;
}

int main() {
	FILE *input = fopen("euclid2.in", "r");
	FILE *output = fopen("euclid2.out", "w");

	int a, b, t;

	fscanf(input, "%d", &t);
	
	for(int i = 0; i < t; i++) {
		fscanf(input, "%d %d", &a, &b);
		fprintf(output, "%d\n", gcd(a, b));
	}

	fclose(input);
	fclose(output);
}
