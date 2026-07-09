#include <fstream>

#define NMax 1030

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, s1[NMax], s2[NMax], dp[NMax][NMax], len, answ[NMax];

int getMax(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	f >> n >> m;
	for (int i = 1; i <= n; i++)
		f >> s1[i];
	for (int i = 1; i <= m; i++)
		f >> s2[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = getMax(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int i = n, j = m;

	len = dp[n][m];
	g << len << "\n";
	while (i > 0 || j > 0) {
		if (s1[i] == s2[j]) {
			answ[len--] = s1[i];

			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	}

	for (int i = 1; i <= dp[n][m]; i++)
		g << answ[i] << " ";

	return 0;
}