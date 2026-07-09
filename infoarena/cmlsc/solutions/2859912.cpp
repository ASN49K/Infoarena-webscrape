#include <fstream>
#include <vector>
#define ll long long
using namespace std;
const int NMAX = 1025;
int a[NMAX], b[NMAX], dp[NMAX][NMAX];
vector <int> sol;
signed main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n, m, i, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= m; i++)
        cin >> b[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        }
    cout << dp[n][m] << "\n";
    i = n, j = m;
    while (dp[i][j] != 0)
    {
        int val = (a[i] == b[j]);
        if (val == 1)
            sol.push_back(a[i]);
        if (dp[i - 1][j] == dp[i][j] - val)
            i--;
        else
            j--;
    }
    for (i = sol.size() - 1; i > -1; i--)
        cout << sol[i] << " ";
}
