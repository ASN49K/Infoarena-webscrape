#include <cstdio>

#define DIM 1055
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int N, M, X[DIM], Y[DIM], A[DIM][DIM], sol[DIM];

int main()
{
	FILE *fin = fopen("cmlsc.in", "r");
	FILE *fout = fopen("cmlsc.out", "w");

	fscanf(fin, "%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		fscanf(fin, "%d", X + i);
	for (int i = 1; i <= M; i++)
		fscanf(fin, "%d", Y + i);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (X[i] == Y[j]) A[i][j] = A[i - 1][j - 1] + 1;
			else              A[i][j] = max(A[i - 1][j], A[i][j - 1]);

	fprintf(fout, "%d\n", A[N][M]);
	int x = N, y = M, l = 0;
	while (A[x][y])
	{
		if (X[x] == Y[y])
		{
			sol[++l] = X[x];
			x--;
			y--;
		}
		else if (A[x - 1][y] >= A[x][y - 1])
			x--;
		else
			y--;
	}
	for (int i = l; i > 0; i--)
		fprintf(fout, "%d ", sol[i]);

	fclose(fin);
	fclose(fout);
	return 0;
}

