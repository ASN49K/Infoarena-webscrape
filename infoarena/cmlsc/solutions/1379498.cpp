/*
    Keep It Simple!
*/

#include <fstream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int kMaxN = 1050;

int n,m;
int a[kMaxN],b[kMaxN],dp[kMaxN][kMaxN];
list<int> ans;

void Solve()
{
    f >> n >> m;
    for(int i=1;i<=n;++i) f >> a[i];
    for(int i=1;i<=m;++i) f >> b[i];

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

    int x = n, y = m;
    while(x>0 || y>0)
    {
        if(a[x] == b[y])
        {
            ans.push_front(a[x]);
            --x,--y;
        }
        else if(dp[x-1][y] > dp[x][y-1])
            --x;
        else
            --y;
    }
    g << dp[n][m] << '\n';

    for(auto it:ans)
        g << it << ' ';
}

int main()
{
    Solve();
    return 0;
}
