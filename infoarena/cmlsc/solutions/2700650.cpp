#include <fstream>

using namespace std;
const short NMAX = 1024;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[NMAX + 5][NMAX + 5];
int a[NMAX + 5], b[NMAX + 5];
int ans[NMAX + 5];

int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);

    int n,m,i,j,cnt = 0;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i <= m; i++)
        fin >> b[i];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[n][m] << "\n";
    for(i = n, j = m; i;)
        if(a[i] == b[j])
            ans[++cnt] = a[i], i--, j--;
        else
            if(dp[i - 1][j] < dp[i][j - 1])
                j--;
            else
                i--;
    for(i = cnt; i > 0; i--)
        fout << ans[i] << " ";
    return 0;
}
