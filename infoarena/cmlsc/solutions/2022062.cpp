#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[1025], b[1025], d[1025][1025], s[1025];
int i, j, m, n, k;

int main ()	{
	fin >> m >> n;
	for (i = 1; i <= m; i++)
		fin >> a[i];
	for (j = 1; j <= n; j++)
		fin >> b[j];
	for (i = 1; i <= m; i++)	{
		for (j = 1; j <= n; j++)	{
			if (a[i] == b[j]) d[i][j] = d[i - 1][j - 1] + 1;
			else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}
	fout << d[m][n] << '\n';
	for (i = m, j = n; d[i][j] != 0;)	{
		if (a[i] == b[j])
			s[++k] = a[i], i--, j--;
		else if (d[i - 1][j] < d[i][j - 1]) j--;
		else i--;
	}
	for (i = k; i; i--)
		fout << s[i] << ' ';
}

