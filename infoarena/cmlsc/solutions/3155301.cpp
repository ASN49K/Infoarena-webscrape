#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m, cnt;
int a[1050], b[1050], ans[1050];
int dp[1050][1050];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            //cout << dp[i][j] << ' ';
        }
        //cout << '\n';
    }
    cout << dp[n][m] << '\n';

    cnt = 0;
    for(int i = n, j = m; i && j;)
    {
        if(a[i] == b[j])
            ans[++cnt] = a[i], i--, j--;
        else if(dp[i - 1][j] < dp[i][j - 1])
            j--;
        else i--;
    }
    for(int i = cnt; i >= 1; i--)
        cout << ans[i] << ' ';
    return 0;
}
