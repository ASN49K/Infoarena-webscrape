#define DM 1025
#include <fstream>
#include <stack>
using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");
int v1[DM], v2[DM], n, m, mx, mxa, mxl, dp[DM][DM], perf[DM];
stack <int> s;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> v1[i];
	for (int j = 1; j <= m; ++j)
		cin >> v2[j];
	for (int i = 1; i <= n; ++i)
	{
		mxa = mx;
		mx = 0;
		for (int j = 1; j <= m; ++j)
		{
			if (v1[i] == v2[j])
				dp[i][j] = dp[i-1][mxa] + 1;
			else
				dp[i][j] = dp[i-1][j];
			if (dp[i][j] > dp[i][mx])
				mx = j;
		}
		perf[i] = mx;
		if (dp[i][mx] > dp[mxl][perf[mxl]])
			mxl = i;
	}
	cout << dp[n][mx] << '\n';
	while (dp[n][mx] && mxl)
	{
		if (v1[mxl] == v2[perf[mxl]])
		{
			s.push(v1[mxl]);
			--dp[n][mx];
		}
		--mxl;
	}
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}