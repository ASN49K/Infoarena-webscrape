#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

const int max_size = 1025;

int dp[max_size][max_size], a[max_size], b[max_size];

int main ()
{
    int n, m;
    in >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        in >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        in >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    vector <int> ans;
    int i = n, j = m;
    while (i > 0)
    {
        if (a[i] == b[j])
        {
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] < dp[i][j - 1])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    out << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for (auto f : ans)
    {
        out << f << " ";
    }
    in.close();
    out.close();
    return 0;
}
