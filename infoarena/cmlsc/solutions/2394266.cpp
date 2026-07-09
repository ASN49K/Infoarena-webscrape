#include <fstream>
#include <iostream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,a[1025],b[1025],d[1025][1025],poz,sir[1025];
void mamadariei(int i,int j)
{
    if(i>=1&&j>=1)
    {
        if(a[i]==b[j])
        {
            poz++;
            sir[poz]=a[i];
            mamadariei(i-1,j-1);
        }
         else if(d[i-1][j]>d[i][j-1]) mamadariei(i-1,j);
            else  mamadariei(i,j-1);
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1;
        else d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    poz=0;
    mamadariei(n,m);
    g<<d[n][m]<<'\n';
    for(i=poz;i>=1;i--)
    {
        g<<sir[i]<<" ";
    }
    return 0;
}
