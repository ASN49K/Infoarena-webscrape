#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int d[1001], a[1001], b[1001], n, m, k;

int main()
{
    f >> n >> m;
    for(int i=1; i<=n; i++)
        f >> a[i];
    for(int i=1; i<=m; i++)
        f >> b[i];
    k=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i] == b[j])
            {
                d[++k] = a[i];
            }
    g  << k << '\n';
    for(int i=1; i<=k; i++)
        g << d[i] << ' ';
    return 0;
}
