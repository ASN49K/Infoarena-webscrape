#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

unsigned char v1[1025], v2[1025], v[2050];
int n, m, d[1025][1025];

int maxx(int x, int y)
{
	return (x > y ? x : y);
}

void cmlsc()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (v1[i] == v2[j])
			{
				d[i][j] = d[i - 1][j - 1] + 1;
				v[d[i][j]] = v1[i];
			}
			else d[i][j] = maxx(d[i - 1][j], d[i][j - 1]);
		}
	}
}

int main()
{
	f >> n >> m;
	int x;
	for (int i = 1; i <= n; i++)
		f >> x, v1[i] = x;
	for (int i = 1; i <= m; i++)
		f >> x, v2[i] = x;
	cmlsc();
	g << d[n][m] << '\n';
	for (int i = 1; i <= d[n][m]; i++)
		g << (int)v[i] << " ";
	return 0;
}