#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define pb push_back
#define x first
#define y second
#define Nmax 1028

int v[Nmax];

int n, m, mx = 0, ii, jj;
int a[Nmax], b[Nmax];

int dp[Nmax][Nmax];

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int j = 1; j <= m; ++j)
        fin >> b[j];

    dp[1][0] = 0;
    dp[0][1] = 0;
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            if (dp[i][j] > mx)
            {
                mx = dp[i][j];
                ii = i;
                jj = j;
            }
        }

    fout << mx << '\n';

    int i = ii, j = jj, cnt = 0;

    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            v[++cnt] = a[i];
            --i;
            --j;
        }

        if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    for (int i = cnt; i >= 1; --i)
        fout << v[i] << ' ';

    return 0;
}