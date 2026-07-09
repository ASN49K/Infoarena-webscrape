#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("scmax.in");
ofstream fout("scmax.out");

const int NMAX = 1050;

int m, n;
int dp[NMAX][NMAX];
int a[NMAX];
int b[NMAX];
vector<int>sol;

void cmlsc()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
}

bool ok = false;

void recon(int i, int j)
{
	if (ok) return;
	if (dp[i][j] == 0)
	{
		ok = true;
		return;
	}
	if (dp[i][j-1] == dp[i-1][j] && dp[i-1][j-1] == dp[i][j-1] && dp[i][j] == dp[i-1][j-1] + 1) {\
		sol.push_back(a[i]);
		recon(i - 1, j - 1);
	}
	if (dp[i - 1][j] > dp[i][j - 1])
		recon(i - 1, j);
	else
		recon(i, j - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	fin.tie(0); fout.tie(0);
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
		fin >> a[i];
	for (int i = 1; i <= m; i++)
		fin >> b[i];
	cmlsc();
	fout << dp[n][m] << '\n';\
	recon(n, m);
	reverse(sol.begin(), sol.end());
	for (int i = 0; i < sol.size(); i++)
		fout << sol[i] << ' ';
	fout << '\n';
	return 0;
}

