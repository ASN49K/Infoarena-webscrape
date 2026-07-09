#include <vector>
#include <fstream>
using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout("cmlsc.out");

int dp[1030][1030];
int a[1030], b[1030], n, m;

int main()
{
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=m;i++) cin >> b[i];

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    vector<int> res;
    for (int i=n, j=m; i;)
    {
        if (a[i] == b[j]) {
            res.push_back(a[i]);
            i--; j--;
        }
        else if (dp[i-1][j] < dp[i][j-1])
            j--;
        else
            i--;
    }

    cout << dp[n][m] << '\n';

    for (int i=res.size()-1;i>=0;i--)
        cout<<res[i]<<' ';

    return 0;
}
