#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");



int maxi(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int main()
{
	char a[1025], b[1025];
	int i, j, n, m;
	f >> a >> b;
	n = strlen(a);
	m = strlen(b);
	int dp[1025][1025];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			dp[0][j] = 0, dp[i][0] = 0;
	int max = 0, imax = 0, jmax = 0;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			if (a[i] == b[j])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
				if (dp[i][j] > max)
					max = dp[i][j], imax = i, jmax = j;
			}

			else
			{
				dp[i][j] = maxi(dp[i - 1][j], dp[i][j - 1]);
				if (dp[i][j] > max)
					max = dp[i][j], imax = i, jmax = j;
			}
	}

	char comun[1025];
	int nr = 0;
	for (i = n, j = m; i>=0;)
	{
		if (a[i] == b[j]) comun[nr++] = a[i--], j--;
		else if (dp[i - 1][j] < dp[i][j - 1]) j--;
		else i--;
	}
	for (i = nr - 1; i >= 0; i--)
		g << comun[i];
}
