#include <iostream>
#include <fstream>
#define nmax 2000

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, mx = 0, d[nmax][nmax], a[nmax], b[nmax], e[nmax];

int main()
{
	int i, j;

	f >> m >> n;
	for(i = 1; i <= m; ++i)
		f >> a[i];
	for(i = 1; i <= n; ++i)
		f >> b[i];

	for(i = 1; i <= m; ++i)
		for(j = 1; j <= n; ++j)
			if(a[i] == b[j])
				d[i][j] = ++d[i-1][j-1];
			else
				d[i][j] = ((d[i-1][j] > d[i][j-1]) ? d[i-1][j] : d[i][j-1]);
	
	for(i = m, j = n; i;)
		if(a[i] == b[j])
			e[++mx] = a[i], --i, --j;
		else if (d[i-1][j] < d[i][j-1])
			--j;
		else 
			--i;
	
	g << mx << '\n';
	for(i = mx; i; --i)
		g << e[i] << ' ';
	g << '\n';
	return 0;
}
