#include <cstdio>
using namespace std;

int N, X, Y;

int cmmdc(int x, int y)
{
	while (y)
	{
		int aux = x % y;
		x = y;
		y = aux;
	}
	return x;
}

int main()
{
	FILE *fin = fopen("euclid2.in", "r");
	FILE *fout = fopen("euclid2.out", "w");

	fscanf(fin, "%d", &N);
	for (int i = 1; i <= N; i++)
	{
		fscanf(fin, "%d%d", &X, &Y);
		if (X < Y) {int aux = X; X = Y; Y = aux; }
		fprintf(fout, "%d\n", cmmdc(X, Y));
	}

	fclose(fin);
	fclose(fout);
	return 0;
}

