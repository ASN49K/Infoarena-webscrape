#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int m,n,x,a[1030][1030],j=0,maxim,lin,col,b[1025],ind,c[1025],d[1025];
void bacK(int i,int j,int ma)
{
    while(a[i-1][j]==ma)
    {
        i--;
    }
    while(a[i][j-1]==ma)
    {
        j--;
    }
    if(c[i]==d[j])
    {
        ind++;
        b[ind]=c[i];
        if(ma>1)
        bacK(i,j,ma-1);
    }

}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
    {
        in>>c[i];
    }
    for(int i=1;i<=m;i++)
    {
        in>>d[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(d[j]==c[i])a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
            if(maxim<a[i][j])
            {
                maxim=a[i][j];
                lin=i;col=j;
            }
        }
    }
    bacK(lin,col,maxim);
    out<<ind<<'\n';
    for(int i=ind;i>=1;--i)
    {
        out<<b[i]<<' ';
    }
    return 0;
}
