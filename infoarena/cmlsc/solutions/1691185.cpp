#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NMAX 1030
#define VMAX 260
#include <algorithm>
#include <stack>

using namespace std;
FILE *in, *out;
int n, m;
int D[NMAX][NMAX];
int A[NMAX], B[NMAX];
void read();
void afisare();
int cmlsc();
stack<int> s;
void backtrack(int,int);
int main()
{
	in = fopen("cmlsc.in", "r");
	out = fopen("cmlsc.out", "w");
	read();
	fprintf(out,"%d\n",cmlsc());
	backtrack(n,m);
	return 0;
}
void read()
{
	fscanf(in,"%d%d", &n, &m);
	int i;
	for (i = 1; i <= n; i++)
		fscanf(in, "%d", &A[i]);
	for (i = 1; i <= m; i++)
		fscanf(in, "%d", &B[i]);
}
int cmlsc()
{
	int i, j;
	for (i = 1; i <= n;i++)
		for (j = 1; j <= m; j++)
		{
			if (A[i] == B[j])
			{
				D[i][j] = D[i - 1][j - 1] + 1;
			}
			else
				D[i][j] = std::max(D[i - 1][j], D[i][j - 1]);
		}
		return D[n][m];
}
void afisare()
{
	int dim = s.size();
	for (int i = 0; i < dim; i++)
	{
		fprintf(out, "%d ", s.top());
		s.pop();
	}
}
void backtrack(int i, int j)
{
	if (i == 0 && j == 0)
	{
		afisare();
	}
	else
	{
		if (A[i] == B[j]&&i>0&&j>0)
		{
			s.push(A[i]);
			backtrack(i - 1, j - 1);
		}
		else
		{
			if (D[i][j - 1] > D[i - 1][j]&&j>0)
			{
				backtrack(i, j - 1);
			}
			else
			if (i > 0)
				backtrack(i - 1, j);
			else
				backtrack(0,0);
		}
	}
}