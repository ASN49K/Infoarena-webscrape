#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025], b[1025], m, n;
int c[1025][1025];
void generare(int c[1025][1025], int a[1025],int b[1025])
{
	for (int i = 1; i <= m; i++)
		c[0][i] = 0;
	for (int i = 1; i <= n; i++)
		c[i][0] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i] == b[j])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = max(c[i][j-1], c[i-1][j]);
}
void reconstruire(int c[1025][1025], int a[1025], int b[1025], int i, int j)
{
	if (i == 0 or j == 0)
	{
		return ;
	}
	if (a[i] == b[j])
	{
		reconstruire(c, a, b, i - 1, j - 1);
		g << a[i] << ' ';
	}
	else
		if (c[i][j-1] > c[i-1][j])
			reconstruire(c, a, b, i, j-1);
		else
			reconstruire(c, a, b, i-1, j);
}
int main()
{

	f >> m >> n;
	for (int i=1; i<=m; i++)
		f >> a[i];
	for (int i = 1; i <= n; i++)
		f >> b[i];
	generare(c,a,b);
	g << c[m][n] << '\n';
	reconstruire(c,a,b,m,n);
	return 0;
}
