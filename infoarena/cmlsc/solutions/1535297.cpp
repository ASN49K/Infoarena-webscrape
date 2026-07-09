#include <iostream>
#include <fstream>
using namespace std;
int n,m,a[1025],b[1025],c[1025][1025],j;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
void afis(int x,int y)
{
    if(x&&y)
    {
        if(a[x]==b[y])
        {
            afis(x-1,y-1);
            g<<a[x]<<" ";
        }
        else
            if(c[x-1][y]>c[x][y-1]) afis(x-1,y);
            else afis(x,y-1);
    }
}
int main()
{
    f>>m>>n;
    for(int i=1;i<=m;i++)
        f>>a[i];
    for(int i=1;i<=n;i++)
        f>>b[i];
    for(int i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<c[m][n]<<'\n';
    afis(m,n);
    return 0;
}
