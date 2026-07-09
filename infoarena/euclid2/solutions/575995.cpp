#include <cstdio>
#include <iostream>
using namespace std;

long cmmdc(const long& a, const long& b) {
	if(b == 0)
		return a;
	return cmmdc(b, a % b);
}

int main(void) {
	FILE* fin;
	FILE* fout;
	fout = fopen("euclid2.out", "w");
	fin = fopen("euclid2.in", "r");
	
	long a, b, n;
	fscanf(fin, "%ld", &n);
	for(int i = 1; i <= n; ++i) {
		fscanf(fin, "%ld %ld", &a, &b);
		fprintf(fout, "%ld\n", cmmdc(a, b));
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
