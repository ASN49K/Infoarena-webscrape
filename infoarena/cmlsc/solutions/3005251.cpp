#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n, i, j, m, dp[1025][1025],prv[1025][1025], nr, x[1025], y[1045];
void afis(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (prv[i][j] == 1)
    {
        afis(i - 1, j - 1);
        cout << x[i]<<' ';
    }
    else
        if (prv[i][j] == -1)
            afis(i - 1, j);
        else
            afis(i, j - 1);
}
int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> x[i];
    for (j = 1; j <= m; j++)
        cin >> y[j];

    for(i=1;i<=n;i++)
        for (j = 1; j <= m; j++)
        {
            if (x[i] == y[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                prv[i][j] = 1;
            }
            else
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    prv[i][j] = -1;
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    prv[i][j] = 0;
                    dp[i][j] = dp[i][j - 1];
                }
        }

    cout << dp[n][m]<<endl;
    afis(n,m);
}