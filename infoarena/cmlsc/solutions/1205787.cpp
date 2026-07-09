#include <fstream>
#include <vector>
using namespace std;

int dp[1030][1030], n, m, a[1030], b[1030], max_len;
vector<int> sol;

int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> b[i];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > max_len)
                    max_len = dp[i][j];
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    cout << max_len << '\n';
    int value = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (dp[i][j] == value)
            {
                cout << a[i] << " ";
                value ++;
            }
    return 0;
}
