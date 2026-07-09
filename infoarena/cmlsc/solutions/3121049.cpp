#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int NMAX = 1024;
int a[NMAX + 1], b[NMAX + 1];
int n, m;

int dp[NMAX + 1][NMAX + 1];
int ans[NMAX + 1], ind;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    
    int i = n, j = m;
    while(i >= 1 && j >= 1)
        if(a[i] == b[j])
            ans[++ind] = a[i], i--, j--;
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;

    cout << dp[n][m] << '\n';
    for(int i = ind; i >= 1; i--)
        cout << ans[i] << ' ';

    return 0;
}