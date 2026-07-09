#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, p;
const int Nmax = 1030;
int a[Nmax], b[Nmax], dp[Nmax][Nmax], ans[Nmax];

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; ++i) fin >> a[i];

    for(int j = 1; j <= m; ++j) fin >> b[j];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if(a[i] == b[j])
                dp[i][j] ++;
        }

    p = dp[n][m];
    int cp = p;

    int i = n, j = m;
    while(dp[i][j] > 0)
    {
        if(a[i] ==  b[j])
            ans[--p] = a[i];

        if(dp[i - 1][j] > dp[i][j - 1])--i;
        else --j;

    }


    fout << cp << '\n';
    for(int i = 1; i <= cp; ++i)
        fout <<  ans[i - 1] << ' ';

    return 0;
}
