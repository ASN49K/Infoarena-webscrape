#include <fstream>

using namespace std;
int dp[1025][1025], n, m, a[1025], b[1025], sol[1025];
void Solve()
{
    int n, m, i, j;
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (j = 1; j <= m; j++)
        fin >> b[j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[n][m] << "\n";
    int k = 0;
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
    fout << "\n";
    fout.close();

}
int main()
{
    Solve();
    return 0;
}
