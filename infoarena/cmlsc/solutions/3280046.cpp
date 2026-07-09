#include<fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int const nmax = 1025;
int a[1025], b[1025], c[1025][1025], n, m, x, ans[1025];

int main()
{
	f >> n >> m;
	for (int i = 1; i <= n; i++)
		f >> a[i];
	for (int j = 1; j <= m; j++)
		f >> b[j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (b[j] == a[i])
				c[i][j] = c[i - 1][j - 1] + 1;
			else c[i][j] = max(c[i - 1][j], c[i][j - 1]);
		}
	}
	int i = n, j = m;
	while (c[i][j])
	{
		while (c[i][j] == c[i - 1][j])
			i--;
		while (c[i][j] == c[i][j - 1])
			j--;
		x++;
		ans[x] = a[i];
		i--;
		j--;
	}
	g << c[n][m] << '\n';
	for (int i = x; i >= 1; i--)
		g << ans[i] << " ";
}