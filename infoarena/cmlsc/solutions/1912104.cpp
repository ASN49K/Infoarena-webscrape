#include <fstream>
#define N 1025
using namespace std;

int n, m;
int v[N], w[N], a[N][N];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void citire()
{
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
		fin >> v[i];
	for (int i = 1; i <= m; i++)
		fin >> w[i];
	fin.close();
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

void build()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (v[i] == w[j]) a[i][j] = a[i - 1][j - 1] + 1;
			else
				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
	fout << a[n][m] << '\n';
}

void trace(int i, int j)
{
	if (!a[i][j]) return;
	if (a[i][j] == a[i - 1][j - 1] + 1)
	{
		trace(i - 1, j - 1);
		fout << v[i] << " ";
	}
	else
		if (a[i][j] == a[i - 1][j]) trace(i - 1, j);
		else trace(i, j - 1);
}

int main()
{
	citire();
	build();
	trace(n,m);
	return 0;
}