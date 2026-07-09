#include <stdio.h>

int i, n, a, b;

int eu(int a, int b)
{
    if (b) return(eu(b, a % b));
    else return(a);
}

int main()
{
    freopen("euclid2.in", "rt", stdin);
    freopen("euclid2.out", "wt", stdout);

    scanf("%d", &n);

    for (i = 1; i <= n; ++i)
    {
	scanf("%d %d", &a, &b);
	printf("%d\n", eu(a,b));
    }

    return(0);
}
