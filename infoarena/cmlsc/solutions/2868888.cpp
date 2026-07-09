#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1025], b[1025], dp[1025][1025], sol[1025], nr;

int main()
{

    int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++) fin >> a[i];
    for (i = 1; i <= m; i++) fin >> b[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[n][m] << "\n";
    i = n;
    j = m;
    while (i)
    {
        if (a[i] == b[j])
        {
            sol[++nr] = a[i];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    for (i = nr; i > 0; i--)
        fout << sol[i] << " ";
    fout << "\n";
    fout.close();

    return 0;
}
