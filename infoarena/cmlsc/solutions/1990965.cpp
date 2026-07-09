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
    for(int i = 0; i < m; ++i)
    {
        f >> a[i];
    }
    for(int i = 0; i < n; ++i)
    {
        f >> b[i];
    }
}

void dynamicProgramming()
{
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(j == 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i][j-1];
            if(a[i] == b[j])
            {
                c[dp[i][j]] = b[j];
                dp[i][j] += 1;
            }
        }
    }
}

void writing()
{
    g<<dp[m-1][n-1]<<"\n";
    for(int i = 0; i < dp[m-1][n-1]; ++i)
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
