#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream reader ("cmlsc.in");
    ofstream writer ("cmlsc.out");
    int n,m;
    reader>>n>>m;
    int dim;
    if(n>m) dim=n;
    else dim=m;
    int a[dim],b[dim];
    int mat[dim][dim];
    int sir[dim];
    for(int i=0;i<dim;++i)
        for(int j=0;j<dim;++j)
        {
            a[j]=0;
            b[j]=0;
            mat[i][j]=0;
            sir[j]=0;
        }
    for(int i=1;i<=n;++i)
    {
        reader>>a[i];
    }
    for(int i=1;i<=m;++i)
        reader>>b[i];
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
        {
            if(a[i]==b[j])
            {
                mat[i][j]=1+mat[i-1][j-1];
            }
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    int i=n;
    int cnt=0;
    int j=m;
    while(i)
    {
        if(a[i]==b[j])
        {
            sir[++cnt]=a[i];
            i--;
            j--;
        }
        else if(mat[i-1][j]<mat[i][j-1])
            j--;
        else
            i--;
    }
    writer<<cnt<<'\n';
    while(cnt)
    {
        writer<<sir[cnt]<<" ";
        cnt--;
    }
    return 0;
}