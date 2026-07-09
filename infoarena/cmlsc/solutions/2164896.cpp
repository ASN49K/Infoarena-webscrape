#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int NMax = 1030;

int n, m, dp[NMax][NMax], a[NMax], b[NMax];
vector < int > sol;

int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i) f >> a[i];
    for(int i = 1; i <= m; ++i) f >> b[i];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = n, j = m;

    while(i && j)
    {
        if(dp[i][j] == dp[i - 1][j - 1] + 1 && dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1])
        {
            sol.push_back(a[i]);
            i--; j--;
        }
        else
        {
            if(dp[i - 1][j] >= dp[i][j - 1])
                i--;
            else j--;
        }
    }
    g << sol.size() << '\n';
    for(vector < int >::iterator it = sol.end() - 1; it >= sol.begin(); --it)
        g << *it << ' ';
}
