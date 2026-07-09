#include <stdio.h>

#define MAX(a, b)  ((a) > (b)) ? (a) : (b)

int main() {
	
	int m, n;
	FILE *in = fopen("cmlsc.in", "r");
	fscanf(in, "%d%d", &m, &n);

	int A[m+1], B[n+1], i;
	for (i = 1; i <= m; i++)
		fscanf(in, "%d", &A[i]);

	for (i = 1; i <= n; i++)
		fscanf(in, "%d", &B[i]);

	int C[m+1][n+1];
	for (i = 0; i <= n; i++)
		C[0][i] = -1;
	for (i = 0; i <= m; i++)
		C[i][0] = -1;

	int j;
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			if (A[i] == B[j]) {
				C[i][j] = C[i-1][j-1] + 1;

			} else {
				C[i][j] = MAX(C[i-1][j], C[i][j-1]);

			}

	int len = C[m][n] + 1;
	int sir[len];
	int cont = len-1;

	for (i = m, j = n; i!= 0; ){
		if (A[i] == B[j]) {
			sir[cont--] = A[i];
			i--;
			j--;

		} else if (C[i][j-1] > C[i-1][j]) {
			j--;

		} else {
			i--;

		}
	}

	FILE *out = fopen("cmlsc.out", "w");

	fprintf(out, "%d\n", len);

	for (i = 0; i < len; i++)
		fprintf(out, "%d ", sir[i]);

	fclose(in);
	fclose(out);

	return 0;
}
