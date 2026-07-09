#include <fstream>
#include <vector>

using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");
int n, m, a[1032], b[1032], dp[1032][1032];
vector <int> s;
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
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = n, j = m;

    while(i && j)
    {
        if(a[i] == b[j])
        {
            s.push_back(a[i]);
            --i;
            --j;
        }
        else
        {
            if(dp[i - 1][j] > dp[i][j - 1])
                --i;
            else --j;
        }
    }

    cout << dp[n][m] << '\n';

    for(auto it = s.rbegin(); it != s.rend(); ++it)
    {
        cout << *it << ' ';
    }

    return 0;
}
