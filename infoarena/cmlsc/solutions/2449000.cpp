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
    v3[++k]=v1[m];
    for(unsigned i=1;i<=m;i++)a[n][i]=1;
    for(unsigned i=1;i<=n;i++)a[i][m]=1;
    }
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
