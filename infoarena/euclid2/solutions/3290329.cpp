#define _CRT_SECURE_NO_WARNINGS
#include <fstream>

int gcd(int a, int b) {
	int r;
	while (b > 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	FILE* fin = fopen("euclid2.in", "r");
	FILE* fout = fopen("euclid2.out", "w");
	int T;
	fscanf(fin, "%d", &T);
	for (int i = 0; i < T; ++i) {
		int a, b;
		fscanf(fin, "%d %d", &a, &b);
		fprintf(fout, "%d\n", gcd(a, b));
	}
}