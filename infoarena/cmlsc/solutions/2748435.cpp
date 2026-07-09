#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int N=1025;
int n,m,a[N],b[N],d[N][N],sol[N];
void afisare(int i,int j)
{
    if(d[i][j]==0)
    {
        g<<d[n][m]<<'\n';
        return ;
    }
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
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int j=1;j<=m;j++)
        f>>b[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]!=b[j])
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            else
                d[i][j]=d[i-1][j-1]+1;
        }
    afisare(n,m);

    return 0;
}
