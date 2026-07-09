#include <stdio.h>
#define NMAX 1024
#define max(a,b) a>b?a:b

FILE *fi = fopen("cmlsc.in", "r");
FILE *fo = fopen("cmlsc.out", "w");

int M, N, A[NMAX], B[NMAX], LMAX[NMAX][NMAX], i, j, l, ix, iy, h=0, k=0;

int main() {
	fscanf(fi, "%d %d", &M, &N);

	for (i=0; i<M; i++) fscanf(fi, "%d", &A[i]);
	for (i=0; i<N; i++) fscanf(fi, "%d", &B[i]);

	for (i=M-1; i>=0; i--)
		for (j=N-1; j>=0; j--)
			if (A[i] == B[j]) LMAX[i][j] = 1+LMAX[i+1][j+1];
			else LMAX[i][j] = max(LMAX[i+1][j], LMAX[i][j+1]);

	l = LMAX[0][0];

	fprintf(fo, "%d\n", l);

	for (i=0; i<M && l>0; i++)
		for (j=0; j<N && l>0; j++)
			if (A[i] == B[j] && LMAX[i][j] == l) {
				l--;
				fprintf(fo, "%d ", A[i]);
				i++; j++;
			}

	fprintf(fo, "\n");
	fclose(fi);
	fclose(fo);

	return 0;
}