#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("fast-math")
#pragma GCC optimize ("unroll-loops")

using namespace std;
#define int long long
#define ll long long
#define all (x) begin(x), end(x)
#define xx first
#define yy second


#define cin fin
#define cout fout

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");


using pii = pair <int, int>;
using tii = tuple <int, int>;

int n, m;
constexpr int NMAX = (int) 1024;
int v[NMAX + 1];
int w[NMAX + 1];
int dp[NMAX + 1][NMAX + 1];
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= m; ++ i){
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j)
        {
            dp[i][j] = dp[i - 1][j - 1] + 1;
            if (v[i] != w[j])
            {
                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << '\n';
    vector <int> ans;
    int idx = n, jdx = m;
    while (idx > 0 && jdx > 0)
    {
        if (v[idx] == w[jdx])
        {
            ans.push_back(v[idx]);
            idx --;
            jdx --;
        }
        else{
            if (dp[idx][jdx - 1] < dp[idx - 1][jdx])
                idx --;
            else
                jdx --;
        }
    }
    reverse (ans.begin(), ans.end());
    for (int i = 0; i <= ans.size() - 1; ++ i)
        cout << ans[i] << ' ';
    return 0;
}
