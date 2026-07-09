#include <fstream>
#include <vector>

using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");
int n, m, a[1032], b[1032];
vector <int> dp[1032][1032];
int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= m; ++i)
        cin >> b[i];

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1];
                dp[i][j].push_back(a[i]);
            }
            else
            {
                if(dp[i - 1][j].size() > dp[i][j - 1].size())
                    dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i][j - 1];
            }
        }
    }

    cout << dp[n][m].size() << '\n';

    for(auto it = dp[n][m].begin(); it != dp[n][m].end(); ++it)
    {
        cout << *it << ' ';
    }

    return 0;
}
