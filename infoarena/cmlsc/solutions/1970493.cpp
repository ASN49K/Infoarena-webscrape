#include <bits/stdc++.h>
using namespace std;

int n,m;
int x[1027],y[1027];
short dp[1027][1027];
stack<int> s;

int main()
{
    int i,j,val;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&x[i]);
    for(j=1;j<=m;j++) scanf("%d",&y[j]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(x[j]==y[i]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    printf("%d\n",dp[m][n]);
    i=m; j=n; val=dp[m][n];
    while(val!=0)
    {
        while(dp[i-1][j]==val) i--;
        while(dp[i][j-1]==val) j--;
        s.push(y[i]);
        i--;
        val=dp[i][j];
    }
    while(!s.empty())
    {
        printf("%d ",s.top());
        s.pop();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
