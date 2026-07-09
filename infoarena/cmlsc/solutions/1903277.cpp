#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,nr;
short int a[1025],b[1025],c[1025][1025],d[1025];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>a[i];
    for(int i=1; i<=m; i++)
        f>>b[i];
    for(int i=1; i<=m; i++)
    {
        if(c[1][i-1]==1) c[1][i]=1;
        else if(a[1]==b[i]) c[1][i]=1;
    }
    for(int i=1; i<=n; i++)
    {
        if(c[i-1][1]==1) c[i][1]=1;
        else if(a[i]==b[1]) c[i][1]=1;
    }

    for(int i=2; i<=n; i++)
        for(int j=2; j<=m; j++)
            {if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
            else if(c[i-1][j]>c[i][j-1]) c[i][j]=c[i-1][j];
            else c[i][j]=c[i][j-1];}

    nr=c[n][m];
    g<<nr<<'\n';
    for(int i=n; i>=1; i--)
        for(int j=m; j>=1; j--)
    {
        if(a[i]==b[j] && c[i][j]==nr)
        {

            d[nr]=a[i];
             nr--;
        }
    }
    for(int i=1; i<=c[n][m]; i++)
        g<<d[i]<<' ';
    g<<'\n';
}
