#include <bits/stdc++.h>
using namespace std;
int dp[1025][1025];
int a[1025],b[1025];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int m,n,i,j;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
    scanf("%d",&a[i]);
        for(j=1;j<=n;j++)
        scanf("%d",&b[j]);
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    {
        if(a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    cout<<dp[m][n]<<endl;
    int st=m,dr=n;
    int s[1005];
    int cnt=0;
    while(st&&dr)
    {
        if(a[st]==b[dr]){s[++cnt]=a[st];--st;--dr;}
        else
            if(dp[st][dr-1]>dp[st-1][dr])--dr;
        else
            --st;
    }
    for(i=cnt;i>=1;i--)
        cout<<s[i]<<" ";
    return 0;
}
