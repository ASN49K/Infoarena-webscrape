#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int d[1025][1025],a[257],b[257],c[257];

int main()
{
    int n,m,i,j,k=0;
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            if(b[i]==a[j])
            {
                d[i][j]=1+d[i-1][j-1];
                c[++k]=b[i];
            }
            if(b[i]!=a[j])
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    g << d[m][n] << '\n';
    for(i=1;i<=k;i++)
        g << c[i] << " ";
    return 0;
}
