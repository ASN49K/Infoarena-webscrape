#include<cstdio>
#include<algorithm>
using namespace std;
const int nmax = 1030;
int n,m,a[nmax],b[nmax],i,j,dp[nmax][nmax],s[nmax],sol;
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    printf("%d\n",dp[n][m]); sol=dp[n][m];
    for(i=n,j=m;sol;)
    {
        if(a[i]==b[j]) s[sol--]=a[i],i--,j--;
        else if(dp[i][j]==dp[i-1][j]) i--;
        else j--;
    }
    for(i=1;i<=dp[n][m];i++) printf("%d ",s[i]);
	return 0;
}
