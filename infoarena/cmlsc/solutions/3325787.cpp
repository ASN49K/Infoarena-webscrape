#include<fstream>
using namespace std;
#define endl '\n'
#define nrmax 1024

int a[nrmax], b[nrmax], dp[nrmax][nrmax];

int main() {
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	int n, m;
	fin >> n >> m;
	for (int i = 0; i < n; ++i) fin >> a[i];
	for (int i = 0; i < m; ++i) fin >> b[i];
	for (int i = 0; i < n; ++i) dp[i][0] = a[i] == b[0];
	for (int i = 0; i < m; ++i) dp[0][i] = a[0] == b[i];

	for(int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	int rez[nrmax], size = 0;
	for (int i = n - 1, j = m - 1; i; i) {
		if (a[i] == b[j])
			rez[size++] = a[i], i--, j--;
		else if (dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	}
	fout << dp[n - 1][m - 1] << endl;
	for (int i = size - 1; i >= 0; ++i) fout << rez[i] << ' ';
	return 0;
}