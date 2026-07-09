#include <stdio.h>

#define NMax 1024
#define MMax 1024

int t[NMax][MMax] = {0}, A[NMax], B[MMax];
int list[NMax], listIter = 1;

int maxim(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	int n, m;

	FILE * f;
	FILE * g;
	g = fopen("cmlsc.out", "w");
	f = fopen("cmlsc.in", "r");

	fscanf(f, "%d %d", &n, &m);
	
	for(int i=1; i<=n; i++)
		fscanf(f, "%d", &A[i]);
	for(int i=1; i<=m; i++)
		fscanf(f, "%d", &B[i]);

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(A[i] == B[j]) t[i][j] = 1 + t[i-1][j-1];
			else t[i][j] = maxim(t[i-1][j], t[i][j-1]);
		}
	}

	for(int i = n, j = m; i;)
	{
		if(A[i] == B[j])
			list[listIter++] = A[i], i--, j--;
		else if(t[i-1][j] < t[i][j-1]) j--;
		else i--;
	}

	fprintf(g, "%d\n", --listIter);
	for(int i = listIter; i; i--)
		fprintf(g, "%d ", list[i]);
	
}