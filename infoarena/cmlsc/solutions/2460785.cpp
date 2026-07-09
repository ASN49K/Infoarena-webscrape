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
                dp[i][j] = dp[i-1][j-1] + 1;
        }
    }
}

void afisare()
{
    int i = n, j = m;
    while(i>0 && j>0)
    {
        if(a[i] == b[j])
        {
            v[k++] = a[i];
            i--;
            j--;
        }
        else if(dp[i][j-1] > dp[i-1][j])
            j--;
        else
            i--;
    }
    g<<dp[n][m]<<"\n";
    for(int l = k-1; l>=0; --l)
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
