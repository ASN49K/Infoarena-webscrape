#include <fstream>
#define max(a, b) (a > b) ? a : b
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

struct pre
{
	int x, y;
};

struct cmlsc
{
	int nr;
	pre poz;
} a[1025][1025];

int n, m, x[1025], y[1025], v[1025], maxx;
void citire();
void dinamica();
void retrace(int, int);
void scriere();

int main()
{
	citire();

	dinamica();

	fout << a[n][m].nr << '\n'; maxx = a[n][m].nr;

	retrace(n, m);

	scriere();

	return 0;
}

void dinamica()
{
	int i, j;

	if (x[n] == y[m])
		a[n][m].nr = 1;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (x[i] == y[j])
			{
				a[i][j].nr = a[i - 1][j - 1].nr + 1;
				a[i][j].poz.x = i - 1;
				a[i][j].poz.y = j - 1;
			}
			else
			{
				a[i][j].nr = max(a[i - 1][j].nr, a[i][j - 1].nr);
				if (a[i - 1][j].nr > a[i][j - 1].nr)
				{
					a[i][j].nr = a[i - 1][j].nr;
					a[i][j].poz.x = a[i - 1][j].poz.x;
					a[i][j].poz.y = a[i - 1][j].poz.y;
				}
				else
				{
					a[i][j].nr = a[i][j - 1].nr;
					a[i][j].poz.x = a[i][j - 1].poz.x;
					a[i][j].poz.y = a[i][j - 1].poz.y;
				}
			}
}

void retrace(int lin, int col)
{
	if (lin > 0 && col > 0)
	{
		v[maxx--] = x[lin];

		retrace(a[lin][col].poz.x, a[lin][col].poz.y);
	}
}

void citire()
{
	int i, j;

	fin >> n >> m;

	for (i = 1; i <= n; i++)
		fin >> x[i];
	for (i = 1; i <= m; i++)
		fin >> y[i];
}

void scriere()
{
	int i;

	for (i = 1; i <= a[n][m].nr; i++)
		fout << v[i] << ' ';
	fout << '\n';
}