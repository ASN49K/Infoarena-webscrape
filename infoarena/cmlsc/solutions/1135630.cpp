#include <cstdio>

#define MAX(a, b) ((a) >= (b))? (a) : (b)
#define MAX_NM 1024 + 1

int main()
{
    unsigned short a[MAX_NM], b[MAX_NM];
    unsigned int d[MAX_NM][MAX_NM];
    unsigned int n, m, r[MAX_NM], k, i, j;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%u %u", &n, &m);

    for (i = 1; i <= n; ++i)
    {
	scanf("%hu", &a[i]);
	d[i][0] = 0;
    }
    for (i = 1; i <= m; ++i)
    {
	scanf("%hu", &b[i]);
	d[0][i] = 0;
    }
    d[0][0] = 0;

    for (i = 1; i <= n; ++i)
    {
	for (j = 1; j <= m; ++j)
	{
	    if (a[i] == b[j])
	    {
		d[i][j] = d[i - 1][j - 1] + 1;
	    }
	    else
	    {
		d[i][j] = MAX(d[i - 1][j], d[i][j - 1]);
	    }
	}
    }

    i = n, j = m, k = 0;
    while (i || j)
    {
	if (a[i] == b[j])
	{
	    r[++k] = a[i];
	    --i;
	    --j;
	}
	else
	{
	    if (d[i][j] == d[i - 1][j])
	    {
		--i;
	    }
	    else
	    {
		--j;
	    }
	}
    }

    printf("%u\n", d[n][m]);
    for (i = k; i > 0; --i)
    {
	printf("%u ", r[i]);
    }

    return 0;
}
