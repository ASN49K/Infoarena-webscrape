#define DM 1025
#include <fstream>
#include <stack>
using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");
int v1[DM], v2[DM], n, m, mx, mxl, dp[DM][DM], perf[DM];
stack <int> s;

int mxa(int a, int b)
{
	int ja = 0;
	for (int i = 1; i < b; ++i)
		if (dp[a][i] > dp[a][ja])
			ja = i;
	return ja;
}

int main() {
	cin >> n >> m;
	if (n >= m)
	{
		for (int i = 1; i <= n; ++i)
			cin >> v1[i];
		for (int j = 1; j <= m; ++j)
			cin >> v2[j];
	}
	else
	{
		for (int i = 1; i <= n; ++i)
			cin >> v2[i];
		for (int j = 1; j <= m; ++j)
			cin >> v1[j];
		swap(n, m);
	}
	for (int i = 1; i <= n; ++i)
	{
		mx = 0;
		for (int j = 1; j <= m; ++j)
		{
			if (v1[i] == v2[j])
				dp[i][j] = dp[i-1][mxa(i - 1, j)] + 1;
			else
				dp[i][j] = dp[i-1][j];
			if (dp[i][j] > dp[i][mx])
				mx = j;
		}
		perf[i] = mx;
		if (dp[n][mx] > dp[mxl][perf[mxl]])
			mxl = i;
	}
	s.push(v2[mx]);
	int a = mx;
	cout << dp[n][mx] << '\n';
	for (int i = mxl - 1; dp[n][mx] && i; --i)
		for (int j = a; j >= 1; --j)
			if (dp[i][j] == dp[mxl][a] - 1 && v1[i] == v2[j])
			{
				s.push(v2[j]);
				a = j, --dp[n][mx], mxl = i;
				break;
			}
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}