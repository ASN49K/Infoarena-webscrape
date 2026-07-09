#include <stdio.h>

int euc(int a, int b)
{
    if (!b) return a;
    return euc(b, a%b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int n, a, b;
    scanf("%d", &n);

    for (int i=1; i<=n; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", euc(a, b));
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
