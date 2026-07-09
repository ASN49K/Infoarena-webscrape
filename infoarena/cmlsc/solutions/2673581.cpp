#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1024], b[1024];
int dp[1025][1025];
/*void afisareMatrice(int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}*/
void subsir(int m, int n)
{
	if (m == 0 || n == 0)
	{
		return;
	}
	if (a[m - 1] == b[n - 1])
	{
		subsir(m - 1, n - 1);
		out << a[m - 1] << " ";
	}
	else
	{
		if (dp[m - 1][n] > dp[m][n - 1])
		{
			subsir(m - 1, n);
		}
		else
		{
			subsir(m, n - 1);
		}
	}
}
int main()
{
	int m, n;
	in >> m >> n;
	for (int i = 0; i < m; i++)
	{
		in >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		in >> b[i];
	}
	in.close();
	m++;
	n++;
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	out << dp[m - 1][n - 1] << endl;
	subsir(m - 1, n - 1);
	out.close();
	return 0;
}