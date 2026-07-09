#include <iostream>
#include <fstream>
#include <algorithm>

#define x first
#define y second

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, ii, jj, k, aux;
int v1[1025], v2[1025], sol[1025];
int dp[1025][1025];

int main()
{
    in >> n >> m;
    for(int i = 1; i <= n; ++ i)
    {
        in >> v1[i];
    }
    for(int i = 1; i <= m; ++ i)
    {
        in >> v2[i];
    }
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
        {
            if(v1[i] != v2[j])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }

    ii = n;
    jj = m;

    while(dp[ii][jj])
    {
        aux = dp[ii][jj];
        if(v1[ii] != v2[jj])
        {
            if(dp[ii - 1][jj] > dp[ii][jj - 1])
                -- ii;
            else
                -- jj;
        }
        else
        {
            -- ii;
            -- jj;
            ++ k;
            sol[k] = v1[ii + 1];
        }
    }

    out << dp[n][m] << '\n';

    for(int i = k; i > 0; -- i)
        out << sol[i] << " ";
    return 0;
}
