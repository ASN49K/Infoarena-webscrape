#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,a[1050][1050],b[1050],c[1050],sol[2005];
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
    {
        in>>b[i];
    }
    for(int i=1;i<=m;i++)
    {
        in>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[i]==c[j])a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    }
    out<<a[n][m]<<'\n';
    int x=n,y=m,ind=0;
    while(a[x][y]!=0)
    {
        if(b[x]==c[y])sol[++ind]=b[x],x--,y--;
        else if(a[x-1][y]>a[x][y-1])x--;
        else y--;
    }
    for(int i=ind;i>0;i--)
    {
        out<<sol[i]<<' ';
    }
    return 0;
}
