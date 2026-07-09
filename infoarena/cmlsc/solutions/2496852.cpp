#include <bits/stdc++.h>
#define N 1030

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, a[N], b[N], dp[N][N];
int subsir[N], k;

int main()
{
    fin >> n >> m;

    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int j = 1; j <= m; j++)
        fin >> b[j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }

    for (int i = n, j = m; i; )
    {
        if (a[i] == b[j])
            subsir[++k] = a[i], i--, j--;
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else j--;
    }

    fout << dp[n][m] << "\n";
    for (int i = k; i >= 1; i--)
        fout << subsir[i] << " ";
    return 0;
}
