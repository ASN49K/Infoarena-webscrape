#include <fstream>

#include <vector>

using namespace std;

ifstream fin ("cmlsc.in");

ofstream fout ("cmlsc.out");

int main() {

	int n, m;

	fin >> n >> m;

	vector<int> a (n + 1);

	for (int i = 1; i <= n; ++i)
		fin >> a[i];
	
	vector<int> b (m + 1);

	for (int i = 1; i <= m; ++i)
		fin >> b[i];
	
	vector<vector<int>> dp (n + 1, vector<int> (m + 1));

	for (int i = 1; i <= n; ++i) {

		for (int j = 1; j <= m; ++j) {

			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
		}
	}

	fout << dp[n][m] << '\n';
	
	vector<int> rez (dp[n][m] + 1);

	int i = n, j = m, l = dp[n][m];

	while (l > 0) {

		if (a[i] == b[j]) {

			rez[l] = a[i];

			i--, j--, l--;
		}
		else {

			if (dp[i - 1][j] > dp[i][j - 1])
				i--;
			else
				j--;
		}
	}

	for (int i = 1; i <= dp[n][m]; ++i)
		fout << rez[i] << ' ';
	
	return 0;
}