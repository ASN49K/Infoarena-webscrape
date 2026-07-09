#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAXN = 1025;

int x[MAXN], y[MAXN], dp[MAXN][MAXN], sir[MAXN];

int main()
{
	int m, n;
	fin >> m >> n;

	for (int i = 1; i <= m; i++)
		fin >> x[i];

	for (int i = 1; i <= n; i++)
		fin >> y[i];
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (x[i] == y[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	int indexX = m, indexY = n, indexSub = dp[m][n];
	while (indexX != 0 && indexY != 0)
	{
		if (x[indexX] == y[indexY])
		{
			sir[indexSub--] = x[indexX];
			indexX--;
			indexY--;
		}
		else if (dp[indexX - 1][indexY] > dp[indexX][indexY - 1])
		{
			indexX--;
		}
		else
		{
			indexY--;
		}
	}

	fout << dp[m][n] << '\n';
	for (int i = 1; i <= dp[m][n]; i++)
	{
		fout << sir[i] << ' ';
	}
}

