#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int c[1100][1100],a[1030],b[1030],x,y,m,n,i,j,h,d[1030];
int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(j=1; j<=m; j++)
        f>>b[j];
    c[1][0]=0;
    for(j=1; j<=m; j++)
      c[1][j]=(a[1]==b[j]? 1 :c[1][j-1]);

    c[0][1]=0;
    for(i=1; i<=n; i++)
      c[i][1]=(b[1]==a[i]? 1: c[i-1][1]);

    for(i=2; i<=n; i++)
        for(j=2; j<=m; j++)
            if(a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<c[n][m]<<" ";
    x=n;
    y=m;
    h=0;
    while(x>0 && y>0)
    {
        if(a[x]==b[y])
        {
            d[++h]=a[x];
            x--;
            y--;
        }
        if(c[x-1][y]>c[x][y-1])
            x--;
        else
            y--;
    }

    for(i=h;i>=1;i--)
    g<<d[i]<<" ";
    return 0;
}
