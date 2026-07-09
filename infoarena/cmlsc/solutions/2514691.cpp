#include <fstream>
#include <algorithm>

#define NMAX 1024

int dp[NMAX][NMAX], c[NMAX];

int main()
{
	std::ifstream fin("cmlsc.in");
	std::ofstream fout("cmlsc.out");
	
	int m, n;
	fin >> m >> n;
	int a[NMAX], b[NMAX];

	for (int i = 1; i <= m; i++)
		fin >> a[i];

	for (int i = 1; i <= n; i++)
		fin >> b[i];

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);

	/*dp[1][1] = 0, dp[1][2] = 0, dp[1][3] = 0
	  dp[2][1] = 1, dp[2][2] = 1, dp[2][3] = 1
	  dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1
	  dp[4][1] = 1, dp[4][2] = 1, dp[4][3] = 1
	  dp[5][1] = 1, dp[5][2] = 1, dp[5][3] = 2

	  indicii reprezinta pozitiile unde se afla numerele comune
	*/

	int i = m, j = n;
	while (i) {
		if (a[i] == b[j]) {
			c[++c[0]] = a[i];
			i--, j--;
		}

		//!!!
		else if (dp[i - 1][j] < dp[i][j - 1])
			j--;
		else
			i--;
	}

	fout << c[0] << "\n";
	for (i = c[0]; i >= 1; i--)
		fout << c[i] << " ";

	fin.close(), fout.close();

	return 0;
}