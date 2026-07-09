#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v[1030][1030],a[1030],b[1030],t[1030],k;
void sir(int x,int y)
{
    if(x>=1 && y>=1)
    {
        if(a[x]==b[y])
        {
            k++;
            t[k]=a[x];
            sir(x-1,y-1);
        }
        else
        {
            if(v[x-1][y]>v[x][y-1])
            {
                sir(x-1,y);
            }
            else
            {
                sir(x,y-1);
            }
        }
    }
}
int main()
{
    int n,m,i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>a[i];
    }
    for(j=1;j<=m;j++)
    {
        f>>b[j];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                v[i][j]=v[i-1][j-1]+1;
            }
            else
            {
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
    }
    g<<v[n][m]<<"\n";
    sir(n,m);
    for(i=k;i>=1;i--)
        g<<t[i]<<" ";
    return 0;
}
