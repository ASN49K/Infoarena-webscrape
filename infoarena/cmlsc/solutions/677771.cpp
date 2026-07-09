#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define N_MAX 1025
#define MAX(a,b) (a > b) ? a: b;

ifstream fin(FIN);
ofstream fout(FOUT);
int n,m;
int c[N_MAX][N_MAX],b[N_MAX][N_MAX];
int X[N_MAX],Y[N_MAX],LCS[N_MAX];
int LCS2[N_MAX][N_MAX];
vector<int> rec;

void lcs()
{
	int i,j;
	fin >> n >> m;
	for (i = 1; i <= n; ++i) fin >> X[i];
	for (i = 1; i <= m; ++i) fin >> Y[i];
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			if (X[i] == Y[j])
				LCS2[i][j] = LCS2[i - 1][j - 1] + 1;
			else
				LCS2[i][j] = MAX(LCS2[i - 1][j], LCS2[i][j - 1]);
			fout << LCS2[n][m] << '\n';
	for (int i = n, j = m; i != 0 && j != 0; )
	{
		if (X[i] == Y[j])
		{
			rec.push_back(X[i]);
			--i;
			--j;
		} else {
			i = LCS2[i - 1][j] >= LCS2[i][j - 1] ? i - 1 : i ;
			j = LCS2[i - 1][j] >= LCS2[i][j - 1] ? j : j - 1;
			}
	}

	for (int i = rec.size() - 1; i >= 0; --i)
	fout << rec[i] << " ";
}

int main()
{
	lcs();
	
	return 0;
}
