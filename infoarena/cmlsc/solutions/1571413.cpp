#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int maxi(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int x[100],y[100],a[100][100],b[100];

int main()
{
    int n,m,i,j,nr=1;
    f>>n>>m;

    for(i=1;i<=n;i++)
        f>>x[i];
    for(j=1;j<=m;j++)
        f>>y[j];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(x[i]==y[j])
            a[i][j]=a[i-1][j-1]+1;
        else
        a[i][j]=maxi(a[i-1][j],a[i][j-1]);

    }
    i=n;
    j=m;
    while(a[i][j]!=0)
    {
        if(x[i]==y[j])
        {
            b[nr]=x[i];
            nr++;
            i--;
            j--;
        }
        else
        {
            if(a[i][j]==a[i-1][j])
            i--;
            else
            j--;
        }
    }
    g<<nr-1;
    g<<'\n';
    for(i=nr-1;i>=1;i--)
        g<<b[i]<<' ';
    return 0;
}
