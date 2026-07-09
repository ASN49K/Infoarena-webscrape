#include <bits/stdc++.h>
#define N 1025
#define pb push_back
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, i, j, a[N], b[N], dp[N][N];
char prv[N][N];
vector<int> ans;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;++i)
        fin>>a[i];
    for(i=1;i<=m;++i)
        fin>>b[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
    {
        if(a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1,prv[i][j]=-1;
        else if(dp[i-1][j]>dp[i][j-1])
        {
            dp[i][j]=dp[i-1][j];
            prv[i][j]=1;
        }
        else
        {
            dp[i][j]=dp[i][j-1];
            prv[i][j]=2;
        }
    }
    i=n, j=m;
    while(i>=1&&j>=1)
    {
        if(prv[i][j]==-1)
        {
            ans.pb(a[i]);
            --i,--j;
        }
        else if(prv[i][j]==1)
            --i;
        else --j;
    }
    reverse(ans.begin(),ans.end());
    fout<<ans.size()<<'\n';
    for(i=0;i<ans.size();++i)
        fout<<ans[i]<<' ';

    return 0;
}
