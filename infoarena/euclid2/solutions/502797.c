#include <stdio.h>
#include <stdlib.h>

int euclid(int&, int&);

int main() {
	int cases;
	FILE* input = fopen("euclid2.in", "r");
	FILE* output = fopen("euclid2.out", "w");
	
	fscanf(input, "%d", &cases);
	
	int a, b, result;
	while(cases--) {
		fscanf(input, "%d%d", &a, &b);
		result = euclid(a, b);
		fprintf(output, "%d\n", result);
	}
}

int euclid(int &x, int &y) {
	if(x < y) {
		int swap = x;
		x = y;
		y = swap;
	}
	while(y != 0) {
		x = x % y;
		int swap = x;
		x = y;
		y = swap;
	}
	return x;
}
