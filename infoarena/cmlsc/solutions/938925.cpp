#include<fstream>
#include<iostream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void afisare(int **c, int m, int n, int *x)
{
	if(m != 0 && n != 0)
	{
		if(c[m][n] > c[m-1][n] && c[m][n] > c[m][n-1])
		{
			afisare(c, m-1, n-1, x);
			fout << x[m] << " ";
		}
		else 
		{
			if(c[m][n] > c[m][n-1])
				afisare(c, m-1, n, x);
			else
				afisare(c, m, n-1, x);
		}
	}
}

int main()
{
	
	int n, m, **c, *x, *y, i, j;
	fin >> m >> n;
	c = new int*[m + 1];
	for(i = 0; i < m+1; i++)
		c[i] = new int[n + 1];
	x = new int[m + 1];
	y = new int[n + 1];
	for(i = 1; i < m + 1; i++)
		fin >> x[i];
	for(i = 1; i < n + 1; i++)
		fin >> y[i];
	for(i = 1; i <= m; i++)
	{
		c[i][0] = 0; 
	}
	for(i = 0; i <= n; i++)
		c[0][i] = 0;
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(x[i] == y[j])
			{
				c[i][j] = c[i-1][j-1] + 1;
			}
			else
			{
				if(c[i-1][j] >= c[i][j-1])
					c[i][j] = c[i-1][j];
				else
					c[i][j] = c[i][j-1];
			}
		}
	}
	fout << c[m][n] << endl;
	afisare(c, m, n, x);
	return 0;
}

