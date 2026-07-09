#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025][1025],b[1025],c[1025];
int n,m,i,j;
int sol[1025],f;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)fin>>b[i];
    for(i=1;i<=m;i++)fin>>c[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(b[i]==c[j])a[i][j]=a[i-1][j-1]+1;
        else a[i][j]=max(a[i-1][j],a[i][j-1]);
    }
    fout<<a[n][m]<<"\n";
    i=n;
    j=m;
    while(i)
    {
        if(b[i]==c[j])sol[++f]=b[i],i--,j--;
        else
        if(a[i-1][j]<a[i][j-1])j--;
        else i--;
    }
    for(i=f;i>=1;i--)fout<<sol[i]<<" ";
    return 0;
}

