#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1026],b[1026],m,n,s,k;
int c[1026][1026],sol[1026];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)f>>a[i];
    for(int i=1;i<=m;++i)f>>b[i];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i]==b[j])c[i][j]=1+c[i-1][j-1];
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    /*for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)cout<<c[i][j]<<' ';
        cout<<'\n';
    }*/
    s=c[n][m];
    for(int i=n,j=m;i>0&&j>0;)
    {
        if(a[i]==b[j]){sol[++k]=a[i];--i;--j;}
        else if(c[i-1][j]<c[i][j-1])--j;
        else --i;
    }
    g<<s<<'\n';
    for(int i=s;i>0;--i)g<<sol[i]<<' ';
}
