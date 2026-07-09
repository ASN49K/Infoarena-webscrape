#include <iostream>
#include <fstream>
#define Nmax 1024
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m, n, a[Nmax], b[Nmax], subsir[Nmax],c[Nmax][Nmax];

int maxim(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}

int main()
{
	f >> m >> n;
	for (int i = 0; i < m; i++)
	{
		f >> a[i];
	}
	for (int j = 0; j < n; j++)
	{
		f >> b[j];
	}
	

	for(int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			if(a[i]==b[j])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = maxim(c[i - 1][j], c[i][j - 1]);
		}
	int i = m;
	int j = n;
	int k = 0;
	while (i >= 1 && j >= 1)
		if (a[i] == b[j])
		{
			subsir[++k] = a[i];
			--i;
			--j;
		}
		else
			if (c[i - 1][j]>c[i][j - 1])
				--i;
			else
				--j;
	g << k<<'\n';
	for (int i = 0; i < k; i++)
	{
		g << subsir[i];
	}
	
	return 0;
}