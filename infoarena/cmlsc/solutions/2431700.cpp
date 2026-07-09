#include <fstream>
#include <algorithm>
using namespace std;
const int nmax = 1026;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, dp[nmax][nmax], x[nmax], y[nmax], s[nmax], k;
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        fin >> x[i];
    for(int i = 1; i <= m; ++i)
        fin >> y[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(x[i] == y[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[n][m] << "\n";
    for(int i = n, j = m; i;)
    {
        if(x[i] == y[j])
            s[++k] = x[i], --i, --j;
        else if(dp[i - 1][j] < dp[i][j - 1])
            j--;
        else
            i--;
    }
    for(int i = k; i > 0; i--)
        fout << s[i] <<  " ";
    return 0;
}
