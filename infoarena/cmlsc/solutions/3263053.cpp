#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

/**
     - a c e
  +  0 0 0 0
  a  0 1 1 1
  b  0 1 1 1
  c  0 1 2 2
  d  0 1 2 2
  e  0 1 2 3

*/

int n, m, a[1024], b[1024], dp[1024][1024];

int main()
{
    int i, j;
    fin >> n >> m;
    for (i = 1 ; i <= n ; i++)
        fin >> a[i];
    for (i = 1 ; i <= m ; i++)
        fin >> b[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
    {
        if (a[i] == b[j])
            dp[i][j] = dp[i-1][j-1] + 1;
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
    fout << dp[n][m] << "\n";
    i = 1; j = 1;
    while (i <= n && j <= m)
    {
        if (a[i] == b[j])
        {
            fout << a[i] << " ";
            i++; j++;
        }
        else if (dp[i+1][j] >= dp[i][j+1]) i++;
        else j++;
    }
    return 0;
}
