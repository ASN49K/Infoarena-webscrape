#include <stdio.h>

int euclid(int a, int b)
{
    if (!b) return(a);
    return(euclid(b, a % b));
}

int main()
{
    int n, a, b;

    freopen("euclid2.in", "rt", stdin);
    freopen("euclid2.out", "wt", stdout);

    scanf("%d", &n);

    for (; n; --n)
    {
	scanf("%d %d", &a, &b);
	printf("%d\n", euclid(a,b));
    }
    return (0);
}

