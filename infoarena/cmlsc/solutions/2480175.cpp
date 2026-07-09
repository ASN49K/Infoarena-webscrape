#include<fstream>
#include<iostream>
#define MAX 1025

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[MAX], b[MAX], c[MAX + 1][MAX + 1], d[MAX], m, n;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	
	f >> m >> n;
	for (int i = 0; i < m; ++i)
	{
		f >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		f >> b[i];
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[i] == b[j])
			{
				c[i + 1][j + 1] = 1 + c[i][j];
			}
			else
			{
				c[i + 1][j + 1] = max(c[i][j + 1], c[i + 1][j]);
			}
		}
	}
	int i = m - 1, j = n - 1, k = 0;
	while (c[i+1][j+1] != 0)
	{
		if (c[i][j+1] < c[i+1][j])
		{
			if (c[i+1][j+1] != c[i+1][j])
			{
				d[k] = a[i];
				k++;
			}
			j = j - 1;
		}
		else
		{
			if (c[i+1][j+1] != c[i][j+1])
			{
				d[k] = b[j];
				k++;
			}
			i = i - 1;
		}
	}
	g << c[m][n] << endl;
	for (k = k - 1; k > 0; --k)
	{
		g << d[k] << ' ';
	}
	g << d[0] << endl;
}