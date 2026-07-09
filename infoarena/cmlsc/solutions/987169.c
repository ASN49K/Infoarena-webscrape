#include <stdio.h>

#define MAX 1024

int main(void)
{
	int i, j;
	int M, N, A[MAX], B[MAX], C[MAX], PD[MAX][MAX] = {{ 0 }};

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &M, &N);

	for (i = 0; i < M; i++)
		scanf("%d", &A[i]);
	for (i = 0; i < N; i++)
		scanf("%d", &B[i]);

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (A[i] == B[j]) {
				PD[i][j] = PD[i-1][j-1] + 1;
				C[PD[i-1][j-1]] = A[i];
			}
			else {
				PD[i][j] = PD[i-1][j] > PD[i][j-1] ?
						PD[i-1][j] : PD[i][j-1];
			}
		}
	}

	printf("%d\n", PD[M-1][N-1]);
	for (i = 0; i < PD[M-1][N-1]; i++)
		printf("%d ", C[i]);

	return 0;
}
