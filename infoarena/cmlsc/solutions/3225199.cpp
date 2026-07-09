#include <iostream>
#include <fstream>
#define NMAX 1025

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int i, j, n, m, a[NMAX], b[NMAX], nsol, sol[NMAX];
int dp[NMAX][NMAX];

int main()
{
	f >> n >> m;
	for (i = 1; i <= n; i++)
		f >> a[i];
	for (i = 1; i <= m; i++)
		f >> b[i];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (a[i] == b[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	for (i = n; i >= 1; )
		for (j = m; j >= 1; )
			if (a[i] == b[j])
			{
				sol[++nsol] = a[i];
				--i; --j;
			}
			else
				if (dp[i-1][j] < dp[i][j-1]) j--;
			else i--;
	g << nsol << '\n';
	for (i = nsol; i >= 1; i--)
		g << sol[i] << ' ';
	f.close();
	g.close();
	return 0;
}
