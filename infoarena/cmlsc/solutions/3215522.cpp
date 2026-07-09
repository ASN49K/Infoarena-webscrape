#include <fstream>
#define MAX 1024
using namespace std;
ifstream cin ("sclm.in");
ofstream cout ("sclm.out");
int a[MAX + 10], b[MAX + 10], dp[MAX + 10][MAX + 10], ans[MAX + 10];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1] + 1);
            else
                dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
    cout << dp[n][m] << '\n';
    int i = n, j = m, cnt = 0;
    while (i >= 1 && j >= 1)
        if (a[i] == b[j])
        {
            cnt++;
            ans[cnt] = a[i];
            i--;
            j--;
        }
        else
            if (dp[i][j] == dp[i - 1][j])
                i--;
            else
                j--;
    for (i = cnt; i >= 1; i--)
        cout << ans[i] << ' ';
    return 0;
}
