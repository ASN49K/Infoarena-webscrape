#include <bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1030],b[1030],dp[1030][1030],sol[1030];
int main()
{
    int n,m,i,j,s;
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(i=1;i<=m;i++)
        in>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    i=n;j=m;s=dp[n][m];
    while(i&&j)
    {
        if(a[i]==b[j])
            sol[s--]=a[i],i--,j--;
        else if(dp[i][j-1]>dp[i-1][j])
            j--;
        else
            i--;
    }
    s=dp[n][m];
    out<<s<<"\n";
    for(i=1;i<=s;i++)
        out<<sol[i]<<" ";
    return 0;
}
