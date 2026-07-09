#include <fstream>
#include <algorithm>

using namespace std;

const int NMAX = 1030;
int n, m;
int a[NMAX], b[NMAX];
int dp[NMAX][NMAX];
int v[NMAX];

int main()
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	fin >> n >> m;
	for (int i = 1;i <= n;++i)
		fin >> a[i];
	for (int i = 1;i <= m;++i)
		fin >> b[i];
	for (int i = 1;i <= n;++i)
		for (int j = 1;j <= m;++j)
		{
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	int lg = dp[n][m], i = n, j = m;
	while (lg > 0)
	{
		if (a[i] == b[j])
		{
			v[lg--] = a[i];
			--i;
			--j;
		}
		else
		{
			if (dp[i - 1][j] >= dp[i][j - 1])
				--i;
			else
				--j;
		}
	}
	fout << dp[n][m] << "\n";
	for (int i = 1;i <= dp[n][m];++i)
		fout << v[i] << " ";
	fin.close();
	fout.close();
	return 0;
}