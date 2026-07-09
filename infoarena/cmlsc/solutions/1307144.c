#include <stdio.h>
#include <stdlib.h>

int m, n, vm[1025], vn[1025], a[1025][1025], i, j;

void afis(FILE* g, int i, int j);
void LSC(FILE* g);

int main()
{
	FILE* f = fopen("cmlsc.in", "r");
	FILE* g = fopen("cmlsc.out", "w");

	fscanf(f, "%d%d", &m, &n);

	for(i = 0; i < m; i++)
		fscanf(f, "%d", &vm[i]);
	for(i = 0; i < n; i++)
		fscanf(f, "%d", &vn[i]);

	LSC(g);

	return 0;
}

void afis(FILE* g, int i, int j)
{
	if(i == 0 || j == 0 || a[i][j] == 0)
		return;

	if(vm[i - 1] == vn[j - 1])
	{
		afis(g, i - 1, j - 1);
		fprintf(g, "%d ", vm[i - 1]);
	}

	else if(a[i - 1][j] > a[i][j - 1])
		afis(g, i - 1, j);

	else
		afis(g, i, j - 1);
}

void LSC(FILE* g)
{
  int i, j;

  for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
			if(vm[i - 1] == vn[j - 1])
				a[i][j] = a[i - 1][j - 1] + 1;
			else
				a[i][j] = (a[i - 1][j] > a[i][j - 1]) ? a[i - 1][j] : a[i][j - 1];

	fprintf(g, "%d\n", a[m][n]);
	afis(g, m, n);
}
