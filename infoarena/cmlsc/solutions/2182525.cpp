#include <iostream>
using namespace std;

int n, i, j, m, nrsecv[1024], k;
int x[1024], y[1024], c[1025][1025];
int main()
{
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		cin >> x[i];
	for (i = 1; i <= m; i++)
		cin >> y[i];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (x[i] == y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				nrsecv[++k] = x[i];
			}
			else
				c[i][j] = __max(c[i][j - 1], c[i - 1][j]);
	cout << c[n][m] << "\n";
	for (i = 1; i <= k; i++)
		cout << nrsecv[i] << " ";
	cin >> n;
}