#include<stdio.h>
#include<fstream>
#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 
#pragma warning(disable:4996)
int m, n, a[1024], b[1024], d[1024][1024], sir[1024], bz;
int max(int a,int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main(void)
{
	std::ifstream f("cmlsc.in");
	std::ofstream o("cmlsc.out");
	int i, j;
	f >> n >> m;
	for (i = 1; i <= n; ++i)
		f >> a[i];
	for (i = 1; i <= m; i++)
		f >> b[i];
	for ( i = 1; i <= n; ++i)
		for ( j = 1; j <= m; ++j)
			if (a[i] == b[j])
				d[i][j] = 1 + d[i - 1][j - 1];
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
	for ( i = n, j = m; i; )
		if (a[i] == b[j])
			sir[++bz] = a[i], --i, --j;
		else if (d[i - 1][j] < d[i][j - 1])
			--j;
		else
			--i;
	o << bz << '\n';
	for (int i = bz; i; --i)
		o << sir[i] << ' ';
	return 0;
}