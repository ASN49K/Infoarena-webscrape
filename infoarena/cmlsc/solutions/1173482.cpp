#include <iostream>
#include <fstream>

using namespace std;

#define MAX(a, b) (a) > (b) ? a : b

int a[1025], b[1025], n, m, d[1025][1025], ans = 0, i, j;
int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");

	f >> n >> m;
	for (i = 1; i <= n; ++i) f >> a[i];
	for (i = 1; i <= m; ++i) f >> b[i];

	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j) 
			if (a[i] == b[j]) 
				d[i][j] = d[i-1][j-1] + 1;
			else 
				d[i][j] = MAX(d[i-1][j], d[i][j-1]);

	g << d[n][m] << "\n";
	int last = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (d[i][j] != last) {
				g << a[i] << " ";
				last = d[i][j];
			}
	return 0;
}
