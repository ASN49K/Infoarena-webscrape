#include <iostream>
#include<fstream>
#define mx 1025
using namespace std;
fstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[mx], b[mx],d[mx][mx],c[mx],n,m,nr;
int main()
{
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            if(a[i]==b[j])
            d[i][j]=1+d[i-1][j-1];
        else
            d[i][j]=max(d[i-1][j], d[i][j-1]);
    fout<<d[n][m]<<'\n';
    i=n; j=m;
    while(i!=0 && j!=0)
    {
        if(a[i]==b[j])
        {
            c[++nr]=a[i];
            --i; --j;
        }
        else if (d[i-1][j]>d[i][j-1]) --i;
        else --j;
    }
        for(i=nr;i>=1;i--)
            fout<<c[i]<<" ";
        fin.close();
        fout.close();
    return 0;
}
