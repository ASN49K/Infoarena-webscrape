#include<iostream>
#include<fstream>
#define DX 1100
using namespace std;
fstream fin("cmlsc.in",ios::in),fout("cmlsc.out",ios::out);
int x[DX],y[DX];
int bst[DX][DX];
int main()
{
    int n,m,i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>x[i];
    for(i=1;i<=m;i++) fin>>y[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j]) bst[i][j]=bst[i-1][j-1]+1;
            bst[i][j]=max(bst[i][j],max(bst[i][j-1],max(bst[i-1][j],bst[i-1][j-1])));
        }
    }
    fout<<bst[n][m];
}

