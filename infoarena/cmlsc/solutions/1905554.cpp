#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, nr, sol[1100], a[1100], b[1100], rez[1100][1100];

int main()
{
	int i, j;

	fin >> n >> m;
	for (i = 1; i <= n; i++)
		fin >> a[i];
	for (i = 1; i <= m; i++)
		fin >> b[i];
	for (i=1;i<=n;i++)
		for (j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
				rez[i][j] = 1 + rez[i - 1][j - 1];
			else
				rez[i][j] = max(rez[i - 1][j], rez[i][j - 1]);
		}
	i = n; j = m;
	while (nr < rez[n][m])
	{
		if (a[i] == b[j])
		{
			sol[++nr] = a[i];
			i--;
			j--;
		}
		else if (rez[i - 1][j] > rez[i][j - 1])
			i--;
		else j--;
	}
	fout << rez[n][m] << '\n';
	for (i = nr; i >= 1; i--)
		fout << sol[i] << ' ';
	fout << '\n';
	return 0;
}