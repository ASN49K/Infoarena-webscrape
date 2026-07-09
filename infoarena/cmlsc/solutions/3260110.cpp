#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
#define ll long long
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
pair<ll, ll> dp[1100][1100];
ll a[1100];
ll b[1100];
ll val[1100][1100];
void print(ll n, ll m)
{
    if(n == 0 || m == 0)
        return;
    print(dp[n][m].first, dp[n][m].second);
    if(a[n] == b[m])
        cout<<a[n]<<" ";
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll m, n;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    for(int i = 1; i <= m; i++)
        cin>>b[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(val[i][j] < val[i][j - 1])
                dp[i][j] = {i, j  - 1}, val[i][j] = val[i][j - 1];
            if(val[i][j] < val[i - 1][j])
                dp[i][j] = {i - 1, j}, val[i][j] = val[i - 1][j];
            if(a[i] == b[j] && val[i][j] < val[i - 1][j - 1] + 1)
                dp[i][j] = {i - 1, j - 1}, val[i][j] = val[i - 1][j - 1] + 1;
        }
    }
    cout<<val[n][m]<<'\n';
    print(n, m);
    return 0;
}
