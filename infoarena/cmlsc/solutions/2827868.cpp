#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n, m, a[1025], b[1025], dp[1025][1025];
void sirul (int l, int c)
{
    if (l == 0 || c == 0)
        return;
    if (a[l] == b[c])
    {
        sirul(l - 1, c - 1);
        fout << a[l] << " ";
    }
    else if (dp[l - 1][c] > dp[l][c - 1])
        sirul(l-1, c);
    else
        sirul(l, c - 1);

}
int main()
{
    fin >> n >> m;
    for (int i=1; i<=n; i++)
        fin >> a[i];
    for (int i=1; i<=m; i++)
        fin >> b[i];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

        }
    }
    fout << dp[n][m] << endl;
    sirul(n, m);
    return 0;
}
