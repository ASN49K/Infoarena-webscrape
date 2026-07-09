#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int A[1025][1025], i, j, n, m, a[1025], b[1025], v[1025];

int main()
{	f>>n>>m;
	for (i=1; i<=n; ++i) f>>a[i];
	for (j=1; j<=m; ++j) f>>b[j];
	for (i=1; i<=n; ++i)
		for (j=1; j<=m; ++j)
			if (a[i]==b[j]) A[i][j]=1+A[i-1][j-1];
			else A[i][j]=max(A[i-1][j], A[i][j-1]);
	i=j=n;
	g<<A[n][m]<<'\n';
	while (i && j)
	{	if (a[i]==b[j])
		{	v[++v[0]]=a[i];
			--i;
			--j;
		}
		else
		{	if (A[i-1][j]>A[i][j-1]) --i;
			else --j;
		}
	}
	for (i=v[0]; i>=1; --i) g<<v[i]<<' ';
    return 0;
}
