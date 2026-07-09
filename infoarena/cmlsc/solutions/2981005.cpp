#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
#include <queue>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, c1[1030], c2[1030];
int dp[1025][1025], sol[1030], p;
int main()
{
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
		fin >> c1[i];
	for (int j = 1; j <= m; j++)
		fin >> c2[j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (c1[i] == c2[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	fout << dp[n][m] << '\n';
	int i = n, j = m;
	while (i && j)
		if (c1[i] == c2[j])
			sol[++p] = c1[i], i--, j--;
		else if (dp[i - 1][j] < dp[i][j - 1])
			j--;
		else
			i--;
	for (int i = p; i >= 1; i--)
		fout << sol[i] << ' ';
		
	return 0;
}

