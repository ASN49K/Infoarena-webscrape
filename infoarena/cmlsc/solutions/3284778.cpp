#include <fstream>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
#include <map>
#include <string>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#define oo 2000000
#define MOD 1000000007
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[2000][2000], n, m, a[2000], b[2000],rez[2000],p;

int main()
{
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
		fin >> a[i];
	for (int i = 1; i <= m; i++)
		fin >> b[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	fout << dp[n][m] << endl;
	int i = n;
	int j = m;
	while (j > 0 && i > 0)
	{
		if (a[i] == b[j])
		{
			rez[++p] = a[i];
			i--;
			j--;
			
		}
		else
		{
			if (dp[i][j - 1] > dp[i - 1][j])
				j--;
			else
				i--;
		}
	}
	for (int i = p; i >= 1; i--)
	{
		fout << rez[i] << " ";
	}
}
