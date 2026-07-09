#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int c[1025][1025], b[1025][1025];
int x[1025], y[1025];
int n, m;


void Citire()
{
	f >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		f >> x[i];
	}

	for (int i = 1; i <= n; i++)
	{
		f >> y[i];
	}
}

void LungimeCmlsc()
{
	for (int i = 1; i <= m; i++)
	{
		c[i][0] = 0;
	}
	for (int i = 0; i <= n; i++)
	{
		c[0][i] = 0;
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (x[i] == y[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else
			{
				if (c[i - 1][j] > c[i][j - 1])
				{
					c[i][j] = c[i - 1][j];
					b[i][j] = 2;
				}
				else
				{
					c[i][j] = c[i][j - 1];
					b[i][j] = 3;
				}
			}
		}
	}
}

void ScrieCmlsc(int i, int j)
{
	if (i != 0 && j != 0)
	{
		if (b[i][j] == 1)
		{
			ScrieCmlsc(i - 1, j - 1);
			g << x[i] << " ";
		}
		else
		{
			if (b[i][j] == 2)
			{
				ScrieCmlsc(i - 1, j);
			}
			else
			{
				ScrieCmlsc(i, j - 1);
			}
		}
	}
}

int main()
{
	Citire();
	LungimeCmlsc();

	g << c[m][n] << "\n";

	ScrieCmlsc(m, n);
}
