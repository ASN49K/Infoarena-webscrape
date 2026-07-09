#include <iostream>
#include <fstream>
#define nm 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[nm],b[nm],c[nm][nm],n,m,d[nm],k;

int main()
{
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;++i)fin>>a[i];
    for(i=1;i<=m;++i)fin>>b[i];
    i=j=1;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])c[i][j]=1+c[i-1][j-1];
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
    i=n;j=m;
    while(i&&j)
    {
        if(a[i]==b[j])d[++k]=a[i],--i,--j;
        else if(c[i-1][j]>c[i][j-1])--i;
             else --j;
    }
    fout<<k<<"\n";
    for(i=k;i;--i)fout<<d[i]<<" ";
}
