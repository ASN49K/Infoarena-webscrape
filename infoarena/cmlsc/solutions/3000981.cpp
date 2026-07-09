#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, k;
int a[1030], b[1030], sol[1030], dp[1030][1030];

int main()
{
    int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i = 1; i <= n; i++)
        fin >> b[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[n][m] << "\n";
    i = n; j = m;
    while (i >= 1 && j >= 1)
    {
        if (a[i] == b[j])
        {
            sol[++k] = a[i];
            i--; j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j]) j--;
        else i--;
    }
    for (i = dp[n][m]; i >= 1; i--)
        fout << sol[i] << " ";
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}
/**
  7 5 8
1 2 1 1
7 2 1 1
3 1 1 1
9 1 1 1
8 1 1 1

*/
