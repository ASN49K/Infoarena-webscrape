#include <iostream>
#include <fstream>
#define DM 1030
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, a[DM], b[DM], dp[DM][DM], rez[DM], nr;

int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; i++)
        f >> a[i];
    for(int i = 1; i <= m; i++)
        f >> b[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {

            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
        {
            rez[++nr] = a[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else j--;
        }

    }
    g << dp[n][m] << '\n';
    for(int i = nr; i >= 1; i--)
        g << rez[i] << ' ';
    return 0;
}
