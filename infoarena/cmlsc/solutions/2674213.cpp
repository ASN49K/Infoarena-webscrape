#include <fstream>

using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");
int a[1025];
int b[1025];
int dp[1025][1025];
void solve(int x, int y)
{
    if (dp[x][y] == 0)
        return;
    if (a[x] == b[y])
    {
        solve(x - 1, y - 1);
        cout << a[x] << " ";
    }
    else
    {
        if (dp[x - 1][y] > dp[x][y - 1])
            solve(x - 1, y);
        else
            solve(x, y - 1);
    }
}
int main()
{
    int n, m, i, j, maxi = 0;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= m; i++)
        cin >> b[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            maxi = max(maxi, dp[i][j]);
        }
    cout << maxi << '\n';
    solve(n, m);
    return 0;
}
