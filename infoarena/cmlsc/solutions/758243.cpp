#include<stdio.h>

int main() {
	FILE *f = fopen("cmlsc.in", "r"), *g = fopen("cmlsc.out", "w");

	int n, m;
	fscanf(f, "%d %d", &n, &m);

	// citeste sirurile
	int *X = new int[n];
	int *Y = new int[m];
	for(int i = 1; i <= n; i++)
		fscanf(f, "%d", &X[i - 1]);
	for(int i = 1; i <= m; i++)
		fscanf(f, "%d", &Y[i - 1]);

	//structurile folosite
	int **lcs = new int*[n + 1],
		**path = new int*[n + 1];
	for(int i = 0; i <= n; i++) {
		lcs[i] = new int[m + 1];
		path[i] = new int[m + 1];
	}

	for(int i = 0; i <= n; i++)
		lcs[i][0] = 0;
	for(int i = 0; i <= m; i++)
		lcs[0][i] = 0;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(X[i - 1] == Y[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				path[i][j] = 0;
			}
			else {
				if(lcs[i - 1][j] > lcs[i][j - 1]) {
					lcs[i][j] = lcs[i - 1][j];
					path[i][j] = 1;
				}
				else {
					lcs[i][j] = lcs[i][j - 1];
					path[i][j] = 2;
				}
			}

	//solutia
	int i = n, j = m, *sol = new int[lcs[n][m]], k = 0;
	while(i != 0 && j != 0) {
		if(path[i][j] == 2) j--;
		else if(path[i][j] == 1) i--;
		else if(path[i][j] == 0) {
			sol[k++] = X[i - 1];
			i--;
			j--;
		}
	}
	for(; k; k--)
		fprintf(g, "%d ", sol[k - 1]);

	fclose(f);
	fclose(g);

	return 0;
}