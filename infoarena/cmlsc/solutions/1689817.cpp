#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define INF numeric_limits<int>::max()
#define int64 long long
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1025],b[1025],dp[1025][1025],n,m;
void afis(int x,int y)
{
    if(dp[x][y]!=0)
    {
        if(a[x]==b[y])
        {
            afis(x-1,y-1);
            out<<a[x]<<' ';
        }
        else if(dp[x-1][y]==dp[x][y])afis(x-1,y);
        else afis(x,y-1);
    }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>a[i];
    for(int i=1;i<=m;i++)
        in>>b[i];
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(a[i]==b[j])
        dp[i][j]=dp[i-1][j-1]+1;
    else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    out<<dp[n][m]<<'\n';
    afis(n,m);
    return 0;
}

