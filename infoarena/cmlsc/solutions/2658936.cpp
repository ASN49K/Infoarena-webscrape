#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int N = 1025;
int n,m,a[N],b[N],d[N][N];
void afisare(int i,int j)
{
    if(d[i][j]==0)
        return;
    if(a[i]==b[j])
    {
        afisare(i-1,j-1);
        g<<a[i]<<' ';
    }
    else
        if(d[i-1][j]>=d[i][j-1])
            afisare(i-1,j);
    else
        afisare(i,j-1);
}
int main()
{
    f>>n;for(int i=1; i<=n;i++)f>>a[i];
    f>>m;for(int i=1; i<=m;i++)f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    g<<d[n][m]<<'\n';
    afisare(n,m);
    return 0;
}
