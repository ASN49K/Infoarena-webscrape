#include <iostream>
#include <fstream>
using namespace std;
int dp[1025][1025], a[1025], b[1025], c[1025], i, j, n, m, k;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f >> n >> m;
    for(i = 1; i <= n; ++ i)
        f >> a[i];
    for(i = 1; i <= m; ++ i)
        f >> b[i];
    for(i = 1; i <= n; ++ i)
    {
        for(j = 1; j <= m; ++ j)
        {
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    i = n;
    j = m;
    while(i )
    {
        if(a[i] == b[j])
        {
            c[++ k] = a[i];
            i --;
            j --;
        }
        else if(dp[i][j - 1] < dp[i - 1][j])
            i --;
        else
            j --;
    }
    g << k << "\n";
    for(i = k; i >= 1; i --)
        g << c[i] << " ";
    return 0;
}
