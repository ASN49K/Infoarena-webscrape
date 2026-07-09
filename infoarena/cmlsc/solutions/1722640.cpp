#include<iostream>
#include<fstream>
#define DX 1100
using namespace std;
fstream fin("cmlsc.in",ios::in),fout("cmlsc.out",ios::out);
int x[DX],y[DX],r[DX];
int bst[DX][DX];
int main()
{
    int n,m,i,j,raspuns;
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
    raspuns=bst[n][m];
    for(i=n;i>=1;i--)
    {
        for(j=m;j>=1;j--)
        {
            if(x[i]==y[j] && bst[i-1][j-1]==raspuns-1)
            {
                r[raspuns]=x[i];
                raspuns--;
                break;
            }
        }
    }
    fout<<bst[n][m]<<"\n";
    for(i=1;i<=bst[n][m];i++)
    {
        fout<<r[i]<<" ";
    }
}

