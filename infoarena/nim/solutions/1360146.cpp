#include <stdio.h>

int main()
{
	FILE *fin, *fout;
	fin = fopen("nim.in", "r");
	fout = fopen("nim.out", "w");
	
	int T;
	fscanf(fin, "%d", &T);
	
	int i, j;
	for (i = 0; i < T; ++i) {
		int N, xr = 0;
		fscanf(fin, "%d", &N);
		for (j = 0; j < N; ++j) {
			int num;
			fscanf(fin, "%d", &num);
			xr ^= num;
		}
		fprintf(fout, xr ? "DA\n" : "NU\n");
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}
