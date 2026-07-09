#include <cstdio>
#include <algorithm>
#define nmax 1200

using namespace std;

int i, n, m, j, k;
int a[nmax], b[nmax], dp[nmax][nmax], sol[nmax];

int main()
{
    freopen("cmlsc.in", "rt", stdin);
    freopen("cmlsc.out", "wt", stdout);

    scanf("%d%d", &n, &m);

    for(i=1; i<=n; ++i)
        scanf("%d", &a[i]);

    for(j=1; j<=m; ++j)
        scanf("%d", &b[j]);

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);


    for(i=n, j=m, k=0; i; )
    if(a[i]==b[j]) sol[++k]=a[i], --i, --j;
    else if(dp[i-1][j]<dp[i][j-1]) --j;
            else --i;

    printf("%d\n", k);

    for(i=k; i; --i)
        printf("%d ", sol[i]);

    return 0;
}
