//#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025];
int b[1025];
int dp[1025][1025];

void buildMatrix(int n, int m)
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				continue;
			}

			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
}

int v[1025];

void getMax(int n, int m)
{
	int i = n;
	int j = m;
	int k = 0;

	while (i) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else {
			if (dp[i][j] == dp[i][j - 1]) {
				j--;
			}
			else {
				v[++k] = a[i];
				i--;
				j--;
			}
		}
	}
	
	fout << k << '\n';
	for (i = k; i >= 1; --i) fout << v[i] << " ";
}

int main()
{
	ios::sync_with_stdio(false);
	fin.tie(0); fout.tie(0);

	int n, m;
	fin >> n >> m;
	for (int i = 1; i <= n; ++i) fin >> a[i];
	for (int i = 1; i <= m; ++i) fin >> b[i];

	buildMatrix(n, m);
	getMax(n, m);
}