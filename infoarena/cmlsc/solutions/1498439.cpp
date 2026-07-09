#include <bits/stdc++.h>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n,m,i,j,a[1000],b[1000],c[1000][1000],d[1000],poz;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j])
            {c[i][j]=1+c[i-1][j-1];d[++poz]=a[i];}
        else
            c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<poz<<endl;
    for(i=1;i<=poz;i++)
        g<<d[i]<<" ";
    return 0;
}
