#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m,n,a[1030],b[1030],d[1030][1030];
void sir(int x,int y)
{
    int i,j;
    if(a[x]==b[y] && x>=1 && y>=1)
        {
            sir(x-1,y-1);
            g<<a[x]<<" ";
        }
    else
    {
        if(d[x][y]==d[x-1][y] && x>=1 && y>=1)
            sir(x-1,y);
        else
            if(d[x][y]==d[x][y-1] && x>=1 && y>=1)
                sir(x,y-1);
    }
}
int main()
{
    int i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
        {
            f>>a[i];
        }
    for(i=1;i<=m;i++)
        {
            f>>b[i];
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    g<<d[n][m]<<"\n";
    sir(n,m);
    }
