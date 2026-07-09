#include <bits/stdc++.h>
#define pb push_back
//#define int long long
using namespace std;
const int N=1024+5;
int a[N],b[N];
int dp[N][N];
int calc(int i, int j)
{
    if(i<=0||j<=0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]) return dp[i][j]=calc(i-1,j-1)+1;
    return dp[i][j]=max(calc(i-1,j),calc(i,j-1));
}
signed main()
{
    ifstream cin("cmlsc.in");ofstream cout("cmlsc.out");
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int j=1;j<=m;++j) cin>>b[j];
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) dp[i][j]=-1;
    calc(n,m);
    int i=n,j=m;
    vector<int> sol;
    while(i>=1&&j>=1)
    {
        if(a[i]==b[j]) {sol.pb(a[i]);--i,--j;}
        else
        {
            if(i>1&&(j==1||dp[i-1][j]>=dp[i][j-1])) --i;
            else if(j>1) --j;
        }
    }
    reverse(sol.begin(),sol.end());
    cout<<sol.size()<<'\n';
    for(auto x:sol) cout<<x<<" ";
}
