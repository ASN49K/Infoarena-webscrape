#include <fstream>
#define max(a, b) (a > b) ? a : b
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, x[1025], y[1025], v[1025], a[1025][1025], maxx;
void citire();
void dinamica();
void retrace(int, int);
void scriere();

int main()
{
	citire();

	dinamica();

	fout << a[n][m] << '\n'; maxx = a[n][m];

	retrace(n, m);

	scriere();

	return 0;
}

void dinamica()
{
	int i, j;

	if (x[n] == y[m])
		a[n][m] = 1;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (x[i] == y[j])
				a[i][j] = a[i - 1][j - 1] + 1;
			else
				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
}

void retrace(int lin, int col)
{
	while (lin > 0 && col > 0)
	{
		if (x[lin] == y[col])
		{
			v[maxx--] = x[lin];
			lin--; col--;
		}
		else
			if (a[lin - 1][col] > a[lin][col - 1])
				lin--;
			else
				col--;
	}
}

void citire()
{
	int i;

	fin >> n >> m;

	for (i = 1; i <= n; i++)
		fin >> x[i];
	for (i = 1; i <= m; i++)
		fin >> y[i];
}

void scriere()
{
	int i;

	for (i = 1; i <= a[n][m]; i++)
		fout << v[i] << ' ';
	fout << '\n';
}