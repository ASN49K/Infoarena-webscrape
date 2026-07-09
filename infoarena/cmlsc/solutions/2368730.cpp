#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int x[1025],y[1025],n,m,v[1025],a[1025][1025];
void citire()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>x[i];
    for(int j=1;j<=m;++j)
        f>>y[j];
}
void dinamica()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
    g<<a[n][m]<<'\n';
}
void afisare(int i,int j)
{
    int k=0;
    while(i>0 && j>0)
    {
        if(x[i]==y[j])
        {
            v[++k]=x[i];
            --i;
            --j;
        }
        else if(a[i][j]==a[i-1][j]) --i;
        else if(a[i][j-1]==a[i][j-1]) --j;
    }
    for(int i=k;i>=1;--i)
        g<<v[i]<<" ";
}
int cmmdc(int x,int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    citire();
    dinamica();
    afisare(n,m);
    cout<<cmmdc(8,4);
    return 0;
}
