#include <cstdio>
#include <algorithm>

#define MAXN 1030

using namespace std;

FILE *f = fopen ("cmlsc.in","r");
FILE *g = fopen ("cmlsc.out","w");

int m, n, A[MAXN], B[MAXN], SOL[MAXN], NrSol;
int D[MAXN][MAXN];

void read()
{
	fscanf (f, "%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
		fscanf (f, "%d", &A[i]);
	for (int i = 1; i <= n; i++)
		fscanf (f, "%d", &B[i]);
}

void lcs()
{
	int i, j;
	
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			if (A[i] == B[j])
				D[i][j] = D[i - 1][j - 1] + 1;
			else
				D[i][j] = max(D[i - 1][j], D[i][j - 1]);
}

int main()
{
	int i, j;
	
	read();
	lcs();
	
	for (i = m, j = n; i && j; )
		if (A[i] == B[j])
		{
			SOL[++NrSol] = A[i];
			i--;
			j--;
		}
		else if (D[i - 1][j] > D[i][j - 1])
			i--;
		else
			j--;
		
	fprintf (g, "%d\n", D[m][n]);
	for (i = NrSol; i >= 1; i--)
		fprintf (g, "%d ", SOL[i]);
	
	fclose(f);
	fclose(g);
	
	return 0;
}
