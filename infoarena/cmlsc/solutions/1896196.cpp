#include <fstream>

#define NMax 1025

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, a[NMax], b[NMax], dp[NMax][NMax], answ[NMax];

int get_max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	f >> n >> m;
	for (int i = 1; i <= n; i++)
		f >> a[i];
	for (int i = 1; i <= m; i++)
		f >> b[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = get_max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	g << dp[n][m] << '\n';

	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (a[i] == b[j]) {
			answ[++answ[0]] = a[i];
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	}

	for (int i = answ[0]; i >= 1; i--)
		g << answ[i] << ' ';
}