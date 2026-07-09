#include <bits/stdc++.h>

using namespace std;
int dp[1026][1026],a[1026],b[1026],c[1026],i,j,n,m,sol,N;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    sol=dp[n][m];
    N=sol;
    printf("%d\n",sol);
    for(i=n,j=m;sol;)
    {
        if(a[i]==b[j])
        {
            c[sol--]=a[i];
            i--;j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(i=1;i<=N;i++)
        printf("%d ",c[i]);
    return 0;
}
