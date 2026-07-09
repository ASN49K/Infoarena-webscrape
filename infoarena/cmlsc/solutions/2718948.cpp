#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int nmax = 1024;
int n,m,a[nmax],b[nmax],d[nmax][nmax], ans[nmax],best = 0;
int main(void)
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> a[i];
    for(int i = 1; i <= m; ++i)
        f >> b[i];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    }
    for(int i = n, j = m; i;)
    {
        if(a[i] == b[j])
        {
            ans[++best] = a[i];
            i--;
            j--;
        }
        else if(d[i-1][j] < d[i][j-1]) j--;
        else i--;
    }
    g << best << '\n';
    for(int i = best; i; --i)
        g << ans[i] << " ";
    return 0;
}
