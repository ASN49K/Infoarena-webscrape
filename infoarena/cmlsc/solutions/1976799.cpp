#include <iostream>
#include <fstream>
#define NMAX 1023

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int x[NMAX], y[NMAX], m, n, c[NMAX][NMAX], i, j;
void afisare(int i, int j)
{
	if (i >= 0 && j >= 0)
	{
		if (x[i] == y[j])
		{
			afisare(i - 1, j - 1);
			g << x[i] << " ";
		}
		else if (c[i][j - 1] > c[i - 1][j])
			afisare(i, j - 1);
		else
			afisare(i - 1, j);
	}
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	
	f >> m >> n;
	for ( i = 0; i < m; i++)
		f >> x[i];
	for ( j = 0; j < n; j++)
		f >> y[j];
	f.close();
	for(i=0;i<m;i++)
		for (j = 0; j < n; j++)
		{
			if (x[i] == y[j])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = max(c[i][j - 1], c[i - 1][j]);
		}
	g << c[m][n] << '\n';
	afisare(m, n);
	g.close();
	
	return 0;
}