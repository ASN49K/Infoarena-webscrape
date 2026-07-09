#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
#define Nmax 1024
#define max(a,b) ((a>b)? a:b)
int a[Nmax][Nmax], v1[Nmax], v2[Nmax],sir[Nmax],k;

int main()
{
	int i, j, n, m;
	fi >> n >> m;
	for (i = 1; i <= n; ++i)
		fi >> v1[i];
	for (i = 1; i <= m; ++i)
		fi >> v2[i];
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
		{
			if (v1[i] == v2[j])
				a[i][j] = a[i - 1][j - 1] + 1;
			else
				a[i][j] = max(a[i][j - 1], a[i - 1][j]);
		}
	for (i = n,j = m; i;)
	{
		if (v1[i] == v2[j])
			sir[++k] = v1[i], --i, --j;
		else if (a[i - 1][j] < a[i][j - 1])
			--j;
		else --i;
	}
	fo << k << " \n";
	for (i = k; i>=1; --i)
		fo << sir[i] << " ";
	return 0;
}