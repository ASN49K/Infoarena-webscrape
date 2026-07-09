#include <iostream>

using namespace std;

int cmmdc(int x, int y) {
	int r;
	while(x % y > 0) {
		r = x % y;
		x = y;
		y = r;
	}
	return y;
}

int main() 
{
	FILE *fin, *fout;
	fin = fopen("euclid2.in", "r");
	fout = fopen("euclid2.out", "w");

	int n, x, y;
	fscanf(fin, "%d", &n);
	for(int i = 0; i < n; i++) {
		fscanf(fin, "%d %d\n", &x, &y);
		fprintf(fout, "%d\n", cmmdc(x, y));
	}
	fclose(fin);
	fclose(fout);
	return 0;
}