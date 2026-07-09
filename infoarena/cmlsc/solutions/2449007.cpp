#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
unsigned a[1025][1025];
int main()
{
    unsigned v1[1025],v2[1025],v3[1025],m,n,k=0;
    fin>>m>>n;
    for(unsigned i=1;i<=m;i++)fin>>v1[i];
    for(unsigned i=1;i<=n;i++)fin>>v2[i];
    if(v1[m]==v2[n]){
    a[n][m]=1;
    v3[++k]=v1[m];}
    for(unsigned i=m-1;i>=1;i--)
        if(v1[i]==v2[n]){a[n][i]=a[n][i+1]+1;v3[++k]=v2[n];}
        else
        a[n][i]=a[n][i+1];
    for(unsigned i=n-1;i>=1;i--)
        if(v2[i]==v1[m]){a[i][m]=1+a[i+1][m];v3[++k]=v1[m];}
        else
        a[i][m]=a[i+1][m];

    for(int i=n-1;i>=1;i--)
        for(int j=m-1;j>=1;j--)
            if(v1[j]==v2[i])a[i][j]=1+a[i+1][j+1],v3[++k]=v1[j];
            else {
                if(a[i+1][j]>a[i][j+1])a[i][j]=a[i+1][j];
                else a[i][j]=a[i][j+1];
            }

    fout<<a[1][1]<<'\n';
    for(int i=k;i>=1;i--)fout<<v3[i]<<' ';
    return 0;
}
