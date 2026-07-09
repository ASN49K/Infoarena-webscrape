#include <cstdio>

const int M = 1025, N = 1025;

short s[M],t[N],m,n,a[M][N];

short max (short a, short b)
{
	if (a > b)
		return a;
	return b;
}

void parcurgere()
{
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (s [i] == t [j])
				a [i][j] = a [i-1][j-1] + 1;
			else
				a [i][j] = max (a [i-1][j], a[i][j-1]);
}

void citire()
{
	int i;
	scanf ("%hd%hd",&m,&n);
	for (i = 1; i <= m; ++i)
		scanf ("%hd",&s[i]);
	for (i = 1; i <= n; ++i)
		scanf ("%hd",&t[i]);
}

void afisare()
{
	printf ("%hd\n1 1 1\n",a [m][n]);
}

int main()
{
	freopen ("cmlsc.in","r",stdin);
	freopen ("cmlsc.out","w",stdout);
	citire();
	parcurgere();
	afisare();
}
