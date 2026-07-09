#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, p, ii, jj;
const int Nmax = 1025;
int a[Nmax], b[Nmax], dp[Nmax][Nmax], ans[Nmax];

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; ++i) fin >> a[i];

    for(int j = 1; j <= m; ++j) fin >> b[j];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            dp[i][j] = max(dp[i][j],max(dp[i][j - 1], dp[i - 1][j]));
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            if(dp[i][j] > p)
            {
                p = dp[i][j];
                ii = i;
                jj = j;
            }
        }


    int cp = p;

    int i = ii, j = jj;
    while(dp[i][j] > 0)
    {
        if(a[i] ==  b[j])
            ans[--p] = a[i], i--, j--;
        else if(dp[i - 1][j] > dp[i][j - 1])--i;
        else --j;

    }


    fout << cp << '\n';
    for(int i = 1; i <= cp; ++i)
        fout <<  ans[i - 1] << ' ';

    return 0;
}
