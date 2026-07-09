#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <stack>
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
#define bug(a) cerr << "(" << #a << ": " << a << ")\n";
#define all(x) x.begin(),x.end()
using i64= int64_t;
using u64= uint64_t;
using u32= uint32_t;
using i32= int32_t;
const i32 inf=1e9;
const i64 INF=1e18;
const i32 mod=1e9+7;
void solve()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    vector<int>a(n+1);
    vector<int>b(m+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(a[i]==b[j])
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    cout<<dp[n][m]<<'\n';
    int i=n,j=m;
    stack<int>st;
    while(i && j)
    {
        if(dp[i][j]==dp[i-1][j])
        {
            i--;
        }
        else if(dp[i][j]==dp[i][j-1])
        {
            j--;
        }
        else
        {
            st.push(a[i]);
            i--;
            j--;
        }
    }
    while(st.size())
    {
        cout<<st.top()<<' ';
        st.pop();
    }

}
main()
{
    auto sol=[&](bool x)
    {
        if(x)return "YES\n";
        return "NO\n";
    };
    i32 tt=1;
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cin>>tt;
    while(tt--)
    {
        solve();
    }
}
