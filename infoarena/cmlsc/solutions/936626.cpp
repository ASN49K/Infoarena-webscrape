#include <fstream>
using namespace std;

int main() {
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	int m, n;
	f>>m>>n;
	int a[m+1], b[n+1];
	for (int i = 1; i <= m; ++i)
		f >> a[i];
	for (int i = 1; i <= n; ++i)
		f >> b[i];

	int c[m+1][n+1];
	for (int i = 0; i <= m; ++i)
		c[i][0] = 0;
	for (int i = 1; i <= n; ++i)
		c[0][i] = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i] == b[j]) c[i][j] = c[i-1][j-1]+1;
			else c[i][j] = max(c[i-1][j],c[i][j-1]);
		}
	}
	int nr = c[m][n];
	int v[nr];
	for (int i = m, j = n, k = nr; k > 0;) {
		if (a[i] == b[j]) {
			v[--k] = a[i];
			--i;
			--j;
		}
		else {
			if (c[i-1][j] >= c[i][j-1]) --i;
			else --j;
		}
	}
	g << nr << '\n';
	for (int i = 0; i < nr; ++i)
		g << v[i] << ' ';
	return 0;
}
