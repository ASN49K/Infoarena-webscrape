#include <bits/stdc++.h>

#pragma GCC target("avx2")
//#define int long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
using namespace __gnu_pbds;
using namespace std;
//ofstream fout("date.out");
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
vector <pair<vector <int>,int>> v;
int n,m;
int a[1025],b[1025];
int dp[1025][1025];

void solve()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int j=1;j<=m;j++)
        fin>>b[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        if(a[i]==b[j])
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    }
    vector <int> nums;
    fout<<dp[n][m]<<'\n';
    int x=n,y=m;
    while(x>=1&&y>=1)
    {
        if(dp[x-1][y]==dp[x][y])
        {
            x--;
            continue;
        }
        if(dp[x][y-1]==dp[x][y])
        {
            y--;
            continue;
        }
        if(dp[x-1][y-1]+1==dp[x][y]&&a[x]==b[y])
        {
            nums.push_back(a[x]);
            x--;
            y--;
        }
    }
    reverse(nums.begin(),nums.end());
    for(int i:nums)
        fout<<i<<' ';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    //fin>>t;
    while(t--)
        solve();
    return 0;
}
