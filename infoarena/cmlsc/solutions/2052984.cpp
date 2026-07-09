#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int c[101][101],a[101],b[101],n,m;

void tipar(int i,int j)
{
    if (i>=1&&j>=1)
        if (a[i]!=b[j])
        {
            if (c[i][j-1]>c[i-1][j]) tipar(i,j-1);
            else tipar(i-1,j);
        }
        else
        {
            tipar(i-1,j-1);
            g<<a[i]<<' ';
        }
}

void solve()
{
    int i,j;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]==b[j]) c[i][j]=1+c[i-1][j-1];
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<c[n][m]<<'\n';
    tipar(n,m);
}

void citire()
{
    int i;
    f>>n>>m;
    for (i=1;i<=n;i++) f>>a[i];
    for (i=1;i<=m;i++) f>>b[i];
}

int main()
{
    citire();
    solve();
    return 0;
}
