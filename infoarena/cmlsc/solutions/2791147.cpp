#include <fstream>
#include <vector>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
vector<int> ans;
int v1[1025], v2[1025];
int dp[1025][1025];
int main()
{
    int n, m, i, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> v1[i];
    }
    for (i = 1; i <= m; i++)
    {
        cin >> v2[i];
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (v1[i] == v2[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m] << "\n";
    int x = n, y = m;
    while (x >= 1 && y >= 1)
    {
        if (dp[x][y] == dp[x][y - 1])
            y--;
        else if (dp[x][y] == dp[x - 1][y])
            x--;
        else
        {
            ans.push_back(v1[x]);
            x--;
            y--;
        }
    }
    for (i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    return 0;
}