#include <iostream>
#include <fstream>
using namespace std;
int a[1025],b[1025],mat[1025][1025],i,j,n,m,maxx,sir[1025];
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>a[i];
    for(i=1;i<=m;i++) fin>>b[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j]) mat[i][j]=mat[i-1][j-1]+1;
        else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    }
    maxx=mat[n][m];
    fout<<maxx<<'\n';
    for(i=n,j=m;i;)
    {
        if(a[i]==b[j])
           sir[maxx--]=a[i],i--,j--;
        else if(mat[i-1][j]>mat[i][j-1])
            i--;
        else j--;
    }
    for(i=1;i<=mat[n][m];i++)
        fout<<sir[i]<<" ";
    return 0;
}
