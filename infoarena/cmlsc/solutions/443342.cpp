#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define PIN		"euclid2.in"
#define POUT	"euclid2.out"

using namespace std;

int m, n;
int a[1030], b[1030], dt[1030][1030];

void recurse(int x, int y, int curr, FILE *fout)
{
	if (!curr)
		return;
	
	for (int i = x; i > 0; --i)
		if (dt[i][y] == curr && a[i] == b[y])
		{
			recurse(i, y, curr - 1, fout);
			fprintf(fout, "%d ", a[i]);
			return;
		}

	for (int j = y; j > 0; --j)
		if (dt[x][j] == curr && a[x] == b[j])
		{
			recurse(x, j, curr - 1, fout);
			fprintf(fout, "%d ", a[x]);
			return;
		}

	recurse(x - 1, y - 1, curr, fout);
}

void cmlsc(FILE *fout)
{
	int best = 0;

	for (int j = 1; j <= n; ++j)
		for (int i = 1; i <= m; ++i)
		{
			int max = dt[i - 1][j];
			if (dt[i][j - 1] > max)
			{
				max = dt[i][j - 1];
			}
			if (a[i] == b[j])
				if (dt[i - 1][j - 1] + 1 > max)
				{
					max = dt[i - 1][j - 1] + 1;
				}
			dt[i][j] = max;
			best = max > best ? max : best;
		}
	fprintf(fout, "%d\n", best);
	
	recurse(m, n, best, fout);
}



int main()
{
	FILE *fin = fopen("euclid2.in", "r"), *fout = fopen("euclid2.out", "w");

	fscanf(fin, "%d %d", &m, &n);
	for (int i = 1; i <= m; ++i)
		fscanf(fin, "%d", a + i);

	for (int i = 1; i <= n; ++i)
		fscanf(fin, "%d", b + i);
	
	cmlsc(fout);

	fclose(fout);
	return 0;
}