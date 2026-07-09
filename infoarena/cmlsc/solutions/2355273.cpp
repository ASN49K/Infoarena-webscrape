#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int v1[1025], v2[1025], n, m, d[1025][1025];

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
				d[i][j] = d[i - 1][j - 1] + 1;
			else d[i][j] = maxx(d[i - 1][j], d[i][j - 1]);
		}
	}
}

void print_sol(int i, int j)
{
	bool ok = 0;
	if (i * j == 0)
		return;
	if (v1[i] == v2[j])
	{
		ok = 1;
		print_sol(i - 1, j - 1);
	}
	else if (d[i][j - 1] > d[i - 1][j])
		print_sol(i, j - 1);
	else print_sol(i - 1, j);
	if (ok) g << (int)v1[i] << " ";
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
	print_sol(n, m);
	return 0;
}