#include <cstdio>

#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMAX 1024

int M, N, A[NMAX], B[NMAX], D[NMAX][NMAX], sir[NMAX], bst;

int main(void) {
	FILE * iff = fopen("cmlsc.in","r");
	FILE * off = fopen("cmlsc.out","w");
	fscanf(iff,"%d %d",&M, &N);
	int i, j;
	FOR (i, 1, M)
		fscanf(iff,"%d",&A[i]);
	FOR (i, 1, N)
		fscanf(iff,"%d",&B[i]);

	FOR (i, 1, M)
		FOR (j, 1, N)
			if (A[i] == B[j])
				D[i][j] = 1 + D[i - 1][j - 1];
			else
				D[i][j] = maxim(D[i - 1][j], D[i][j - 1]);

	for (i = M, j = N; i != 0;) {
		if (A[i] == B[j]) {
			sir[++bst] = A[i];
			--i; --j;
		} else if (D[i - 1][j] < D[i][j - 1]) {
			--j;
		} else {
			--i;
		}
	}

	fprintf(off,"%d\n",bst);
	for (i = bst; i; --i) {
		fprintf(off,"%d ", sir[i]);
	}

	fclose(iff);
	fclose(off);

	return 0;
}