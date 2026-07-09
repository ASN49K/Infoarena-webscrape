#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int cmmdc(int a, int b) {
	if (!b) return a;
    return cmmdc(b, a % b);
}

int main() {

	FILE *input, *output;
	int n, a, b, result, scan_result;
	input = fopen("euclid2.in", "r");
	output = fopen("euclid2.out", "w");

	fscanf(input, "%d", &n);

	for(int i = 0; i < n; i++) {
		if(fscanf(input, "%d %d", &a, &b) != 2) {
			fprintf(stderr, "There must be two numbers\n");
			exit(1);
		}

		result = cmmdc(a,b);
		fprintf(output, "%d\n", result);
	}

	return 0;
}