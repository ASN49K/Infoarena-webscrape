#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1025][1025], a[1030], b[1030], c[1030], m, n;

int main()
{

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);

    for(int i=1; i<=m; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i=1; i<=n; i++)
    {
        scanf("%d", &b[i]);
    }

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
            {
                dp[i][j]=max(max(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]);
            }
        }
    }/*
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }*/
    int i=m, j=n;
    while(dp[i][j]!=0)
    {
        if(a[i]==b[j])
        {
            c[++c[0]]=a[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    printf("%d\n", dp[m][n]);
    for(int i=c[0]; i>=1; i--)
        printf("%d ", c[i]);
    return 0;
}
