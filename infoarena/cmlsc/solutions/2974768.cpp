#include <bits/stdc++.h>

#define MAX 1024

#define FILES freopen("cmlsc.in","r",stdin);\
              freopen("cmlsc.out","w",stdout);

using namespace std;

int n, m, a[MAX + 5], b[MAX + 5], best;
int dp[MAX + 5][MAX + 5];

vector<int> ans;

void build(int & i, int & j)
{
    while(i >= 1 && j >= 1)
    {
        if(dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1])
        {
            ans.push_back(a[i]);
            i--,j--;
        }
        else
        {
            if(dp[i][j] == dp[i - 1][j])
                i--;
            else
                j--;
        }
    }
    reverse(ans.begin(), ans.end());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    FILES
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for(int i = 1; i <= m; ++i)
        std::cin >> b[i];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    build(n, m);
    std::cout << ans.size() << '\n';
    for(auto i : ans)
        std::cout << i << ' ';
}
