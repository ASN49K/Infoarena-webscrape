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

void scrie(int i,int j)
{
	if(i==0 || j==0)
		return;
	if(s[i] == t[j])
	{
		scrie(i-1,j-1);
		printf("%d ",s[i]);
		return;
	}
	if(a[i][j-1] > a[i-1][j])
		scrie(i,j-1);
	else
		scrie(i-1,j);
}

void afisare()
{
	printf ("%hd\n",a [m][n]);
	scrie(m,n);
}

int main()
{
	freopen ("cmlsc.in","r",stdin);
	freopen ("cmlsc.out","w",stdout);
	citire();
	parcurgere();
	afisare();
}
