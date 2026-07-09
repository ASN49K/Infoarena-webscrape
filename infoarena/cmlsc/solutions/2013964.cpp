#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int n_max = 1100;
int a[n_max], b[n_max], ans[n_max], dp[n_max][n_max];

int main()
{
    int n, m, i, j, top;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i = 1; i <= m; i++)
        fin >> b[i];
    fin.close();
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j -1]);
    i = n; j = m; top = 0;
    while (i && j)
        if (a[i] == b[j]) {
            ans[++top] = a[i];
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    fout << dp[n][m] << "\n";
    for(i = top; i > 0; i--)
        fout << ans[i] << " ";
    fout.close();
    return 0;
}
