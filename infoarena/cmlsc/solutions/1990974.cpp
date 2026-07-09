#include <iostream>
#include <fstream>

#define nmax 2405
#define mmax 2405

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[mmax], b[nmax], dp[mmax][nmax], c[nmax], m, n;

void reading()
{
    f >> m >> n;
    for(int i = 1; i <= m; ++i)
    {
        f >> a[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        f >> b[i];
    }
}

void dynamicProgramming()
{
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int nr=1;
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(dp[i][j] == nr)
            {
                c[nr] = a[i];
                ++nr;
            }
        }
    }
}

void writing()
{
    g<<dp[m][n]<<"\n";
    for(int i = 1; i <= dp[m][n]; ++i)
    {
        g<<c[i]<<" ";
    }
}

int main()
{
    reading();
    dynamicProgramming();
    writing();
    return 0;
}
