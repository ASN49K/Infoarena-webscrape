#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1050],b[1050],dp[1050][1050],sol[1050];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i,j,n,m,mx;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    i=n; j=m;

    while(i>0 && j>0)
        {
            if(a[i]==b[j])
                {
                    sol[++sol[0]]=a[i];
                    i--;
                    j--;
                }
            else
                {
                    mx=max(dp[i-1][j],dp[i][j-1]);
                    if(mx==dp[i-1][j]) i--;
                    else               j--;
                }
        }
    printf("%d\n",sol[0]);
    for(i=sol[0];i>=1;i--)
        printf("%d ",sol[i]);
    return 0;
}
