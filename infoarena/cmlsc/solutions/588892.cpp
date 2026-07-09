
#include <cstdio>
#define nmax  1024
//#define for(i, a, b) for (i = a; i <= b; ++i)
#define maxim(a, b) ((a > b) ? a : b)
using namespace std;
int m, n, a[nmax], b[nmax], d[nmax][nmax], sir[nmax], bst;

int main(){
    int i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d", &m, &n);
    for (i=1;i<=m;++i) scanf("%d", &a[i]);
    for (i=1;i<=n;++i) scanf("%d", &b[i]);

    for (i=1;i<=m;++i)
        for (j=1;i<=n;++i)
            if ( a[i] == b[j] ) d[i][j] = 1 + d[i-1][j-1];
            else d[i][j] = maxim( d[i-1][j], d[i][j-1] );

    for (i = m, j = n; i; )
        if ( a[i] == b[j] ) sir[++bst] = a[i], --i, --j;
        else if ( d[i-1][j] < d[i][j-1] ) --j;
        else --i;

    printf("%d\n", bst);
    for (i = bst; i; --i) printf("%d ", sir[i]);

    return 0;
}
/*
#include <stdio.h>

#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1024

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main(void)
{
    int i, j;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &M, &N);
    FOR (i, 1, M)
        scanf("%d", &A[i]);
    FOR (i, 1, N)
        scanf("%d", &B[i]);

    FOR (i, 1, M)
        FOR (j, 1, N)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);

    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

    printf("%d\n", bst);
    for (i = bst; i; --i)
        printf("%d ", sir[i]);

    return 0;
}
*/



