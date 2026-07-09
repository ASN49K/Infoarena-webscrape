#include <bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
pair<int,int> last[1030][1030];
int dp[1030][1030];
int a[1030];
int b[1030];
int n,m;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        in>>a[i];
    for(int j=1;j<=m;++j)
        in>>b[j];
    for(int i=0;i<=n;++i)
    for(int j=0;j<=m;++j)
    if(i+j)
    {
        if(a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1,
            last[i][j]={i-1,j-1};
        else if(dp[i][j-1]>dp[i-1][j])
            dp[i][j]=dp[i][j-1],
            last[i][j]={i,j-1};
        else dp[i][j]=dp[i-1][j],
            last[i][j]={i-1,j};
    }
    out<<dp[n][m]<<'\n';
    vector<int> sol;
    int x=n,y=m;
    while(x+y)
    {
        int xx=last[x][y].first;
        int yy=last[x][y].second;
        if(x==xx+1 and y==yy+1)
            sol.push_back(a[x]);
        x=xx;
        y=yy;
    }
    for(int i=sol.size()-1;i>=0;--i)
        out<<sol[i]<<' ';
    out<<'\n';
    return 0;
}
