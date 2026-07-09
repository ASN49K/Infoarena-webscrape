#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int nmax = 1026;
int n,m;
int mat[nmax][nmax];
int sir1[nmax];
int sir2[nmax];
int dir[nmax][nmax];

void citire()
{
	f >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		f >> sir1[i];
	}
	for (int j = 1; j <= m; j++)
	{
		f >> sir2[j];
	}
}

void afis(int i, int j)
{
	if (i == 0 || j == 0)
	{
		return;
	}
	if (dir[i][j] == 0)
	{
		afis(i - 1, j - 1);
		g << sir1[i] << ' ';
	}
	else if (dir[i][j] == 1)
	{
		afis(i - 1, j);
	}
	else {
		afis(i, j - 1);
	}
}
int main()
{
	citire();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (sir1[i] == sir2[j])
			{
				dir[i][j] = 0;
				mat[i][j] = mat[i - 1][j - 1] + 1;
			}else if (mat[i - 1][j] > mat[i][j - 1])
			{
				dir[i][j] = 1;
				mat[i][j] = mat[i - 1][j];
			}
			else {
				dir[i][j] = 2;
				mat[i][j] = mat[i][j-1];
			}
		}
	}
	g << mat[n][m] << '\n';
	int i = n, j = m;
	afis(n,m);
}

