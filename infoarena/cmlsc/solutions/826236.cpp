#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, m, a[1030], b[1030], dp[1030][1030], c[1030], nc;

inline void Read()
{
    ifstream f("cmlsc.in");
    f>>n>>m;
    int i;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
    f.close();
}

inline void Solve()
{
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
}

inline void Write()
{
    ofstream g("cmlsc.out");
    g<<dp[n][m]<<"\n";
    int i, j;
    i = n, j = m;
    for(; i;)
    {
        if (a[i] == b[j])
        {
            c[++nc] = a[i];
            i--;
            j--;
        }
        else
            if (dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
    }
    for(i=nc; i; i--)
        g<<c[i]<<" ";
    g<<"\n";
    g.close();
}

int main()
{
    Read();
    Solve();
    Write();
    return 0;
}
