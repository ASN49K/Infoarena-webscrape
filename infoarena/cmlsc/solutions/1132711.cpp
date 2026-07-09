//horatiu11
# include <cstdio>
# include <algorithm>
# define nmax 1025
using namespace std;
int m,n,a[nmax],b[nmax],dp[nmax][nmax],sir_comun[nmax],k;
int main()
{
    int i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;++i)
        scanf("%d",&a[i]);
    for(i=1;i<=n;++i)
        scanf("%d",&b[i]);
    for(i=1;i<=m;++i)
        for(j=1;j<=n;++j)
            if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    for(i=m,j=n;i>0,j>0;)
        if(a[i]==b[j])sir_comun[++k]=a[i],--i,--j;
        else if(dp[i-1][j]>dp[i][j-1])--i;
        else --j;
    printf("%d\n",k);
    for(i=k;i>1;--i)
        printf("%d ",sir_comun[i]);
    printf("%d\n",sir_comun[1]);
    return 0;
}
