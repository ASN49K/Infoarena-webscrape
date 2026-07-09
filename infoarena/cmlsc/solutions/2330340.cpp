#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int Nmax = 1024 + 5;
const int Mmax =1024 + 5;
int n, m, a[Nmax], b[Mmax], dp[Nmax][Mmax], nm, c[Nmax];
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)fin >> a[i];
    for(int j = 1; j <= m; ++j)fin >> b[j];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])dp[i][j] = dp[i- 1][j-1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    int i = n, j = m;
    while(i && j)
    {
        if(a[i] == b[j])++nm, c[nm] = a[i], --i, --j;
        else if(dp[i][j - 1] > dp[i - 1][j])--j;
        else --i;
    }
    for(int ii = 1; ii <= nm / 2; ++ii)
    swap(c[ii], c[nm - ii + 1]);
    fout << nm << '\n';
    for(int ii = 1; ii <= nm; ++ii)
        fout << c[ii] << ' ';
    return 0;
}
