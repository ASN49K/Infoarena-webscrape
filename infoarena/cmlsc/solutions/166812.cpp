#include <stdio.h>

long n, m, i, j, x[1025], y[1025], a[1025][1025];

inline long max(long a, long b)
{
	return a > b ? a : b;
}

void switch_(long a[], long n)
{
	long aux;
	for (long i = 1; i <= n / 2; i ++)
		aux = a[i], a[i] = a[n - i + 1], a[n - i + 1] = aux;
}

int main()
{
	freopen ("cmlsc.in", "rt", stdin);
	freopen ("cmlsc.out", "wt", stdout);

	scanf("%ld %ld", &n, &m);
	for (i = 1; i <= n; ++i)
		scanf("%ld", &x[i]);
	switch_(x, n);

	for (i = 1; i <= m; ++i)
		scanf("%ld", &y[i]);
	switch_(y, m);

	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
		{
			if (x[i] == y[j])
				a[i][j] = a[i - 1][j - 1] + 1;
			else
				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
		}

	printf("%ld\n", a[n][m]);

	i = n;
	j = m;
	while (i && j)
	{
		if (x[i] == y[j])
		{
			printf("%ld ", x[i]);
			i --, j --;
		}
		else
		{
			if (a[i - 1][j] > a[i][j - 1])
				i --;
			else
				j --;
		}
	}

	printf("\n");
	return 0;
}