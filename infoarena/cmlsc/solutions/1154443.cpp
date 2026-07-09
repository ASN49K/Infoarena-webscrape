#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, lg, sir[1100], x[1100], y[1100], a[1100][1100];

int main()
{
	int i, j;

	fin >> n >> m;
	for (i=1;i<=n;i++)
		fin >> x[i];
	for (i=1;i<=m;i++)
		fin >> y[i];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (x[i] == y[j])
				a[i][j] = a[i-1][j-1]+1;
			else
				a[i][j] = max(a[i-1][j],a[i][j-1]);
	for (i=n,j=m;i>0;)
		if (x[i] == y[j])
			sir[++lg] = x[i],i--,j--;
		else if (a[i-1][j] > a[i][j-1])
			i--;
		else
			j--;
	fout << lg << '\n';
	for (i=lg;i>=1;i--)
		fout << sir[i] << ' ';
	return 0;
}