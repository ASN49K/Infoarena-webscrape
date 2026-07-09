#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int N=1025;
int n,m,a[N],b[N],d[N][N];
void afiseaza(int i, int j)
{
    if(d[i][j]==0)
        return;
    if(a[i]==b[j])
    {
        afiseaza(i-1,j-1);
        g<<a[i]<<' ';
    }
    else
        if(d[i-1][j]>=d[i][j-1])
            afiseaza(i-1,j);
        else
            afiseaza(i,j-1);
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);

    g<<d[n][m]<<'\n';
    afiseaza(n,m);
    return 0;
}
