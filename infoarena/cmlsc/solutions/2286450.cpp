#include <fstream>
using namespace std;
const int nmax = 1025;
int a[nmax], b[nmax], dp[nmax][nmax], sol[nmax], n, m, k;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int main()
{
    int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i = 1; i <= m; i++)
        fin >> b[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    fout << dp[n][m] << "\n";
    i = n;
    j = m;
    while (i)
    {
        if (a[i] == b[j])
        {
            sol[++k] = a[i];
            i--;
            j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
            j--;
        else i--;
    }
    for (i = k; i >= 1; i--)
        fout << sol[i] << " ";
    return 0;
}
