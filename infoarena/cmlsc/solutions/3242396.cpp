//https://www.infoarena.ro/problema/cmlsc
#include <fstream>
#include <vector>
#include <stack>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

using namespace std;

vector<vector<int>> dp;
vector<int> A, B;
stack<int> S;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n, m, maxim, i, j;
	fin >> n >> m;
	A.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		fin >> A[i];
	B.resize(m + 1);
	for (int i = 1; i <= m; ++i)
		fin >> B[i];
	dp.resize(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if (A[i] == B[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}

	fout << dp[n][m] << '\n';
	maxim = dp[n][m];
	i = n, j = m;
	while (maxim > 0)
	{
		if (A[i] == B[j])
		{
			S.push(A[i]);
			maxim--;
			i--;
			j--;
		}
		else if (dp[i][j - 1] > dp[i - 1][j])
			j--;
		else
			i--;
	}
	while (!S.empty())
	{
		fout << S.top() << ' ';
		S.pop();
	}
}