#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int d[1025][1025], a[1025], b[1025],n,m,c[1025],v;

int main()
{
    int i,j;
    ifstream f ("cmlsc.in");
    ofstream g ("cmlsc.out");
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>a[i];
    for (j=1;j<=m;j++)
        f>>b[j];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
            if (a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    g<<d[n][m]<<'\n';
    i=n;
    j=m;
    while (i>0 && j>0)
    {
    if (d[i][j]==d[i-1][j-1]+1 && a[i]==b[j])
    {
        v++;
        c[v]=a[i];
        i--;
        j--;
    }
    else
    {
        if (d[i][j]==d[i-1][j])
        {
            i--;
        }
        else
            j--;
    }
    }
    for (i=v;i>=1;i--)
    g<<c[i]<<" ";
    return 0;
}
