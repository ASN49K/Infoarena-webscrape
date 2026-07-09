//https://infoarena.ro/problema/cmlsc
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("fast-math")
#pragma GCC optimize ("unroll-loops")
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int d[1500][1500],a[1500], b[1500];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, i, j;
	vector <int> rez;
	fin >> n >> m;
	for (i = 0; i < n; ++i)
	{
		fin >> a[i];
	}
	for (i = 0; i < m; ++i)
	{
		fin >> b[i];
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= m; ++j)
		{
			if (a[i - 1] == b[j - 1])
			{
				d[i][j] = 1 + d[i - 1][j - 1];
			}
			else
			{
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}
	fout << d[n][m]<<"\n";

	i = n;
	j = m;
	while (i>0 && j>0)
	{
		if (a[i - 1] == b[j - 1])
		{
			rez.push_back(a[i - 1]);
			--i;
			--j;
		}
		else if (d[i - 1][j] > d[i][j - 1])
		{
			--i;
		}
		else
		{
			--j;
		}
	}
	reverse(rez.begin(), rez.end());
	for (auto x:rez)
	{
		fout << x << " ";
	}

	return 0;
}
