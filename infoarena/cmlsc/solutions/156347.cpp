#include <stdio.h>
#define NMAX 1025

int Sol[NMAX][NMAX], n, m;
char Prev[NMAX][NMAX];
int A[NMAX], B[NMAX];

void printSolSeq(int i, int j) {
	if (i < 1 || j < 1)
		return;
	if (Prev[i][j] == 1) {
		printSolSeq(i - 1, j - 1);
		printf("%d ", A[i - 1]);
		return;
	}
	if (Prev[i][j] == 0)
		printSolSeq(i - 1, j);
	else
		printSolSeq(i, j - 1);
}

int main() {

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d\n", &m, &n);
	int i;
	for (i = 0; i < m; ++ i)
		scanf("%d ", &A[i]);
	for (i = 0; i < n; ++ i)
		scanf("%d ", &B[i]);

	for (i = 0; i <= m; ++ i)
		Sol[i][0] = 0;
	for (i = 0; i <= n; ++ i)
		Sol[0][i] = 0;

	int j;
	for (i = 1; i <= m; ++ i)
		for (j = 1; j <= n; ++ j) {
			//Sol[i][j] = max(Sol[i - 1][j], Sol[i][j - 1]);
			if (Sol[i - 1][j] > Sol[i][j - 1]) {
				Sol[i][j] = Sol[i - 1][j];
				Prev[i][j] = 0;
			} else {
				Sol[i][j] = Sol[i][j - 1];
				Prev[i][j] = 2;
			}

			if (A[i - 1] == B[j - 1] && Sol[i][j] < Sol[i - 1][j - 1] + 1) {
				Sol[i][j] = Sol[i - 1][j - 1] + 1;
				Prev[i][j] = 1;
			}
		}


	printf("%d\n", Sol[m][n]);
	printSolSeq(m, n);

	return 0;
}
