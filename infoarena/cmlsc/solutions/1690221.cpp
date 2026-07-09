#include <stdio.h>
#define maxim(a, b)((a>b)?a:b)
#define FOR(i, a, b) for (i=a; i<=b; ++i)
#define nmax 1024
int m, n, a[nmax], b[nmax], d[nmax][nmax], sir[nmax], best;
int main(void)
{
    int i, j;
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &n, &n);
    FOR(i, 1, m)
        scanf("%d", &a[i]);
    FOR(i, 1, n)
        scanf("%d", &b[i]);
    FOR(i, 1, m)
        FOR(j, 1, n)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=maxim(d[i-1][j], d[i][j-1]);
    for(i=m, j=n; i;)
        if (a[i]==b[j])
            sir[++best]=a[i], --i, --j;
        else if (d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    printf("%d\n", best);
    for (i=best; i; --i)
        printf("%d ", sir[i]);
    return 0;
}
