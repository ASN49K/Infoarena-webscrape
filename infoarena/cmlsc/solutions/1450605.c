#include <stdio.h>
#include <stdlib.h>

#define maxim(a,b) ((a > b) ? a : b)
#define NMAX 1024
#define FOR(i,a,b) for(i = a; i <= b; ++i)

int main()
{
    int m, n, a[NMAX], b[NMAX], d[NMAX][NMAX], sir[NMAX], bst, i, j;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d", &m);
    scanf("%d", &n);

    FOR(i, 1, m)
        scanf("%d", &a[i]);

    FOR(i, 1, n)
        scanf("%d", &b[i]);

    FOR(i, 1 , m)
        FOR(j , 1 , n)
            if(a[i] == b[j])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = maxim(d[i-1][j], d[i][j-1]);
    for(i = m, j = n;  i; )
        if(a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
            else --i;

    printf("%d\n", bst);
    for(i = bst; i; --i)
        printf("%d ", sir[i]);

    return 0;
}
