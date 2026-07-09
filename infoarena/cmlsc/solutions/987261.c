#include <stdio.h>

#define MAX 1025

void print(int A[MAX], int B[MAX], int PD[MAX][MAX], int i, int j)
{
	if (i > 0 && j > 0) {
		if (A[i] == B[j]) {
			print(A, B, PD, i-1, j-1);
			printf("%d ", A[i]);
		} else if (PD[i-1][j] < PD[i][j-1]) {
			print(A, B, PD, i, j-1);
		} else {
			print(A, B, PD, i-1, j);
		}
	}
}

int main(void)
{
	int i, j, k;
	int M, N;
	int A[MAX], B[MAX], PD[MAX][MAX];

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &M, &N);

	for (i = 1; i <= M; i++)
		scanf("%d", &A[i]);
	for (i = 1; i <= N; i++)
		scanf("%d", &B[i]);

	for (i = 1; i <= M; i++)
		for (j = 1; j <= N; j++)
			if (A[i] == B[j])
				PD[i][j] = PD[i-1][j-1] + 1;
			else
				PD[i][j] = PD[i-1][j] > PD[i][j-1] ?
						PD[i-1][j] : PD[i][j-1];

	printf("%d\n", PD[M][N]);
	print(A, B, PD, M, N);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
