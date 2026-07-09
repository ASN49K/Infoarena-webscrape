#include <cstdio>
#include <cstdlib>

int main() {
	int *A, *B, M, N;
	int *cmlsc, MAX;
	int **c;
	char **s;
	int i, j, k;

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	// input
	scanf("%d %d", &M, &N);
	A = (int*)malloc((M + 1) * sizeof(int));
	B = (int*)malloc((N + 1) * sizeof(int));
	for (i = 1; i <= M; ++i) {
		scanf("%d", &A[i]);
	}
	for (j = 1; j <= N; ++j) {
		scanf("%d", &B[j]);
	}

	// solve
	c = (int**)malloc((M + 1) * sizeof(int*));
	s = (char**)malloc((M + 1) * sizeof(char*));
	for (i = 0; i <= M; ++i) {
		c[i] = (int*)malloc((N + 1) * sizeof(int));
		s[i] = (char*)malloc((N + 1) * sizeof(char));
	}

	/* c[i][j] = 0, if i = 0 or j = 0 */
	for (i = 1; i <= M; ++i) {
		c[i][0] = 0;
	}
	for (j = 0; j <= N; ++j) {
		c[0][j] = 0;
	}
	/*
	 *	c[i][j] = c[i-1][j-1] + 1, if i,j > 0 and A[i] == B[j]
	 *		    = max(c[i-1][j], c[i][j-1]), ---- A[i] != B[j]
	 */

	for (i = 1; i <= M; ++i) {
		for (j = 1; j <= N; ++j) {
			if (A[i] == B[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				s[i][j] = '\\';
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				s[i][j] = '|';
			}
			else {
				c[i][j] = c[i][j - 1];
				s[i][j] = '-';
			}
		}
	}

	MAX = c[M][N];
	cmlsc = (int*)malloc(MAX * sizeof(int));

	k = MAX - 1; i = M; j = N;
	while (k > -1 && i > 0 && j > 0) {
		if (s[i][j] == '\\') {
			cmlsc[k] = A[i];
			--i; --j; --k;
		}
		else if (s[i][j] == '|') {
			--i;
		}
		else {
			--j;
		}
	}


	// output
	printf("%d\n", MAX);
	for (k = 0; k < MAX; ++k) {
		printf("%d ", cmlsc[k]);
	}
	printf("\n");

	// free memory
	free(A);
	free(B);
	for (i = 0; i <= M; ++i) {
		free(c[i]);
		free(s[i]);
	}
	free(c);
	free(s);
	free(cmlsc);

	return 0;
}
