#include <fstream>
#include <stack>
#include <vector>
using namespace std;
string file = "cmlsc";
ifstream cin(file + ".in");
ofstream cout(file + ".out");
int a[1025], b[1025], dp[1025][1025],n,m;
void refac_subsir(int l, int c)
{
	if (l == 0 || c == 0)
		return;
	if (a[l] == b[c])
	{
		refac_subsir(l - 1, c - 1);
		cout << a[l] << ' ';
	}
	else if (dp[l - 1][c] > dp[l][c - 1])
	{
		refac_subsir(l - 1, c);
	}
	else
	{
		refac_subsir(l, c - 1);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[n][m] << '\n';
	refac_subsir(n, m);
}