#include <bits/stdc++.h>
using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
const int C=1025;
int a[C], b[C], dist[C][C], cmlsc[C];
int main()
{
    int m, n, i, j, poz=0;
    in>>n>>m;
    for (i=1; i<=n; i++)
        in>>a[i];
    for (i=1; i<=m; i++)
        in>>b[i];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
    {
        if (a[i]==b[j])
            dist[i][j]=dist[i-1][j-1]+1;
        else
            dist[i][j]=max (dist[i-1][j], dist[i][j-1]);
    }
    i=n;
    j=m;
    while (i>0 && j>0)
    {
        if (a[i]==b[j])
        {
            cmlsc[poz]=a[i];
            poz++;
            i--;
            j--;
        }
        else
        {
            if (dist[i-1][j]>dist[i][j-1])
                i--;
            else
                j--;
        }
    }
    out<<poz<<'\n';
    for (i=poz-1; i>=0; i--)
        out<<cmlsc[i]<<" ";
    return 0;
}
