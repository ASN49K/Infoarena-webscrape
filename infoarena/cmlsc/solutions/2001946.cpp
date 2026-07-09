#include <bits/stdc++.h>

using namespace std;
ifstream f("cmslc.in");
ofstream g("cmslc.out");
const int N=1030;
int a[N], b[N], d[N][N];
int n, m, i,j;
void afisare(int i, int j)
{
    if(d[i][j]==0)
        return;
    if(a[i]==b[j])
    {
        afisare(i-1,j-1);
        g<<a[i]<<" ";
        return;
    }
    if(d[i-1][j]>d[i][j-1])
        afisare(i-1,j);
    else afisare(i,j-1);
}

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>a[i];
    for(i=1;i<=m;i++) f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            d[i][j]=(a[i]==b[j])?(d[i-1][j-1]+1):max(d[i-1][j],d[i][j-1]);
    g<<d[n][m]<<'\n';
    afisare(n,m);
    return 0;
}
