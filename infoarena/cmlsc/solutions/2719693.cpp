#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 1024

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[NMAX+10], b[NMAX+10], dp[NMAX+10][NMAX+10];
vector <int> ans;

int main()
{
	fin >> n >> m;
	for(int i=1; i<=n; i++)
		fin >> a[i];
	for(int i=1; i<=m; i++)
		fin >> b[i];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			{	if(a[i] == b[j])
					dp[i][j] = dp[i-1][j-1] + 1;
				dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
			}
	fout << dp[n][m] << '\n';
	int r = n, c = m;
	while(r && c)
		{	if(a[r] == b[c] && dp[r][c] == dp[r-1][c-1] + 1)
				{	ans.push_back(a[r]);
					r--;
					c--;
				}
			if(dp[r-1][c] > dp[r][c-1])
				r--;
			else
				c--;
		}
	for(int i=ans.size()-1; i>=0; i--)
		fout << ans[i] << ' ';
	fout << '\n';
	return 0;
}