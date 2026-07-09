#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int a[1025], b[1025];
int dp[1025][1025]={0};
int k[1024], kk=1;
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d ", &a[i]);
    for(int i=1; i<=m; i++)
        scanf("%d ", &b[i]);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(max(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
        }

    printf("%d\n", dp[n][m]);

    int i=n;
    int j=m;
    while(dp[i][j]!=0 && i>=0 && j>=0)
    {
        if(a[i]==b[j])
        {
            k[kk++]=a[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1]>dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    for(int i=kk-1; i>0; i--)
        printf("%d ", k[i]);
    return 0;
}
