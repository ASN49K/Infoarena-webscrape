#include <bits/stdc++.h>
#define ll int
#define mp make_pair
#define pb push_back
#define Vl vector<ll>
#define Vb vector<bool>
#define nl '\n'
#define pf push_front
#define INF 0x3f3f3f3f
#define pii pair <int, int >
#define pll pair < ll, ll >
#define NMAX 100005
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

vector< ll > ans(1055);
ll n, m, a[1055], b[1055], dp[1055][1055];
int main()
{
    in >> n >> m;
    for (int i = 1; i <= n; i++)
        in >> a[i];
    for (int j = 1; j <= m; j++)
        in >> b[j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + max(dp[i - 1][j], dp[i][j - 1]);
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    out << dp[n][m] << nl;
    ll k = 0;
    ll i = n, j = m;
    while (i and j) {
        if (a[i] == b[j]) {
            ans[++k] = a[i];
            i--;
            j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
            j--;
        else i--;
    }
    reverse(ans.begin() + 1, ans.begin() + 1 + n);
    for (int i = 1; i <= n; i++)
        out << ans[i] << ' ';
    return 0;
}