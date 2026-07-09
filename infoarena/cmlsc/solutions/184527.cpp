#include <cstdio>

#define DIM 1055
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int N, M, X[DIM], Y[DIM], A[DIM][DIM];

FILE *fout = fopen("cmlsc.out", "w");

void Rec(int i, int j)
{
	if (i == 0 || j == 0) return;
	if (A[i][j] == A[i - 1][j - 1] + 1)
	{
		Rec(i - 1, j - 1);
		fprintf(fout, "%d ", X[i]);
	}
	else if (A[i][j] == A[i - 1][j])
		Rec(i - 1, j);
	else
		Rec(i, j - 1);
}

int main()
{
	FILE *fin = fopen("cmlsc.in", "r");

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
	Rec(N, M);

	fclose(fin);
	fclose(fout);
	return 0;
}

