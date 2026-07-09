#include <stdio.h>
#define Nmax 1025

int A[Nmax], B[Nmax], sol[Nmax], D[Nmax][Nmax];
int n, m, i, j, k;

int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	
	FILE *f = fopen("cmlsc.in", "r");
	FILE *g = fopen("cmlsc.out", "w");
	
	fscanf(f, "%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &A[i]);
	for (i = 1; i <= m; i++)
		fscanf(f, "%d", &B[i]);
	
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (A[i] == B[j])
				D[i][j] = D[i-1][j-1] + 1;
			else
				D[i][j] = max(D[i-1][j], D[i][j-1]);
	
	for (i = n, j = m; i > 0; )
		if (A[i] == B[j]) {
			sol[++k] = A[i];
			i--, j--;
		}
		else
			if (D[i][j-1] > D[i-1][j])
				j--;
			else
				i--;
	
	fprintf(g, "%d\n", D[n][m]);
	for (i = k; i > 0; i--)
		fprintf(g, "%d ", sol[i]);
	
	fclose(f);
	fclose(g);
	
	return 0;
}