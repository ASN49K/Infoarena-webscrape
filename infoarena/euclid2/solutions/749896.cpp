#include <cstdio>

int cmmdc(int a, int b)
{
    if (b)
        return cmmdc(b, a%b);
    return a;
}
int main()
{
    int T;
    int a, b;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }
    return 0;
}
