#include <stdio.h>

#define nm 1025


int n, m, i, j;
int k;
int a[nm], b[nm], c[nm][nm], d[nm];

void read()

{
	scanf("%d %d ", &n, &m);
	for (i=1; i<=n; ++i)
	{
		scanf("%d ", &a[i]);
	}
	for (i=1; i<=m; ++i)
	{
		scanf("%d ", &b[i]);
	}
}


inline int MX(int a, int b) { return (a > b ? a : b); }


void solve()

{
	for (i=1; i<=n; ++i)
	{
		for (j=1; j<=m; ++j)
		{
			if (a[i] == b[j])
			{
				c[i][j] = c[i-1][j-1] + 1;
			}
			else
			{
				c[i][j] = MX(c[i][j-1], c[i-1][j]);
			}
		}
	}
	k = 0;
	for (i=n, j=m; i>0 && j>0;)
	{
		if (a[i] == b[j])
		{
			d[++k] = a[i];
			-- i;
			-- j;
		}
		else
		if (c[i-1][j] > c[i][j-1])
		{
			-- i;
		}
		else { -- j;}
	}
}


void write()

{
	printf("%d\n", k);
	for (i=k; i>0; --i)
	{
		printf("%d ", d[i]);
	}
}


int main()

{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out","w",stdout);

	read();
	solve();
	write();

	return 0;
}

