#include <iostream>
#include <stdio.h>
using namespace std;

int euclid(int a, int b) {
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	FILE *in, *out;
	in = fopen("euclid2.in", "rt");
	out = fopen("euclid2.out", "wt");
	int t, a, b;
	fscanf(in, "%d", &t);
	for (int i = 0; i < t; ++ i) {
		fscanf(in, "%d%d", &a, &b);
		fprintf(out, "%d\n", euclid(a, b));
	}

	fclose(in);
	fclose(out);
}