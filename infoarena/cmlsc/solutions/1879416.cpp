#include <bits/stdc++.h>
#define NMax 1025
#define INF 0x3f3f3f3f
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, a[NMax], b[NMax], dp[NMax][NMax], nr, sir[NMax];

int main()
{

    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> a[i];
    for(int i = 1; i <= m; ++i)
        f >> b[i];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    int i_curent = n, j_curent = m;
    while(i_curent)
    {
        if(a[i_curent] == b[j_curent])
        {
            sir[++nr] = a[i_curent];
            --i_curent;
            --j_curent;
        }
        else if(dp[i_curent - 1][j_curent] < dp[i_curent][j_curent - 1]) --j_curent;
        else --i_curent;
    }

    g << nr << '\n';


    for(int i = nr; i >= 1; --i)
        g << sir[i] << " ";

    return 0;
}
