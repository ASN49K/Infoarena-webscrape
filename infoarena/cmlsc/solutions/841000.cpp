
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define MAX 1024

int main()
{
	int m, n, sc[MAX];
	ifstream f("cmlsc.in");
	ofstream g("clmsc.out");
	f>>m>>n;
	int a[m], b[n], c[m + 1][n + 1], d[m + 1][n + 1], i, j;
	
	for (i = 1; i<=m; i++)
	{
		c[i][0] = 0;
		f>>a[i];
	}
	
	for (i = 1; i<=n; i++)
	{
		c[0][i] = 0;
		f>>b[i];
	}
	f.close();
	c[0][0] = 0;
	int diri[3] = {-1, 0, -1}, dirj[3] = {0, -1, -1};
	
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			if (a[i] == b[j]){
				c[i][j] = 1 + c[i-1][j-1];
				d[i][j] = 2;
			} else if (c[i][j-1] >= c[i-1][j]){
				c[i][j] = c[i][j-1];
				d[i][j] = 1;
			} else{
				c[i][j] = c[i-1][j];
				d[i][j] = 0;
			}
			
	g<<c[m][n]<<endl;;
	int di = diri[d[m][n]], dj = dirj[d[m][n]];
	i = m; j = n;
	int val = c[i][j];
	int cont = c[m][n] - 1;
	
	while (c[i][j] > 0)
	{
		if (val != c[i][j])
		{
			sc[cont] = a[i+1];
			val = c[i][j];
		}
		i += di; 
		j += dj;
		if (i > 0 && j > 0)
		{
			di = diri[d[i][j]]; 
			dj = dirj[d[i][j]];
		}
	}
	sc[0] = a[i+1];
	for (i = 0; i < c[m][n]; i++)
		g<<sc[i]<<" ";
	g.close();
	
	return 0;
}
