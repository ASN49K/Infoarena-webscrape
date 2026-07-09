#include <bits/stdc++.h>
using namespace std;
#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define lim 1024
int m, n, a[lim], b[lim], d[lim][lim], drum[lim], best;
int main()
{
    int i, j;
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &m, &n);
    FOR (i, 1, m)
        scanf("%d", &a[i]);
    FOR (i, 1, n)
        scanf("%d", &b[i]);
    FOR (i, 1, m)
        FOR (j, 1, n)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = maxim(d[i-1][j], d[i][j-1]);
    for (i = m, j = n; i; )
        if (a[i] == b[j])
            drum[++best] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
    printf("%d\n", best);
    for (i = best; i; --i)
        printf("%d ", drum[i]);
    return 0;
}
