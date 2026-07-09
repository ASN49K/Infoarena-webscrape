#include <fstream>
#include <vector>

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int n, m, sol, maxx;

int main()
{
	cin >> n >> m;
	vector<int> a (n + 1);
	vector<int> b (m + 1);
	vector<vector<int>> dp (n + 1, vector<int> (m + 1));
	vector<int> c (max (n, m) + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
			}
		}
	}

	sol = dp[n][m]; maxx = sol;
	cout << sol << '\n';

	if (!sol)
	{
		cin.close();
		cout.close();
		return 0;
	}

	int i = n, j = m;

	while (maxx)
	{
		if (dp[i - 1][j] == maxx)
		{
			i--;
			continue;
		}

		if (dp[i][j - 1] == maxx)
		{
			j--;
			continue;
		}

		c[maxx] = a[i];
		maxx--;
		i--;
		j--;
	}

	for (i = 1; i <= sol; i++)
	{
		cout << c[i] << " ";
	}

	cout << '\n';
    cin.close();
    cout.close();
	return 0;
}
