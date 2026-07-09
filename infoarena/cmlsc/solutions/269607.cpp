#include <stdio.h>

#define nmax 1027


short int n, m;
short int a [nmax], b [nmax];
short int c [nmax] [nmax];


void scan ()
{
	int i;
	scanf ("%hd%hd", &n, &m);
	for (i=1; i <= n; ++i)
		scanf ("%hd", &a [i]);
	for (i=1; i <= m; ++i)
		scanf ("%hd", &b [i]);
}

inline short int max (short int a, short int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void cmlsc ()
{
	int i, j;
	for (i=1; i <= n; ++i)
		for (j=1; j <= m; ++j)
			if (a [i] == b [j])
				c [i] [j]=c [i-1] [j-1]+1;
			else
				c [i] [j]=max (c [i] [j-1], c [i-1] [j]);
}

void rec (short int x, short int y)
{
	if (x == 0 || y == 0)
		return;
	if (a [x] ==  b [y])
	{
		rec (x-1, y-1);
		printf ("%hd ", a [x]);
	}
	else
		{
			if (c [x] [y-1] > c [x-1] [y])
				rec (x, y-1);
			else
				rec (x-1, y);
		}

}

int main ()
{
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	scan ();
	cmlsc ();
	printf ("%hd\n", c [n] [m]);
	rec (n, m);
	printf ("\n");
	return 0;
}
