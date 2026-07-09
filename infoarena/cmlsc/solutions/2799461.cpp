#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 

#pragma warning(disable : 4996)

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1024], b[1024];

short int dp[1024][1024];

void citire(int n, int v[]) {
	for (int i = 1; i <= n; i++)
		fin >> v[i];
}

void fr(short int dp[1024][1024], int v[], int i, int j) { //afisare sir
	if (dp[i][j] == 0)
		return;
	if (dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1])
		fr(dp, v, i - 1, j - 1), fout << v[i] << " ";
	else if (dp[i - 1][j] > dp[i][j - 1])
		fr(dp, v, i - 1, j);
	else
		fr(dp, v, i, j - 1);
}

int main()
{
	int i = 1, j = 1;
	int n, m;
	fin >> n >> m;
	citire(n, a);
	citire(n, b);
	for(int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	fout << dp[n][m] << endl;
	fr(dp, a,n , m);
	return 0;
}

