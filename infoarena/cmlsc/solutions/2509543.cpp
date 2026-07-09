#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[1100], b[1100], dp[1100][1100],sol[1100],nr;
int main()
{
	int i, j;
	fin >> n >> m;
	for (i = 1; i <= n; i++)
		fin >> a[i];
	for (i = 1; i <= m; i++)
		fin >> b[i];
	for(i=1;i<=n;i++)
		for (j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	fout << dp[n][m]<<'\n';
	i = n; j = m;
	while (nr < dp[n][m])
	{
		if (a[i] == b[j])
		{
			sol[++nr] = a[i];
			i--;
			j--;
		}
		else
		{
			if (dp[i - 1][j] > dp[i][j - 1])
				i--;
			else j--;
		}
	}
	for (i = nr; i > 0; i--)
		fout << sol[i] << ' ';
}