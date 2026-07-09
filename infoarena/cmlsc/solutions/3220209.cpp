#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,dp[1024][1024],a[1024],b[1024];
int sol[1024], lg;


int main()
{
	int i,j;
	fin >> n >> m;
	for (i = 1; i <= n; i++)
		fin >> a[i];
	for (i = 1; i <= m; i++)
		fin >> b[i];
	for (i = 1; i <= n; i++)	
		for (j = 1; j <= m; j++)
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j-1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	/*
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			fout << dp[i][j] << " ";
		fout << "\n";
	}
	*/
	fout << dp[n][m] << "\n";
	i = n, j = m;
	while (i)
	{
		if (a[i] == b[j])
		{
			sol[++lg] = a[i];
			i--, j--;
		}
		else if (dp[i - 1][j] < dp[i][j - 1])j--;
		else i--;
	}
	for (i = lg; i >= 1; i--)
		fout << sol[i] << " ";
	return 0;
}