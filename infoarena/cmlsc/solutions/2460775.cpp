#include <fstream>
#include <math.h>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1030], b[1030], dp[1030][1030], v[1030];
int n, m, k;

void citire()
{
    f>>n>>m;
    for(int i = 1; i<=n; ++i)
    {
        f>>a[i];
    }
    for(int i = 1; i<=m; ++i)
    {
        f>>b[i];
    }
}

void rez()
{
    for(int i = 1; i<=n; ++i)
    {
        for(int j = 1; j<=m; ++j)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i] == b[j])
            {
                dp[i][j]++;
                v[k++] = a[i];
            }
        }
    }
}

void afisare()
{
    g<<dp[n][m]<<"\n";
    for(int l = 0; l<k; l++)
    {
        g<<v[l]<<" ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    citire();
    rez();
    afisare();
    return 0;
}
