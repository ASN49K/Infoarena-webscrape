#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
/*

1 7 3 9 8
7 5 8

dp[i][j] = lg max a unui subsir comun din primele i litere (din sirul b)
				si primele j din sirul a

  1 7 3 9 8
7 0 1 1 1 1 
5 1 1 1 1 1
8 1 1 1 1 2
*/

int a[1030], b[1030], m, n;
int dp[1030][1030], sol[1030], len;

int main()
{
	int i, j, p = 0;
	fin >> m >> n;
	for (i = 1; i <= m; i++)
		fin >> a[i];
	for (i = 1; i <= n; i++)
		fin >> b[i];
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			if (a[i] == b[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	i = m; j = n;
	while (i)
	{
		if (a[i] == b[j])
		{
			sol[++len] = a[i];
			i--; j--;
		}
		else
		{
			if (dp[i - 1][j] > dp[i][j - 1]) i--;
			else j--;
		}
	}
	fout << dp[m][n] << "\n";
	for (i = len; i >= 1; i--)
		fout << sol[i] << " ";
	return 0;
}