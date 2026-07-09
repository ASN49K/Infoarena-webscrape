#include<iostream>
#include<fstream>
using namespace std;

enum Direction {up, left1, diagonal};

int c[1025][1025];
Direction b[1025][1025];

int x[1024], y[1024];

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void print_lcs(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == diagonal)
	{
		print_lcs(i - 1, j - 1);
		g << x[i] << " ";

	}
	else if (b[i][j] == up)
		print_lcs(i - 1, j);
	else
		print_lcs(i, j - 1);
}

int main()
{
	int m = 0, n = 0;
	f >> m >> n;
	for (int i = 1; i <= m; i++)
		f >> x[i];
	for (int i = 1; i <= n; i++)
		f >> y[i];
	f.close();
	for(int i=1;i<=m;i++)
		for (int j = 1; j <= n; j++)
		{
			if (x[i] == y[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = diagonal;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = up;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = left1;
			}
		}

	g << c[m][n] << endl;
	print_lcs(m, n);
	g.close();
	return 0;
}