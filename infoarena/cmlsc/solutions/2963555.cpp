#include <fstream>
#include <stack>
using namespace std;
string file = "cmlsc";
ifstream cin (file + ".in");
ofstream cout (file + ".out");
stack <int> S;
int A[1025], B[1025], dp[1025][1025];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	for (int i = 1; i <= m; i++)
		cin >> B[i];
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (A[i] == B[j])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	int x = n, y = m;
	while (dp[x][y])
	{
		int i = x, j = y;
		while (dp[i - 1][y] == dp[x][y])
			i--;
		while (dp[i][j - 1] == dp[x][y])
			j--;
		S.push(A[i]);
		x = i - 1;
		y = j - 1;
	}

	cout << dp[n][m] << '\n';
	while (!S.empty())
	{
		cout << S.top() << ' ';
		S.pop();
	}
}