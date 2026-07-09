#include <bits/stdc++.h>

using namespace std;
#define fastio std::ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define test " test "
#define yes "YES"
#define no "NO"
#define bn '\n'
#define ll long long
#define pb push_back
#define mp make_pair
//#define int long long
#define deb(a) cout << #a << "=" << (a) << bn
#define deb2(a, b) cout << #a << "=" << (a) << " " << #b << "=" << b << bn
#define printV(v)    \
    for (auto i : v) \
        cout << i << " ";
#define FILES                      \
    freopen("rucsac.in", "r", stdin); \
    freopen("rucsac.out", "w", stdout);
const int mod = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int maxi = INT_MIN, mini = INT_MAX;
/*rucsac.in

rucsac.out
29*/

#define MAXN 5010
#define MAXG 10010

int n, G;
int g[MAXN], v[MAXN];
int dp[2][MAXG];
void solve()
{
    cin >> n>>G;
    vector<int>g(n+1);
    vector<int>v(n+1);
    vector<vector<int>>dp(2,vector<int>(G+1,0));

    for(int i=1; i<=n; i++)
        cin>>g[i]>>v[i];

    int l=0;
    for(int i = 1; i <= n; ++i, l = 1 - l)
        for(int j = 0; j <= G; ++j)
        {
            dp[1-l][j] = dp[l][j];

            if(g[i] <= j)
                dp[1-l][j] = max(dp[1-l][j], dp[l][j - g[i]] + v[i]);
        }
        cout<<dp[l][G]<<" ";



}
signed main()
{
    fastio;
     FILES;
    int t = 1;
    /// cin >> t;
    while (t--)
        solve();

    return 0;
}
