#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

const int N = 1030;
int a[N + 1], b[N + 1], dp[N + 1][N + 1], pred[N + 1][N + 1];

int n, m;

vector <int> sol;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int j = 1; j <= m; ++j)
        cin >> b[j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1, pred[i][j] = 1;
            else
            {
                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
                if (dp[i][j] == dp[i - 1][j])
                    pred[i][j] = -1;
                else
                    pred[i][j] = 0;
            }
    cout << dp[n][m] << '\n';
    while (n && m)
    {
        if (pred[n][m] == 1)
            sol.push_back(a[n]), --n, --m;
        else if (pred[n][m] == -1)
            --n;
        else
            --m;
    }
    reverse (sol.begin(), sol.end());
    for (auto it : sol)
        cout << it << ' ';
    return 0;
}
