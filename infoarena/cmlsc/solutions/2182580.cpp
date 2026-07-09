#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short n, i, j, m, nrsecv[1025], k;
short x[1025], y[1025], c[1025][1025];
int main()
{
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		cin >> x[i];
	for (i = 1; i <= m; i++)
		cin >> y[i];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (x[i] == y[j]) 
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = __max(c[i][j - 1], c[i - 1][j]);
	for (i = n, j = m; i;)
		if (x[i] == y[j]) {
			nrsecv[++k] = x[i];
			--i;
			--j;
		}
		else
			if (c[i - 1][j] < c[i][j - 1])
				--j;
			else
				--i;
	cout << c[n][m] << "\n";
	for (i = k; i>=1; i--)
		cout << nrsecv[i] << " ";
    return 0;
}
