#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, i, j, m, nrsecv[1024], k;
int x[1024], y[1024], c[1025][1025];
int main()
{
	fin >> n >> m;
	for (i = 1; i <= n; i++)
		fin >> x[i];
	for (i = 1; i <= m; i++)
		fin >> y[i];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (x[i] == y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				nrsecv[++k] = x[i];
			}
			else
				c[i][j] = max(c[i][j - 1], c[i - 1][j]);
	fout << c[n][m] << "\n";
	for (i = 1; i <= k; i++)
		fout << nrsecv[i] << " ";
    return 0;
}
