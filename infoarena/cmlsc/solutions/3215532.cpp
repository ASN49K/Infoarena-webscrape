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
    int posa = n, posb = m, cnt = 0;
    while (posa >= 1 && posb >= 1)
        if (a[posa] == b[posb])
        {
            cnt++;
            ans[cnt] = a[posa];
            posa--;
            posb--;
        }
        else
            if (dp[posa][posb] == dp[posa - 1][posb])
                posa--;
            else
                posb--;
    for (int i = cnt; i >= 1; i--)
        cout << ans[i] << ' ';
    return 0;
}
