#include <iostream>
#include <fstream>
#include <stack>
#define nmax 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[nmax][nmax];
stack <int> af;
int main()
{
    int n, m, i, j;
    int a[nmax], b[nmax];

    fin>>n>>m;
    for(i = 1; i <= n; ++i)
        fin>>a[i];

    for(i = 1; i <= m; ++i)
        fin>>b[i];

    for(i = 1; i <= n; ++i)
    {
        for(j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    fout<<dp[n][m]<<'\n';

    for(i = n, j = m; i >= 1 && j >= 1;)
    {
        if(a[i] == b[j])
        {
            af.push(a[i]);
            --i;
            --j;
        }
        else
        {
            if(dp[i-1][j] > dp[i][j-1])
                --i;
            else
                --j;
        }
    }

    while(!af.empty())
    {
        fout<<af.top()<<' ';
        af.pop();
    }
    return 0;
}
