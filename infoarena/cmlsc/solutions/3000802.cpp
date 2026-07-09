#include <fstream>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int dim = 1050;
int n, m, a[dim], b[dim], dp[dim][dim];


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    for (int  i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
    {
        if (i == 0 || j == 0)
            dp[i][j] = 0;
        else if (a[i] == b[j])
            dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }

    cout << dp[n][m] << '\n';

    int k = dp[n][m], sol[dim];
    int i = n, j = m;

    while (i && j && k)
    {
     if (a[i] == b[j]){
        sol[k--] = a[i];
        i --;
        j --;
     }
     else if (dp[i - 1][j] > dp[i][j - 1])
        i --;
     else j --;
    }
    for (i = 1; i <= dp[n][m]; ++i)
        cout << sol[i] << ' ';

    return 0;
}
