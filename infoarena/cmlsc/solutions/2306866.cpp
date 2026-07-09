#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],d[1025][1025],sir[1025],lg,k;
bool oki,okj;
int main()
{
    int i,j;
    f>>m>>n;
    for(i=1; i<=m; i++)
        f>>a[i];

    for(i=1; i<=n; i++)
        f>>b[i];

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
for(i=m,j=n;i;)
    if(a[i]==b[j])
        {sir[++k]=a[i];--i;--j;}
    else
        if(d[i-1][j]>d[i][j-1])
            --i;
        else
            --j;
g<<k<<'\n';
for(i=k;i;--i)
   g<<sir[i]<<" ";
    return 0;
}
