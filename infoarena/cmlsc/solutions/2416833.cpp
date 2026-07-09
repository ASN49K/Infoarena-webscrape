#include <cstdio>
#include<algorithm>

using namespace std;
int dp[1025][1025];
int a[1025],b[1025];
int sol[1025],nr;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(j=1;j<=m;j++)
        scanf("%d",&b[j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    printf("%d\n",dp[n][m]);
    i=n;
    j=m;
    nr=0;
    while(i>=1 && j>=1 && nr<dp[n][m])
    {
        if(a[i]==b[j]){
          sol[++nr]=a[i];
          i--;
          j--;
        }
        else if(dp[i][j]==dp[i-1][j])
          i--;
          else
            j--;
    }
    for(i=nr;i>=1;i--)
        printf("%d ",sol[i]);
    return 0;
}
