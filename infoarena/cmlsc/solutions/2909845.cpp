#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int16_t N = 1024;

int16_t m, n, i, j;
int16_t a[N + 5], b[N + 5], rez[N + 5];
int16_t d[N + 5][N + 5];

void lcs() {
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (a[i] == b[j]) d[i][j] = d[i - 1][j - 1] + 1;
			else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
}

void prt() {
	i = n, j = m;
	int k = 0;
	while (d[i][j]) {
		if (d[i][j] == d[i - 1][j]) i--;
		else if (d[i][j] == d[i][j - 1]) j--;
		else
		{
			rez[++k] = a[i];
			if (d[i][j] == d[i - 1][j] + 1) i--;
			else j--;
		}
	}
	for (; k; k--) g << rez[k] << ' ';
}

int main()
{
	f >> n >> m;
	for (i = 1; i <= n; i++) f >> a[i];
	for (i = 1; i <= m; i++) f >> b[i];

	lcs();
	g << d[n][m] << '\n';
	prt();

	return 0;
}